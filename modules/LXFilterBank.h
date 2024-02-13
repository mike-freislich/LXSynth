#pragma once
#include "LXModule.h"

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
        // TODO update the AudioUnits
    }

private:
    LXParameter *_filterRes, *_filterFreq, *_filterOctave, *_filterType, *_filterPostGain;
    std::vector<AudioAmplifier *> _amps;
    std::vector<AudioMixer4 *> _mixers;
    std::vector<AudioFilterStateVariable *> _filtersSV;
    std::vector<AudioFilterLadder *> _filtersLadder;
};