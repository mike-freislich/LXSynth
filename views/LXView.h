#pragma once
#include "CollectionLiteItem.h"
#include "ViewKeys.h"

class LXView : public CollectionLiteItem<ViewKeys>
{
public:
    LXView(ViewKeys key) : CollectionLiteItem(key) {}
    ItemType getType() { return ItemType::TLXView; }

    void attachParameters(std::vector<LXParameter *> &parameters)
    {
        _parameters = parameters;
    }

    virtual void update() override
    {
        if (didChange())
            render();
    }

protected:
    std::vector<LXParameter *> _parameters;
    
    bool didChange()
    {
        for (auto p : _parameters)
            if (p->changed(false))
                return true;

        return false;
    }

    virtual void render()
    {
    }

private:
};