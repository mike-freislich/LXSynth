#pragma once
#include "LXModule.h"

class LXEnvModulatorBank : public LXModule
{
public:
    LXEnvModulatorBank(ModKeys key) : LXModule(key) {}
    virtual const ItemType getType() override { return ItemType::TLXEnvModulatorBank; }

    LXEnvModulatorBank *attachEnvelopes(const std::vector<AudioEffectEnvelope *> &envelopes)
    {
        _envelopes = envelopes;
        return this;
    }
    LXEnvModulatorBank *attachAmountDC(AudioSynthWaveformDc *amountDC)
    {
        _amountDC = amountDC;
        return this;
    }
    LXEnvModulatorBank *attachBendDC(AudioSynthWaveformDc *bendDC)
    {
        _bendDC = bendDC;
        return this;
    }
    LXEnvModulatorBank *attachLFOWave(AudioSynthWaveformModulated *lfoWave)
    {
        _lfoWave = lfoWave;
        return this;
    }

    void update() override 
    {

        // Envelope Amount / Invert
        if (_parameters[ModBankParamIndex::amount]->changed(true) || _parameters[ModBankParamIndex::invert]->changed(true))
        {
            printf("setting amount : %d", (int)_parameters[ModBankParamIndex::amount]->getValue());
            // printf("setting env emount DC : [%2.2f]\n", _parameters[amount]->getValue());
            // int8_t inverMultiplier = _parameters[ModBankParamIndex::invert]->getValue() ? -1 : 1;
            _amountDC->amplitude(_parameters[amount]->getValue()); // * (float)inverMultiplier);
        }

        // // Envelope ADHSR
        // if (LXParameter *p = _parameters[ModBankParamIndex::invert])
        //     if (p->changed(true))
        //         _amountDC->amplitude(p->getValue());

        if (_parameters[ModBankParamIndex::attack]->changed(true))
        {
            printf("setting attack : %d", (int)_parameters[ModBankParamIndex::attack]->getValue());
            // printf("setting attack!! [%2.2f]\n", _parameters[ModBankParamIndex::attack]->getValue());
            for (auto e : _envelopes)
                e->attack(_parameters[ModBankParamIndex::attack]->getValue());
        }

        if (_parameters[ModBankParamIndex::decay]->changed(true))
        {
            printf("setting decay : %d", (int)_parameters[ModBankParamIndex::decay]->getValue());
            for (auto e : _envelopes)
                e->decay(_parameters[ModBankParamIndex::decay]->getValue());
        }

        if (_parameters[ModBankParamIndex::hold]->changed(true))
        {
            printf("setting hold : %d", (int)_parameters[ModBankParamIndex::hold]->getValue());
            for (auto e : _envelopes)
                e->hold(_parameters[ModBankParamIndex::hold]->getValue());
        }

        if (_parameters[ModBankParamIndex::sustain]->changed(true))
        {
            printf("setting sustain : %d", (int)_parameters[ModBankParamIndex::sustain]->getValue());
            for (auto e : _envelopes)
                e->sustain(_parameters[ModBankParamIndex::sustain]->getValue());
        }

        if (_parameters[ModBankParamIndex::release]->changed(true))
        {
            printf("setting release : %d", (int)_parameters[ModBankParamIndex::release]->getValue());
            for (auto e : _envelopes)
                e->release(_parameters[ModBankParamIndex::release]->getValue());
        }

        // Bend
        if (_parameters[ModBankParamIndex::bend]->changed(true))
            if (_bendDC) // optional
                _bendDC->amplitude(_parameters[ModBankParamIndex::bend]->getValue());

        // LFO
        if (_parameters[ModBankParamIndex::lfo_shape]->changed(true))
        {
            _parameters[ModBankParamIndex::lfo_amount]->changed(true);
            _parameters[ModBankParamIndex::lfo_freq]->changed(true);
            _lfoWave->begin(
                _parameters[ModBankParamIndex::lfo_amount]->getValue(),
                _parameters[ModBankParamIndex::lfo_freq]->getValue(),
                waves[(uint8_t)_parameters[ModBankParamIndex::lfo_shape]->getValue()]);
        }
        else
        {
            if (_parameters[ModBankParamIndex::lfo_amount]->changed(true))
                _lfoWave->amplitude(_parameters[ModBankParamIndex::lfo_amount]->getValue());
            if (_parameters[lfo_freq]->changed(true))
                _lfoWave->frequency(_parameters[ModBankParamIndex::lfo_freq]->getValue());
        }
    }

    /// @brief Trigger all voice envelopes (unison mode)
    /// @return
    void noteOn() 
    {
        for (auto e : _envelopes)
            e->noteOn();
    }

    /// @brief Trigger a specific voice envelope (polyphonic mode)
    /// @param voiceNum - the voice number 0...3
    /// @return
    void noteOn(uint8_t voiceNum) 
    {
        voiceNum = voiceNum % _envelopes.size();
        _envelopes[voiceNum]->noteOn();
    }

    /// @brief all envelopes start release phase (Polyphonic)
    /// @return
    void noteOff() 
    {
        for (auto e : _envelopes)
            e->noteOff();
    }

    /// @brief specific voice envelope start release phase (Unison)
    /// @param voice - which voice to affect
    void noteOff(uint8_t voice) 
    {
        voice = voice % _envelopes.size();
        _envelopes[voice]->noteOff();
    }

private:
    enum ModBankParamIndex
    {
        attack,
        hold,
        decay,
        sustain,
        release,
        amount,
        invert,
        bend,
        lfo_amount,
        lfo_freq,
        lfo_shape
    };
    std::vector<AudioEffectEnvelope *> _envelopes;
    AudioSynthWaveformDc *_amountDC = nullptr, *_bendDC = nullptr;
    AudioSynthWaveformModulated *_lfoWave = nullptr;
};