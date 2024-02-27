#pragma once
#include "LXModule.h"

class LXOscillator : public LXModule
{
public:
    LXOscillator(ModKeys key) : LXModule(key) {}
    virtual const ItemType getType() override { return ItemType::TLXOscillator; }

    void afterAttachParameters() override
    {
        _amp = _parameters[0];
        _detune = _parameters[1];
        _freq = _parameters[2];
        _shape = _parameters[3];
        _pwm_octaves = _parameters[4];
    }

    void update() override
    {
        LXModule::update();
        if (_shape->changed(true))
        {
            _amp->changed(true);
            _detune->changed(true);
            _freq->changed(true);
            
            int index = 0;
            for (auto au : _audioUnits)
            {                
                AudioSynthWaveformModulated *wave = static_cast<AudioSynthWaveformModulated *>(au);
                AudioNoInterrupts();
                wave->begin(
                    _amp->getValue(), _freq->getValue() + _detune->getValue() * index,
                    waves[(uint8_t)_shape->getValue()]);
                AudioInterrupts();
                printf("Osc %s Wave : shape(%d), amp(%d), freq(%d)\n", 
                    modKey_cstr(key), waves[(uint8_t)_shape->getValue()], (uint8_t)(_amp->getValue()*100), (uint16_t)_freq->getValue());
                
                index ++;
            }
        }
        else
        {
            if (_detune->changed(true) || _freq->changed(true))
            {
                float freq = _freq->getValue(); // * _detune->getValue();
                // LOG("Frequency Changed : " << _freq->getValue() << " with detune " << _detune->getValue());
                for (auto au : _audioUnits)
                {
                    AudioSynthWaveformModulated *wave = static_cast<AudioSynthWaveformModulated *>(au);
                    wave->frequency(freq);
                }
            }
            if (_amp->changed(true))
            {
                // LOG("Amplitude Changed : " << _amp->getValue());
                for (auto au : _audioUnits)
                {
                    AudioSynthWaveformModulated *wave = static_cast<AudioSynthWaveformModulated *>(au);
                    wave->amplitude(_amp->getValue());
                }
            }
        }
    }

    void begin()
    {

        for (auto au : _audioUnits)
        {
            AudioSynthWaveformModulated *wave = static_cast<AudioSynthWaveformModulated *>(au);
            wave->begin(_amp->getValue(), _freq->getValue(), _shape->getValue());
        }
    }

    void amplitude(float gain) { _amp->setValue(gain); }
    void detune(float amount) { _detune->setValue(amount); }
    void frequency(float freq) { _freq->setValue(freq); }
    void shape(float shape) { _shape->setValue(shape); }

    float getAmplitude() { return _amp->getValue(); }
    float getDetune() { return _detune->getValue(); }
    float getFrequency() { return _freq->getValue(); }
    float getShape() { return _shape->getValue(); }

private:
    LXParameter *_amp, *_detune, *_freq, *_shape, *_pwm_octaves;
};