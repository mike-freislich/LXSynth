#pragma once
#include "CollectionLite.h"
#include "LXView.h"
#include "ViewKeys.h"
#include "timing.h"

#define REFRESHRATE_HZ 60

class LXViewList : public CollectionLite<LXView, ViewKeys>
{
public:
    LXViewList() : CollectionLite()
    {
        refreshTimer.start(1000 / REFRESHRATE_HZ);
    }

     void update() override
    {
        if (refreshTimer.update())
        {
            CollectionLite::update();
        }
    }

protected:
    SimpleTimer refreshTimer;
} Views;