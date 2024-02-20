#pragma once
#include "CollectionLiteItem.h"
#include "ContKeys.h"
#include "LXParameter.h"
#include "timing.h"
#include "AnalogMux.h"
#include "DigitalIO.h"
#include "ControllerPins.h"

#define ANALOG_READ_BITS 10
#define POT_AVERAGE_SAMPLING 32

//static bool called = false;

class LXController : public CollectionLiteItem<ContKeys>
{
public:
    LXController(ContKeys key) : CollectionLiteItem(key)
    {
        LXController::callOnce();
        _debounceTimer.start();
    }
    virtual ItemType getType() override { return ItemType::TLXController; }

    template <typename ControllerType>
    ControllerType *attachParameters(const std::vector<ParmKeys> &parmKeys)
    {
        _parameters.clear();
        for (auto pkey : parmKeys)
        {
            Serial.printf("Controller: %s -> Parameter : %s\n", this->typeName(), parmKey_cstr(pkey));
            _parameters.push_back(Parameters[pkey]);
        }
        // afterAttachParameters();
        return (ControllerType *)this;
    }

    // virtual void afterAttachParameters() {}
    virtual void update() override
    {
        if (checkDebounce())
            updateController();
    }
    virtual void updateController()
    {
        int v = readValue();
        for (auto p : _parameters)
            p->setValue(mapToParameterValue(p, v));
    }

    template <typename T>
    T *setup(uint16_t pin, uint32_t debounceMS, int rangeMin, int rangeMax)
    {
        debounceMs(debounceMS);
        setPin(pin);
        setRange(rangeMin, rangeMax);
        return static_cast<T *>(this);
    }

    LXController *debounceMs(uint32_t durationMs)
    {
        _debounceTimer.duration(durationMs);
        return this;
    }

    void setPin(uint16_t pin) { _pin = pin; }

    void setRange(int min, int max)
    {
        _min = min;
        _max = max;
    }

    static void callOnce()
    {
        static bool called = false;
        if (!called)
        {
            analogReadResolution(ANALOG_READ_BITS);
            analogReadAveraging(POT_AVERAGE_SAMPLING);
            LOG("SETTING ANALOG READ AVERAGING AND RESOLUTION");
            called = true;
        }
    }

protected:
    std::vector<LXParameter *> _parameters;
    int _min = 0, _max = 1;
    uint16_t _pin = 0;

    /**
     * @brief
     * checks if the debounce duration has completed;
     * @return true
     * @return false
     */
    bool checkDebounce() { return _debounceTimer.update(); }

    float mapToParameterValue(LXParameter *p, int controllerValue)
    {
        float pmin = 0, pmax = 0;
        p->getRange(pmin, pmax);
        float v = map((float)controllerValue, (float)_min, (float)_max, pmin, pmax);
        return v;
    }

    virtual int readValue()
    {
        // TODO get the value from the controller
        return rand() % (_max - _min) + _min;
    }

private:
    SimpleTimer _debounceTimer;
};
