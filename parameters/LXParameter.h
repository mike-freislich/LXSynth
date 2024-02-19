#pragma once
#include "CollectionLiteItem.h"

class LXParameter : public CollectionLiteItem<ParmKeys>
{
public:
    LXParameter(ParmKeys key) : CollectionLiteItem(key) {}
    ItemType getType() override { return ItemType::TLXParameter; }

    LXParameter *setValue(float v)
    {
        v = clampf(v, min_, max_);

        if (v != value_)
        {
            changed_ = true;
            LOG("[PARAMETER][" << parmKey_cstr(key) << "] changed to value : " << value_);
            value_ = v;
        }

        return this;
    }

    LXParameter *setValue(float v, float originMin, float originMax)
    {
        setValue(map(v, originMin, originMax, min_, max_));
        return this;
    }

    float getValue() { return value_; }

    LXParameter *setRange(float minValue, float maxValue)
    {
        min_ = minValue;
        max_ = maxValue;
        value_ = clampf(value_, min_, max_);
        return this;
    }
    void getRange(float &minValue, float &maxValue)
    {
        minValue = min_;
        maxValue = max_;
    }

    float getMin() { return min_; }
    float getMax() { return max_; }

    bool changed(bool clearFlag)
    {
        bool result = changed_;

        if (clearFlag)
            changed_ = false;

        return result;
    }

    void update() override { Serial.printf("updating %s\n", ItemTypeToName(getType())); }

private:
    float value_ = 0, min_ = 0, max_ = 0;
    bool changed_;
};