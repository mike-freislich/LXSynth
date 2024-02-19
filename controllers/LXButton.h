#pragma once
#include "LXController.h"

class LXButton : public LXController
{
public:
    LXButton(ContKeys key) : LXController(key) { setup<LXButton>(0, 1000, 0, 1); }
    ItemType getType() override { return ItemType::TLXButton; }

private:
    int readValue() override
    {                    
        return LXController::readValue();        
        //return analogRead(_pin);
    }
};