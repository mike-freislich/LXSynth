#pragma once
#ifdef BUILD_FOR_TEENSY
#include <Audio.h>
#endif
#include "init.h"

class LXSynth
{
public:
    LXSynth()
    {
        initParameters();
        initModules();
        initControllers(); // testing git
    }

    void update()
    {
        Controllers.update();
        Modules.update();
    }

};