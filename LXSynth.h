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
        initControllers();
    }

    void update()
    {
        Controllers.update();
        Modules.update();
    }

};