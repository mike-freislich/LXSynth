#pragma once
#include "LXModule.h"

class LXPulseWidthMod : public LXModule
{
public:
    LXPulseWidthMod(ModKeys key) : LXModule(key) {}

    virtual const ItemType getType() override { return ItemType::TLXPulseWidthMod; }

    LXPulseWidthMod *attachPWMWave(AudioSynthWaveform *wave)
    {
        _wave = wave;
        return this;
    }

    LXPulseWidthMod *attachAmp(AudioAmplifier *amp)
    {
        _amp = amp;
        return this;
    }

    LXPulseWidthMod *begin()
    {
        _wave->begin(_parameters[gain]->getValue(),
                     _parameters[freq]->getValue(),
                     _parameters[shape]->getValue());      
        return this;          
    }

    void update() override
    {        
        LXModule::update();
        if (_parameters[shape]->changed(true))
        {
            _parameters[gain]->changed(true);
            _parameters[freq]->changed(true);
            _wave->begin(
                1.0, //_parameters[gain]->getValue(),
                _parameters[freq]->getValue(),
                (short)_parameters[shape]->getValue());
        }
        else
        {
            if (_parameters[gain]->changed(true))
            {
                printf("[PWM] %s gain(%d)\n", modKey_cstr(key), (int)_parameters[freq]->getValue());
                _amp->gain(_parameters[gain]->getValue());
            }

            if (_parameters[freq]->changed(true))
            {
                printf("[PWM] %s freq(%d)\n", modKey_cstr(key), (int)_parameters[freq]->getValue());
                _wave->frequency(_parameters[freq]->getValue());
            }
        }
    }

private:
    enum PWMParamIndex
    {
        freq,
        gain,
        shape
    };
    AudioSynthWaveform *_wave;
    AudioAmplifier *_amp;
};