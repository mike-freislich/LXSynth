#pragma once
#include "CollectionLiteItem.h"
#include "ModKeys.h"
#include "LXParameterList.h"
#include "AUMapping.h"
#include "waves.h"
#include "waveshaperTables.h"

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

