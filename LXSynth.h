#pragma once
#ifdef BUILD_FOR_TEENSY
#include <Audio.h>
#endif
#include "init.h"

#define VOICES 4

class LXSynth
{
public:
    enum PolyMode
    {
        Polyphonic,
        Unison
    };
    LXSynth()
    {
        initParameters();
        initModules();
        initControllers();

        _envModulators = {
            Modules.module<LXEnvModulatorBank>(TLXModulatorBank, AEnvModulator),
            Modules.module<LXEnvModulatorBank>(TLXModulatorBank, PEnvModulator),
            Modules.module<LXEnvModulatorBank>(TLXModulatorBank, FEnvModulator)};
    }

    void update()
    {
        Controllers.update();
        Modules.update();
    }

    void noteOn()
    {
        if (_polyMode == Unison)
            for (auto &mod : _envModulators)
                mod->noteOn();
        else
        {
            _polyLastVoice = (_polyLastVoice + 1) % VOICES;
            for (auto &mod : _envModulators)
                mod->noteOn(_polyLastVoice);
        }
    }

    void noteOff()
    {
         if (_polyMode == Unison)
            for (auto &mod : _envModulators)
                mod->noteOff();
        else
        {
            //TODO POLYPHONIC need a way of keeping track which note was lifted and therefore which voice to release            
            for (auto &mod : _envModulators)
                mod->noteOff(_polyLastVoice);
        }
    }

    void setPolyMode(PolyMode poly) { _polyMode = poly; }

private:
    PolyMode _polyMode = PolyMode::Unison;
    uint8_t _polyLastVoice = 0;
    std::vector<LXEnvModulatorBank *> _envModulators;
};