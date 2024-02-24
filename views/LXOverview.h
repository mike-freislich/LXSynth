#pragma once
#include "LXView.h"

class LXOverview : public LXView
{
public:
    LXOverview(ViewKeys key) : LXView(key) {}
     const ItemType getType() { return ItemType::TLXOverview; }
    ~LXOverview() {}

     void update() override  {
        render();
    }

protected:
    void render() override  
    {
        // drawOscillators();
        // drawEnvelopes();
        // drawLfos();
        //drawPeaks();

        // uint8_t parmcount = 0;
        // for (auto p : _parameters)
        // {
        //     float value = p->getValue();
        //     const char *name = parmKey_cstr(p->key);
        //     Serial.printf("%15s : %7.2f", name, value);
        //     parmcount++;
        //     if (parmcount % 6 == 0)
        //         Serial.print("\n");
        //     else
        //         Serial.print("\t");
        // }
        //Serial.println("\n--------------------------------------------------------------------------------------------------");
    }

     void drawPeaks()
    {
        float peakAMTotal = auPEAK_AMPMOD_TOTAL.read();
        float peakAMPost = auPEAK_AM_POST.read();
        printf("pre mult gain %d, level pre final mix = %d\n", int(peakAMTotal * 100.0f), int(peakAMPost * 100.0f));
    }

     void drawEnvelopes()
    {
        drawParms({aenv_amount, aenv_attack, aenv_decay, aenv_hold, aenv_sustain, aenv_release});
        drawParms({penv_amount, penv_attack, penv_decay, penv_hold, penv_sustain, penv_release});
        drawParms({fenv_amount, fenv_attack, fenv_decay, fenv_hold, fenv_sustain, fenv_release});
    }
     void drawLfos()
    {
        drawParms({alfo_amount, alfo_freq, alfo_shape});
        drawParms({plfo_amount, plfo_freq, plfo_shape});
        drawParms({flfo_amount, flfo_freq, flfo_shape});
    }
     void drawOscillators()
    {
        drawParms({osc_a_amp, osc_a_detune, osc_a_freq, osc_a_shape});
        drawParms({osc_b_amp, osc_b_detune, osc_b_freq, osc_b_shape});
    }

     void drawParms(const std::vector<ParmKeys> &keys)
    {
        for (auto k : keys)
        {
            if (LXParameter *p = Parameters[k])
            {
                float value = p->getValue();
                const char *name = parmKey_cstr(p->key);
                // printf("testing %7.2f\t", value);
                Serial.printf("%15s : %7.2f", name, value);
            }
        }
        Serial.print("\n");
    }
};