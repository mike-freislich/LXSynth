#pragma once
#include "LXModule.h"

class LXPartMixer : public LXModule
{
public:
    LXPartMixer(ModKeys key) : LXModule(key)
    {
        _partPan = Parameters[ParmKeys::partpan_ab];
        attachAudioUnits({&auMIXER_PRESHAPE_V1, &auMIXER_PRESHAPE_V2, &auMIXER_PRESHAPE_V3, &auMIXER_PRESHAPE_V4});
    }
    virtual  const ItemType getType() override { return ItemType::TLXPartMixer; }

     void update() override
    {
        LXModule::update();
        if (_partPan->changed(true))
        {
            float pan = _partPan->getValue();
            for (auto m : _audioUnits)
            {
                AudioMixer4 *mixer = static_cast<AudioMixer4 *>(m);
                float a, b;
                a = 1 - pan;
                b = 1 - a;
                mixer->gain(0, a);
                mixer->gain(1, b);
            }
        }
    }

    

private:
    LXParameter *_partPan;
};