#pragma once

enum ModKeys
{
    OscillatorA = 110,
    OscillatorB = 111,
    AEnvModulator = 120,
    FEnvModulator= 130,
    PEnvModulator = 140,    
    PulseWidthModA = 150,  
    PulseWidthModB = 151,    
    FilterBank = 160,
    XModulator = 170,
    Shaper = 180,
    PartMixer = 190,
    NoiseGen = 200,
    RingMod = 210,
    VoiceMixer = 220,
    MainAmp = 230
};

FLASHMEM const char * modKey_cstr(ModKeys key)
{
    switch (key)
    {
    case OscillatorA: return "OscillatorA"; 
    case OscillatorB: return "OscillatorB";
    case AEnvModulator: return "AEnvModulator";
    case FEnvModulator: return "FEnvModulator";
    case PEnvModulator: return "PEnvModulator";
    case PulseWidthModA: return "PulseWidthModA";
    case PulseWidthModB: return "PulseWidthModB";
    case FilterBank: return "FilterBank";
    case XModulator: return "XModulator";
    case Shaper: return "Shaper";
    case PartMixer: return "PartMixer";
    case NoiseGen: return "NoiseGen";
    case RingMod: return "RingMod";
    case VoiceMixer: return "VoiceMixer";
    case MainAmp: return "MainAmp";


    default: return "unknown";
    }
}