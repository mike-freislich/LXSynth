#pragma once
#include "LXModule.h"

class LXOscillator : public LXModule
{
public:
    LXOscillator(ModKeys key) : LXModule(key) {}
    ItemType getType() override { return ItemType::TLXOscillator; }

    void afterAttachParameters() override
    {
        _amp = _parameters[0];
        _detune = _parameters[1];
        _freq = _parameters[2];
        _shape = _parameters[3];
    }

    void update() override
    {
        LXModule::update();
        if (_shape->changed(true))
        {
            _amp->changed(true);
            _detune->changed(true);
            _freq->changed(true);
            LOG("Shape Changed: " << _shape->getValue());
            for (auto au : _audioUnits)
            {
                AudioSynthWaveformModulated *wave = static_cast<AudioSynthWaveformModulated *>(au);                
                wave->begin( // TODO may require audio interrupts to halt for this
                    _amp->getValue(), _freq->getValue() + _detune->getValue(),
                    waves[(uint8_t)_shape->getValue()]);
            }
        }
        else
        {
            if (_detune->changed(true) || _freq->changed(true))
            {
                float freq = _freq->getValue() + _detune->getValue();
                LOG("Frequency Changed : " << _freq->getValue() << " with detune " << _detune->getValue());

                for (auto au : _audioUnits)
                {
                    AudioSynthWaveformModulated *wave = static_cast<AudioSynthWaveformModulated *>(au);
                    wave->frequency(freq);
                }
            }
            if (_amp->changed(true))
            {
                LOG("Amplitude Changed : " << _amp->getValue());
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

private:
    LXParameter *_amp, *_detune, *_freq, *_shape;
};