#pragma once

enum ControllerPins
{
    // envelope board (v1)
    POT_V1_Fader1 = 36,
    POT_V1_Fader2 = 37,
    POT_V1_Fader3 = 38,
    POT_V1_Fader4 = 39,
    POT_V1_EnvLevel = 4,
    POT_V1_Cutoff = 5,
    POT_V1_Resonance = 6,

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
    POT_V1_XmodSend = 17,

    // display board : data pots
    POT_Data1 = 18,
    POT_Data2 = 19,
    POT_Data3 = 20,
    POT_Data4 = 21
};