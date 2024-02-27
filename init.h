#pragma once
#include "AUMapping.h"
#include "LXParameterList.h"
#include "LXModuleList.h"
#include "LXControllerList.h"
#include "LXViewList.h"
#include "LXOverview.h"
#include "digitalio.h"
#include "LXMidi.h"
#include "waves.h"

FLASHMEM void storeParameter(const char *parm) { LOG(F("storing :") << parm); }

FLASHMEM void initParameters()
{
    LOG("[INIT] Parameters");

    // OSC A
    Parameters.add(osc_a_shape)->setRange(0, 11)->setValue(WAVEFORM_SQUARE);
    Parameters.add(osc_a_amp)->setRange(0, 1)->setValue(1.0);
    Parameters.add(osc_a_freq)->setRange(0.1, 20000)->setValue(400);
    Parameters.add(osc_a_detune)->setRange(0, 1)->setValue(0.1);
    Parameters.add(osc_a_pwm_octaves)->setRange(0,12)->setValue(10);

    // OSC B
    Parameters.add(osc_b_shape)->setRange(0, 11)->setValue(WAVEFORM_SAWTOOTH);
    Parameters.add(osc_b_amp)->setRange(0, 1)->setValue(1);
    Parameters.add(osc_b_freq)->setRange(0.1, 20000)->setValue(400);
    Parameters.add(osc_b_detune)->setRange(0, 1)->setValue(0.1);
    Parameters.add(osc_b_pwm_octaves)->setRange(0,12)->setValue(10);

    // AMPLITUDE ENVELOPE
    Parameters.add(ParmKeys::aenv_amount)->setRange(0, 1)->setValue(0.25f)->taper(TAPER_AUDIO);
    Parameters.add(ParmKeys::aenv_attack)->setRange(0, 10000)->setValue(1)->taper(TAPER_AUDIO);
    Parameters.add(ParmKeys::aenv_hold)->setRange(0, 10000)->setValue(0)->taper(TAPER_AUDIO);
    Parameters.add(ParmKeys::aenv_decay)->setRange(0, 10000)->setValue(150)->taper(TAPER_AUDIO);
    Parameters.add(ParmKeys::aenv_sustain)->setRange(0, 1)->setValue(0.2f)->taper(TAPER_AUDIO);
    Parameters.add(ParmKeys::aenv_release)->setRange(0, 10000)->setValue(100)->taper(TAPER_AUDIO);
    Parameters.add(ParmKeys::aenv_invert)->setRange(0, 1)->setValue(0)->taper(TAPER_AUDIO);

    // PITCH ENVELOPE
    Parameters.add(ParmKeys::penv_amount)->setRange(0, 1)->setValue(0);
    Parameters.add(ParmKeys::penv_attack)->setRange(0, 10000)->setValue(1);
    Parameters.add(ParmKeys::penv_hold)->setRange(0, 10000)->setValue(0);
    Parameters.add(ParmKeys::penv_decay)->setRange(0, 10000)->setValue(0);
    Parameters.add(ParmKeys::penv_sustain)->setRange(0, 1)->setValue(1);
    Parameters.add(ParmKeys::penv_release)->setRange(0, 10000)->setValue(1);
    Parameters.add(ParmKeys::penv_invert)->setRange(0, 1)->setValue(0);

    // FILTER ENVELOPE
    Parameters.add(ParmKeys::fenv_amount)->setRange(0, 1)->setValue(0);
    Parameters.add(ParmKeys::fenv_attack)->setRange(0, 10000)->setValue(0);
    Parameters.add(ParmKeys::fenv_hold)->setRange(0, 10000)->setValue(0);
    Parameters.add(ParmKeys::fenv_decay)->setRange(0, 10000)->setValue(0);
    Parameters.add(ParmKeys::fenv_sustain)->setRange(0, 1)->setValue(1);
    Parameters.add(ParmKeys::fenv_release)->setRange(0, 10000)->setValue(100);
    Parameters.add(ParmKeys::fenv_invert)->setRange(0, 1)->setValue(0);

    // AMPLITUDE LFO
    Parameters.add(ParmKeys::alfo_amount)->setRange(0, 1)->setValue(0);
    Parameters.add(ParmKeys::alfo_freq)->setRange(0, 3000)->setValue(1);
    Parameters.add(ParmKeys::alfo_shape)->setRange(0, 11)->setValue(1);
    Parameters.add(ParmKeys::amp_bend)->setRange(0, 1)->setValue(0);

    // PITCH LFO
    Parameters.add(ParmKeys::plfo_amount)->setRange(0, 1)->setValue(0);
    Parameters.add(ParmKeys::plfo_freq)->setRange(0, 3000)->setValue(20);
    Parameters.add(ParmKeys::plfo_shape)->setRange(0, 11)->setValue(1);
    Parameters.add(ParmKeys::pitch_bend)->setRange(0, 1)->setValue(0);

    // FILTER LFO
    Parameters.add(ParmKeys::flfo_amount)->setRange(0, 1)->setValue(0);
    Parameters.add(ParmKeys::flfo_freq)->setRange(0, 3000)->setValue(0.1);
    Parameters.add(ParmKeys::flfo_shape)->setRange(0, 11)->setValue(WAVEFORM_SINE);
    Parameters.add(ParmKeys::filter_bend)->setRange(0, 1)->setValue(0);

    // NOISE
    Parameters.add(ParmKeys::noise_level)->setRange(0, 1)->setValue(1); // 0 = off ... 1 = on
    Parameters.add(ParmKeys::noise_type)->setRange(0, 1)->setValue(1);  // 0 = white ... 1 = pink

    // PWM
    Parameters.add(ParmKeys::pwm_a_shape)->setRange(0, 11)->setValue(WAVEFORM_PULSE); // pulse
    Parameters.add(ParmKeys::pwm_a_freq)->setRange(0, 127)->setValue(10);            // 1 hertz
    Parameters.add(ParmKeys::pwm_a_gain)->setRange(0, 1)->setValue(1);                // 0 gain = off
    Parameters.add(ParmKeys::pwm_b_shape)->setRange(0, 11)->setValue(WAVEFORM_PULSE); // pulse
    Parameters.add(ParmKeys::pwm_b_freq)->setRange(0, 127)->setValue(10);            // 1 hertz
    Parameters.add(ParmKeys::pwm_b_gain)->setRange(0, 1)->setValue(1);                // 0 gain = off

    // XMod
    Parameters.add(ParmKeys::xmod_amount)->setRange(0, 1)->setValue(1.0); // no cross mod (0.5)

    // RingMod
    Parameters.add(ParmKeys::ring_shape)->setRange(0, 11)->setValue(0);   // sine
    Parameters.add(ParmKeys::ring_freq)->setRange(0, 20000)->setValue(0); // freq
    Parameters.add(ParmKeys::ring_level)->setRange(0, 1)->setValue(0);    // off

    // Waveshaper
    Parameters.add(ParmKeys::shaper_pregain)->setRange(0, 2)->setValue(1.0); // preamp
    Parameters.add(ParmKeys::shaper_curve)->setRange(0, 29)->setValue(9);    // shape
    Parameters.add(ParmKeys::shaper_bypass)->setRange(0, 1)->setValue(0);    // bypass set

    // filter
    Parameters.add(ParmKeys::filter_type)->setRange(0, 3)->setValue(3);       // LPF 0, BPF 1, HPF 2, LADDER 3
    Parameters.add(ParmKeys::filter_freq)->setRange(0, 20000)->setValue(400); // 20000 Hz
    Parameters.add(ParmKeys::filter_res)->setRange(0.7, 5.0)->setValue(0.7);  // Q = 0.7 ... 5.0
    Parameters.add(ParmKeys::filter_octaves)->setRange(0, 7)->setValue(1.0);  // 0 ... 7
    Parameters.add(ParmKeys::filter_postgain)->setRange(0, 2)->setValue(1.0); // 1.0 = pass thru

    // master gain
    Parameters.add(ParmKeys::master_gain)->setRange(0, 1)->setValue(1.0)->taper(ParameterTaper::TAPER_AUDIO);
    Parameters.add(ParmKeys::master_pan)->setRange(0, 1)->setValue(1.0);

    // part mixer
    Parameters.add(ParmKeys::partpan_ab)->setRange(0, 1)->setValue(0.5);

    // voice mixer
    Parameters.add(ParmKeys::voice_gain0)->setRange(0, 1)->setValue(0.8);
    Parameters.add(ParmKeys::voice_gain1)->setRange(0, 1)->setValue(0.8);
    Parameters.add(ParmKeys::voice_gain2)->setRange(0, 1)->setValue(0.8);
    Parameters.add(ParmKeys::voice_gain3)->setRange(0, 1)->setValue(0.8);
    Parameters.add(ParmKeys::voice_pan0)->setRange(0, 1)->setValue(0.5);
    Parameters.add(ParmKeys::voice_pan1)->setRange(0, 1)->setValue(0.5);
    Parameters.add(ParmKeys::voice_pan2)->setRange(0, 1)->setValue(0.5);
    Parameters.add(ParmKeys::voice_pan3)->setRange(0, 1)->setValue(0.5);

    // buttons
    Parameters.add(ParmKeys::pressedShift)->setRange(0, 1)->setValue(0);
    Parameters.add(ParmKeys::pressedEnter)->setRange(0, 1)->setValue(0);

    // SERIALIZE -----
    Parameters.serialize(&storeParameter);
}

FLASHMEM void initModules()
{
    LOG(F("[INIT] Modules"));
    // ModulatorBanks
    Modules.add<LXEnvModulatorBank>(ModKeys::AEnvModulator)
        ->attachParameters<LXEnvModulatorBank>(
            {aenv_attack, aenv_hold, aenv_decay, aenv_sustain, aenv_release, aenv_amount, aenv_invert, amp_bend,
             alfo_amount, alfo_freq, alfo_shape})
        ->attachEnvelopes({&auENV_AMP_V1, &auENV_AMP_V2, &auENV_AMP_V3, &auENV_AMP_V4})
        ->attachAmountDC(&auDC_AMPENV)
        ->attachLFOWave(&auLFO_AMP);

    Modules.add<LXEnvModulatorBank>(ModKeys::FEnvModulator)
        ->attachParameters<LXEnvModulatorBank>(
            {fenv_attack, fenv_hold, fenv_decay, fenv_sustain, fenv_release, fenv_amount, fenv_invert, filter_bend,
             flfo_amount, flfo_freq, flfo_shape})
        ->attachEnvelopes({&auENV_FILTER_V1, &auENV_FILTER_V2, &auENV_FILTER_V3, &auENV_FILTER_V4})
        ->attachAmountDC(&auDC_FILTERENV)
        ->attachLFOWave(&auLFO_FILTER);

    Modules.add<LXEnvModulatorBank>(ModKeys::PEnvModulator)
        ->attachParameters<LXEnvModulatorBank>(
            {penv_attack, penv_hold, penv_decay, penv_sustain, penv_release, penv_amount, penv_invert, pitch_bend,
             plfo_amount, plfo_freq, plfo_shape})
        ->attachEnvelopes({&auENV_PITCH_V1, &auENV_PITCH_V2, &auENV_PITCH_V3, &auENV_PITCH_V4})
        ->attachAmountDC(&auDC_PITCHENV)
        ->attachBendDC(&auDC_PITCHBEND)
        ->attachLFOWave(&auLFO_PITCH);

    // PWM
    Modules.add<LXPulseWidthMod>(ModKeys::PulseWidthModA)
        ->attachParameters<LXPulseWidthMod>({pwm_a_freq, pwm_a_gain, pwm_a_shape})
        ->attachAmp(&auAMP_PWM_a)
        ->attachPWMWave(&auWAVE_PWM_a);
    Modules.add<LXPulseWidthMod>(ModKeys::PulseWidthModB)
        ->attachParameters<LXPulseWidthMod>({pwm_b_freq, pwm_b_gain, pwm_b_shape})
        ->attachAmp(&auAMP_PWM_b)
        ->attachPWMWave(&auWAVE_PWM_b);

    // Oscillators
    Modules.add<LXOscillator>(OscillatorA)
        ->attachParameters<LXOscillator>({osc_a_amp, osc_a_detune, osc_a_freq, osc_a_shape})
        ->attachAudioUnits({&auDCO_V1a, &auDCO_V2a, &auDCO_V3a, &auDCO_V4a});
    Modules.add<LXOscillator>(OscillatorB)
        ->attachParameters<LXOscillator>({osc_b_amp, osc_b_detune, osc_b_freq, osc_b_shape})
        ->attachAudioUnits({&auDCO_v1b, &auDCO_v2b, &auDCO_v3b, &auDCO_v4b});

    // Global modules
    Modules.add<LXCrossModulation>(ModKeys::XModulator);
    Modules.add<LXRingModulation>(ModKeys::RingMod);
    Modules.add<LXFilterBank>(ModKeys::FilterBank);
    Modules.add<LXNoiseGen>(ModKeys::NoiseGen);
    Modules.add<LXPartMixer>(ModKeys::PartMixer);
    Modules.add<LXWaveShaper>(ModKeys::Shaper);
    Modules.add<LXVoiceMixer>(ModKeys::VoiceMixer);
}

FLASHMEM void initControllers()
{
    LOG(F("[INIT] Controllers"));
    Controllers.add<LXPotentiometer>(b1_Fader1)->setPin(B1_POT_Fader1)->attachParameters({aenv_attack});
    Controllers.add<LXPotentiometer>(b1_Fader2)->setPin(B1_POT_Fader2)->attachParameters({aenv_decay});
    Controllers.add<LXPotentiometer>(b1_Fader3)->setPin(B1_POT_Fader3)->attachParameters({aenv_sustain});
    Controllers.add<LXPotentiometer>(b1_Fader4)->setPin(B1_POT_Fader4)->attachParameters({aenv_release});
    Controllers.add<LXPotentiometer>(b1_Pot1)->setPin(B1_POT_1)->attachParameters({osc_a_shape});
    Controllers.add<LXPotentiometer>(b1_Pot2)->setPin(B1_POT_2)->attachParameters({osc_b_shape});
    Controllers.add<LXPotentiometer>(b1_Pot3)->setPin(B1_POT_3)->attachParameters({pwm_a_freq, pwm_b_freq});

    Controllers.add<LXPotentiometer>(potDataA)->setPin(POT_Data1)->attachParameters({filter_freq});
    Controllers.add<LXPotentiometer>(potDataB)->setPin(POT_Data2)->attachParameters({filter_res});
    Controllers.add<LXPotentiometer>(potDataC)->setPin(POT_Data3)->attachParameters({master_pan});
    Controllers.add<LXPotentiometer>(potDataD)->setPin(POT_Data4)->attachParameters({master_gain});

    //  Controllers.add<LXPotentiometer>(ContKeys::b1_Pot1)->attachParameters<LXPotentiometer>({})->setPin(14);
    //  Controllers.add<LXButton>(ContKeys::btnShift)->attachParameters<LXButton>({pressedShift})->setPin(30);
    //  Controllers.add<LXButton>(ContKeys::btnEnter)->attachParameters<LXButton>({pressedEnter})->setPin(31);
    //  Controllers.add<LXRotary>(ContKeys::rotA)->setPins(34, 35);
}

FLASHMEM void initViews()
{
    Views.add<LXOverview>(ViewKeys::overview)->attachParameters(Parameters.items);
}