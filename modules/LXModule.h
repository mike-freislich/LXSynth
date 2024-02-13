#pragma once
#include "CollectionLiteItem.h"
#include "ModKeys.h"
#include "LXParameterList.h"
#include "AUMapping.h"

// const uint8_t waves[] PROGMEM = {
//     WAVEFORM_SINE,
//     WAVEFORM_TRIANGLE,
//     WAVEFORM_SAWTOOTH,
//     WAVEFORM_SQUARE,
//     WAVEFORM_PULSE,
//     WAVEFORM_SAMPLE_HOLD,
//     WAVEFORM_BANDLIMIT_PULSE,
//     WAVEFORM_BANDLIMIT_SAWTOOTH,
//     WAVEFORM_BANDLIMIT_SAWTOOTH_REVERSE,
//     WAVEFORM_BANDLIMIT_SQUARE,
//     WAVEFORM_TRIANGLE_VARIABLE,
//     WAVEFORM_ARBITRARY};

class LXModule : public CollectionLiteItem<ModKeys>
{
public:
    LXModule(ModKeys key) : CollectionLiteItem(key) {}

    virtual ItemType getType() override { return ItemType::TLXModule; }

    template <typename ModuleType>
    ModuleType *attachParameters(const std::vector<ParmKeys> &parmKeys)
    {
        _parameters.clear();
        for (auto pkey : parmKeys)
        {
            //printf("Module: %s -> Parameter : %s\n", this->typeName(), parmKey_cstr(pkey));
            _parameters.push_back(Parameters[pkey]);
        }
        afterAttachParameters();
        return (ModuleType *)this;
    }

    virtual void afterAttachParameters() {}

    FLASHMEM LXModule *attachAudioUnits(const std::vector<AudioStream *> &audioUnits)
    {
        _audioUnits = audioUnits;
        return this;
    }

    FLASHMEM LXParameter *findParameter(ParmKeys key)
    {
        for (auto &p : _parameters)
        {
            if (p->key == key)
                return p;
        }
        return nullptr; // not found
    }

protected:
    std::vector<LXParameter *> _parameters;
    std::vector<AudioStream *> _audioUnits;
};

