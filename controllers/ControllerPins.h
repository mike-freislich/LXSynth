#pragma once

enum ControllerPins
{
    // display board : data pots
    POT_Data1 = 0,
    POT_Data2 = 1,
    POT_Data3 = 2,
    POT_Data4 = 3,

    // envelope board (v1)
    B1_POT_1 = 32,
    B1_POT_2 = 33,
    B1_POT_3 = 34,
    B1_POT_Fader1 = 36,
    B1_POT_Fader2 = 37,
    B1_POT_Fader3 = 38,
    B1_POT_Fader4 = 39,

    // vco board (v1)
    POT_V1_Waveform = 7,
    POT_V1_PulseWidth = 8,
    POT_V1_Tune = 9,
    POT_V1_Mix = 10,
    POT_V1_RingLevel = 11,
    POT_V1_RingFreq = 12,
    POT_V1_NoiseLevel = 13,
    POT_V1_Pan = 14,
    POT_V1_ShaperWave = 15,
    POT_V1_ShaperCurve = 16,
    POT_V1_XmodSend = 17

    
};