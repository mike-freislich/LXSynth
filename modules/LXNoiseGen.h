#pragma once
#include "LXModule.h"

class LXNoiseGen : public LXModule
{
public:
    LXNoiseGen(ModKeys key) : LXModule(key)
    {
        _noiseType = Parameters[noise_type];
        _noiseLevel = Parameters[noise_level];
    }
    ItemType getType() override { return ItemType::TLXNoiseGen; }

    void update() override
    {
        if (_noiseType->changed(true) || _noiseLevel->changed(true))
        {
            uint8_t t = _noiseType->getValue();
            float level = _noiseLevel->getValue();
            if (t == NOISE_WHITE)
            {
                auMIXER_NOISE.gain(NOISE_WHITE, level);
                auMIXER_NOISE.gain(NOISE_PINK, 0);
            }
            else // pink noise
            {
                auMIXER_NOISE.gain(NOISE_WHITE, 0);
                auMIXER_NOISE.gain(NOISE_PINK, level);
            }
        }
    }

private:
    enum NoiseType
    {
        NOISE_WHITE,
        NOISE_PINK
    };
    LXParameter *_noiseType, *_noiseLevel;
};