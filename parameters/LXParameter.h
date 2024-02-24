#pragma once
#include "CollectionLiteItem.h"

float convertToAudio(float linearValue, float linearMin, float linearMax, float audioMin = 0, float audioMax = 0, float exponent = 2.0f)
{
    if (audioMax == audioMin)
    {
        audioMax = linearMax;
        audioMin = linearMin;
    }
    linearValue = clampf(linearValue, linearMin, linearMax);
    float audioValue = audioMin + (audioMax - audioMin) * pow((linearValue - linearMin) / (linearMax - linearMin), exponent);

    return audioValue;    
}

enum ParameterCurve
{
    CURVE_LINEAR,
    CURVE_AUDIO
};

class LXParameter : public CollectionLiteItem<ParmKeys>
{
public:
    LXParameter(ParmKeys key) : CollectionLiteItem(key) {}
    const ItemType getType() override { return ItemType::TLXParameter; }

    LXParameter *curve(const ParameterCurve &curve)
    {
        _curve = curve;
        return this;
    }

    LXParameter *setValue(float v)
    {
        v = clampf(v, min_, max_);

        if (_firstSetting || v != value_)
        {
            _firstSetting = false;
            changed_ = true;
            LOG(F("[PARAMETER][") << parmKey_cstr(key) << F("] changed to value : ") << value_);
            value_ = v;
        }

        return this;
    }

     LXParameter *setValue(float v, float originMin, float originMax)
    {
        setValue(map(v, originMin, originMax, min_, max_));
        return this;
    }

     float getValue()
    {
        float v = value_;

        if (_curve == ParameterCurve::CURVE_AUDIO)
            v = convertToAudio(value_, min_, max_, min_, max_);
        
        return _inverted ? max_ - v : v;
    }

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
    bool changed_ = false, _firstSetting = true, _inverted = false;    
    ParameterCurve _curve = CURVE_LINEAR;    
};