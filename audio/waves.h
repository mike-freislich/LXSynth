#pragma once
#include "synth_waveform.h"

const uint8_t waves[] PROGMEM = {
    WAVEFORM_SINE,
    WAVEFORM_TRIANGLE,
    WAVEFORM_SAWTOOTH,
    WAVEFORM_SQUARE,
    WAVEFORM_PULSE,
    WAVEFORM_SAMPLE_HOLD,
    WAVEFORM_BANDLIMIT_PULSE,
    WAVEFORM_BANDLIMIT_SAWTOOTH,
    WAVEFORM_BANDLIMIT_SAWTOOTH_REVERSE,
    WAVEFORM_BANDLIMIT_SQUARE,
    WAVEFORM_TRIANGLE_VARIABLE,
    WAVEFORM_ARBITRARY};
