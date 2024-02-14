#pragma once
#include "LXModule.h"

#define FILTER_TYPE_LOWPASS 0
#define FILTER_TYPE_BANDPASS 1
#define FILTER_TYPE_HIGHPASS 2
#define FILTER_TYPE_LADDER 3

class LXFilterBank : public LXModule
{
public:
    LXFilterBank(ModKeys key) : LXModule(key)
    {
        _filtersLadder = {&auFILTER_LADDER_V1, &auFILTER_LADDER_V2, &auFILTER_LADDER_V3, &auFILTER_LADDER_V4};
        _filtersSV = {&auFILTER_SV_V1, &auFILTER_SV_V2, &auFILTER_SV_V3, &auFILTER_SV_V4};
        _amps = {&auAMP_POST_FILTER_V1, &auAMP_POST_FILTER_V2, &auAMP_POST_FILTER_V3, &auAMP_POST_FILTER_V4};
        _mixers = {&auMIXER_FILTER_BLOCK_V1, &auMIXER_FILTER_BLOCK_V2, &auMIXER_FILTER_BLOCK_V3, &auMIXER_FILTER_BLOCK_V4};

        _filterType = Parameters[filter_type];
        _filterFreq = Parameters[filter_freq];
        _filterRes = Parameters[filter_res];
        _filterOctave = Parameters[filter_octaves];
        _filterPostGain = Parameters[filter_postgain];
    }

    ItemType getType() override { return ItemType::TLXFilterBank; }

    void update() override
    {
        if (_filterType->changed(true))
            filterType(((uint8_t)_filterType->getValue()));

        if (_filterFreq->changed(true))
            frequency(_filterFreq->getValue());

        if (_filterRes->changed(true))
            resonance(_filterRes->getValue());

        if (_filterOctave->changed(true))
            octaves(_filterOctave->getValue());

        if (_filterPostGain->changed(true))
            postGain(_filterPostGain->getValue());
    }

private:
    LXParameter *_filterRes, *_filterFreq, *_filterOctave, *_filterType, *_filterPostGain;
    std::vector<AudioAmplifier *> _amps;
    std::vector<AudioMixer4 *> _mixers;
    std::vector<AudioFilterStateVariable *> _filtersSV;
    std::vector<AudioFilterLadder *> _filtersLadder;

    /**
     * @brief
     * Switches the filter between LP, BP, HP, LADDER
     * @param type = FILTER_TYPE_LOWPASS, FILTER_TYPE_BANDPASS, FILTER_TYPE_HIGHPASS, FILTER_TYPE_LADDER
     */
    void filterType(uint8_t type)
    {
        type = type % 4;
        for (auto mixer : _mixers)
        {
            for (uint8_t channel = 0; channel < 4; channel++)
                mixer->gain(channel, type == channel ? 1.0 : 0.0);
        }
    }

    void frequency(float freq)
    {
        for (auto filter : _filtersLadder)
            filter->frequency(freq);
        for (auto filter : _filtersSV)
            filter->frequency(freq);
    }

    void resonance(float res)
    {
        for (auto filter : _filtersLadder)
            filter->resonance(res);
        for (auto filter : _filtersSV)
            filter->resonance(res);
    }

    void octaves(float oct)
    {
        for (auto filter : _filtersLadder)
            filter->octaveControl(oct);
        for (auto filter : _filtersSV)
            filter->octaveControl(oct);
    }

    void postGain(float gain)
    {
        for (auto amp : _amps)
            amp->gain(gain);
    }
};