#pragma once
#include "LXModule.h"

class LXRingModulation : public LXModule
{
public:
    LXRingModulation(ModKeys key) : LXModule(key)
    {
        _ringFreq = Parameters[ring_freq];
        _ringLevel = Parameters[ring_level];
        _ringShape = Parameters[ring_shape];
    }
    ItemType getType() override { return ItemType::TLXRingModulation; }

    void update() override
    {
        if (_ringShape->changed(true))
        {
            _ringFreq->changed(true);
            _ringLevel->changed(true);
            auWAVE_RINGMOD.begin(_ringLevel->getValue(), _ringFreq->getValue(), _ringShape->getValue());
        }
        else
        {
            if (_ringFreq->changed(true))
                auWAVE_RINGMOD.frequency(_ringFreq->getValue());
            if (_ringLevel->changed(true))
                auWAVE_RINGMOD.amplitude(_ringLevel->getValue());
        }
    }

private:
    LXParameter *_ringFreq, *_ringLevel, *_ringShape;
};