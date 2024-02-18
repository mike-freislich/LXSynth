#pragma once
#include "LXModule.h"
#include "LXEnvModulatorBank.h"
#include "LXFilterBank.h"
#include "LXPulseWidthMod.h"
#include "LXCrossModulation.h"
#include "LXRingModulation.h"
#include "LXNoiseGen.h"
#include "LXPartMixer.h"
#include "LXWaveShaper.h"
#include "LXOscillator.h"
#include "LXVoiceMixer.h"

class LXModuleList : public CollectionLite<LXModule, ModKeys>
{
public:
    template <typename T>
    T *module(ItemType itemType, ModKeys key)
    {        
        if (LXModule *m = this->at(key))
        {            
            if (m->getType() == itemType)
                return static_cast<T *>(m);
        }
        return nullptr;
    }
};

LXModuleList Modules;