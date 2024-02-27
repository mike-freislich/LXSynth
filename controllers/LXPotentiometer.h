#pragma once
#include "LXController.h"

#define POT_RESOLUTION 5

class LXPotentiometer : public LXController
{
public:
    LXPotentiometer(ContKeys key) : LXController(key) { setup<LXPotentiometer>(0, 10, 10 + POT_RESOLUTION, 1010 - POT_RESOLUTION); }
    const ItemType getType() override { return ItemType::TLXPotentiometer; }

    void updateController() override
    {
        int v = readValue();
        if (v >= _lastValue + POT_RESOLUTION || v <= _lastValue - POT_RESOLUTION)
        {
            _lastValue = v;
            // printf("[POT] %s, pin(%d), value(%d)\n", contKey_cstr(key), _pin, v);
            // LOG("[POT] " << key << ", pin(" << _pin << ") change value to: " << v);
            for (auto p : _parameters)
                p->setValue(mapToParameterValue(p, v));
        }
    }

    LXPotentiometer *setPin(uint16_t pin)
    {
        LXController::setPin(pin);
        return this;
    }

    LXPotentiometer *attachParameters(const std::vector<ParmKeys> &parmKeys)
    {
        LXController::attachParameters<LXPotentiometer>(parmKeys);
        return this;
    }

private:
    int _lastValue = 0;

    int readValue() override
    {
        return clampf<int>((int)analogMux.analogReadIO(_pin), _min, _max);
    }
};