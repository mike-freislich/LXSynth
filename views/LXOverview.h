#pragma once
#include "LXView.h"

class LXOverview : public LXView
{
public:
    LXOverview(ViewKeys key) : LXView(key) { }
    ItemType getType() { return ItemType::TLXOverview; }
    ~LXOverview() {}

protected:
    void render() override
    {
        uint8_t parmcount = 0;

        for (auto p : _parameters)
        {            
            float value = p->getValue();
            const char *name = parmKey_cstr(p->key);
            Serial.printf("%15s : %7.2f", name, value);
            
            parmcount ++;
            if (parmcount % 6 == 0)
                Serial.print("\n");
            else
                Serial.print("\t");                                    
        }
        Serial.println("\n--------------------------------------------------------------------------------------------------");
    }
};