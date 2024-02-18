#pragma once
#include "LXModule.h"

class LXCrossModulation : public LXModule
{
public:
    LXCrossModulation(ModKeys key) : LXModule(key) { _xmodAmount = Parameters[xmod_amount]; }
    ItemType getType() override { return ItemType::TLXCrossModulation; }

    void update() override
    {        
        LXModule::update();
        if (_xmodAmount->changed(true))
        {
            // pot centre = no xmod.... pot left = apply a -> b ... pot right = apply b -> a
            float pan = _xmodAmount->getValue();
            auDC_XMOD_a.amplitude(pan <= 0.4 ? pan * 2.5 : 0);
            auDC_XMOD_b.amplitude(pan >= 0.6 ? (pan - 0.6) * 2.5 : 0);
        }
    }

private:
    LXParameter *_xmodAmount;
};