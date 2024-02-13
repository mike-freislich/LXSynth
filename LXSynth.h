#pragma once
#include <Audio.h>
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