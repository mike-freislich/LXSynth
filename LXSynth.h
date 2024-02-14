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
            Modules.module<LXEnvModulatorBank>(TLXEnvModulatorBank, AEnvModulator),
            Modules.module<LXEnvModulatorBank>(TLXEnvModulatorBank, PEnvModulator),
            Modules.module<LXEnvModulatorBank>(TLXEnvModulatorBank, FEnvModulator)};
    }

    void update()
    {
        Controllers.update();   // read controller values and set parameters
        Modules.update();       // check parameters per module and change audio unit parameters
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