#pragma once
#include "CollectionLite.h"
#include "LXController.h"
#include "LXButton.h"
#include "LXPotentiometer.h"
#include "LXRotary.h"
#include "ContKeys.h"

class LXControllerList : public CollectionLite<LXController, ContKeys>
{
public:
    void update() override
    {
        
        //digitalIO.update();        

        // run update on all controllers
        for (auto i : items)
            i->update();
    }

} Controllers;
