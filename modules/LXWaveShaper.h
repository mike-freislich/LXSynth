#pragma once
#include "LXModule.h"

class LXWaveShaper : public LXModule
{
public:
    LXWaveShaper(ModKeys key) : LXModule(key)
    {
        _bypass = Parameters[shaper_bypass];
        _curve = Parameters[shaper_curve];
        _pregain = Parameters[shaper_pregain];
        _shapers = {&auSHAPER_V1, &auSHAPER_V2, &auSHAPER_V3, &auSHAPER_V4};
        _amps = {&auAMP_SHAPER_PREAMP_V1, &auAMP_SHAPER_PREAMP_V2, &auAMP_SHAPER_PREAMP_V3, &auAMP_SHAPER_PREAMP_V4};
        _mixers = {&auMIXER_SHAPER_BYPASS_V1, &auMIXER_SHAPER_BYPASS_V2, &auMIXER_SHAPER_BYPASS_V3, &auMIXER_SHAPER_BYPASS_V4};
    }
    ItemType getType() override { return ItemType::TLXWaveShaper; }

    void update() override
    {
        LXModule::update();
        if (_curve->changed(true))
            for (auto shaper : _shapers)
            {
                uint8_t curveIndex = clampf<uint8_t>(_curve->getValue(), 0, 29);
                int dataLen = (curveIndex == 0) ? 3 : 257;
                shaper->shape(WST[curveIndex], dataLen);
            }
        
        if (_pregain->changed(true))
            for (auto amp : _amps)
                amp->gain(_pregain->getValue());

        if (_bypass->changed(true))
        {
            float bypass = _bypass->getValue();
            for (auto mixer : _mixers)
            {
                if (bypass)
                {
                    mixer->gain(bypassThru, 1);
                    mixer->gain(bypassShaped, 0);
                }
                else
                {
                    mixer->gain(bypassThru, 0);
                    mixer->gain(bypassShaped, 1);
                }
            }
        }
    }

private:
    enum BypassChannels
    {
        bypassThru = 0,
        bypassShaped = 1
    };
    LXParameter *_bypass, *_curve, *_pregain;
    std::vector<AudioEffectWaveshaper *> _shapers;
    std::vector<AudioAmplifier *> _amps;
    std::vector<AudioMixer4 *> _mixers;
};