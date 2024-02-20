#pragma once
#include "LXController.h"

#define POT_RESOLUTION 4

class LXPotentiometer : public LXController
{
public:
    LXPotentiometer(ContKeys key) : LXController(key) { setup<LXPotentiometer>(0, 5, 10, 1010); }
    ItemType getType() override { return ItemType::TLXPotentiometer; }

    void updateController() override
    {
        int v = readValue();
        if (v >= _lastValue + POT_RESOLUTION || v <= _lastValue - POT_RESOLUTION)
        {
            _lastValue = v;
            LOG("[POT] " << key << ", pin(" << _pin << ") change value to: " << v);
            for (auto p : _parameters)
                p->setValue(mapToParameterValue(p, v));           
        }        
    }

private:
    int _lastValue = 0;

    int readValue() override
    {
        return clampf<int>((int)analogMux.analogReadIO(_pin), _min, _max);
    }
};