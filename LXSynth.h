#pragma once
#ifdef BUILD_FOR_TEENSY
#include <Audio.h>
#endif

#include "init.h"
#define VOICES 4

class LXSynth
{
public:
    enum VoiceMode
    {
        Poly,
        Unison
    };

    LXSynth()
    {
    }

    void init()
    {
        LOG("[INIT] digital IO");
        digitalIO.init();
        initMidi();
        AudioMemory(64);
        initMixers();
        initParameters();
        initModules();
        initControllers();
        initViews();

        LOG("[INIT] Envelope Modulators");
        _envModulators = {
            Modules.module<LXEnvModulatorBank>(TLXEnvModulatorBank, AEnvModulator),
            Modules.module<LXEnvModulatorBank>(TLXEnvModulatorBank, PEnvModulator),
            Modules.module<LXEnvModulatorBank>(TLXEnvModulatorBank, FEnvModulator)};

        Modules.module<LXPulseWidthMod>(TLXPulseWidthMod, PulseWidthModA)->begin();
        Modules.module<LXPulseWidthMod>(TLXPulseWidthMod, PulseWidthModB)->begin();

        LOG("[INIT] VoiceMode");
        _voiceMode = VoiceMode::Unison;

        _osc = {
            Modules.module<LXOscillator>(TLXOscillator, OscillatorA),
            Modules.module<LXOscillator>(TLXOscillator, OscillatorB)};

        AudioProcessorUsageMaxReset();
        AudioMemoryUsageMaxReset();
    }

    FLASHMEM void initMixer(AudioMixer4 *mixer, float gain)
    {
        mixer->gain(0, gain);
        mixer->gain(1, gain);
        mixer->gain(2, gain);
        mixer->gain(3, gain);
    }

    FLASHMEM void initMixers()
    {

        // initMixer(&auMIXER_AM_V1a, 1.0f);
        // initMixer(&auMIXER_AM_V2a, 1.0f);
        // initMixer(&auMIXER_AM_V3a, 1.0f);
        // initMixer(&auMIXER_AM_V4a, 1.0f);
        // initMixer(&auMIXER_AM_V1b, 1.0f);
        // initMixer(&auMIXER_AM_V2b, 1.0f);
        // initMixer(&auMIXER_AM_V3b, 1.0f);
        // initMixer(&auMIXER_AM_V4b, 1.0f);

        // initMixer(&auMIXER_FM_v1a, 1.0f);
        // initMixer(&auMIXER_FM_v2a, 1.0f);
        // initMixer(&auMIXER_FM_v3a, 1.0f);
        // initMixer(&auMIXER_FM_v4a, 1.0f);
        // initMixer(&auMIXER_FM_v1b, 1.0f);
        // initMixer(&auMIXER_FM_v2b, 1.0f);
        // initMixer(&auMIXER_FM_v3b, 1.0f);
        // initMixer(&auMIXER_FM_v4b, 1.0f);

        // initMixer(&auMIXER_WAVE_V1a, 1.0f);
        // initMixer(&auMIXER_WAVE_V2a, 1.0f);
        // initMixer(&auMIXER_WAVE_V3a, 1.0f);
        // initMixer(&auMIXER_WAVE_V4a, 1.0f);
        // initMixer(&auMIXER_WAVE_V1b, 1.0f);
        // initMixer(&auMIXER_WAVE_V2b, 1.0f);
        // initMixer(&auMIXER_WAVE_V3b, 1.0f);
        // initMixer(&auMIXER_WAVE_V4b, 1.0f);

        // initMixer(&_auMIXER_AMPMOD_V1, 1.0f);
        // initMixer(&_auMIXER_AMPMOD_V2, 1.0f);
        // initMixer(&_auMIXER_AMPMOD_V3, 1.0f);
        // initMixer(&_auMIXER_AMPMOD_V4, 1.0f);

        // initMixer(&auMIXER_NOISE, 1.0f);

        // initMixer(&auMIXER_PRESHAPE_V1, 0.25f);
        // initMixer(&auMIXER_PRESHAPE_V2, 0.25f);
        // initMixer(&auMIXER_PRESHAPE_V3, 0.25f);
        // initMixer(&auMIXER_PRESHAPE_V4, 0.25f);
    }

    void update()
    {
        Controllers.update(); // read controller values and set parameters
        usbMIDI.read();       // read midi values
        Modules.update();     // check parameters per module and change audio unit parameters
        Views.update();
    }

    void voiceMode(VoiceMode mode) { _voiceMode = mode; }

    void noteOn(byte channel, byte note, byte velocity)
    {
        midi.addNote(note);

        if (_voiceMode == Unison)
        {
            _osc[0]->frequency(noteFreqs[note]);
            _osc[1]->frequency(noteFreqs[note]);

            for (auto &mod : _envModulators)
                mod->noteOn();
        }
        else
        {
            // TODO handle polyphonic mode
        }
    }

    void noteOff(byte channel, byte note, byte velocity)
    {
        int8_t nextNote = midi.releaseNote(note);

        if (_voiceMode == Unison)
        {
            if (nextNote == -1)
            {
                for (auto &mod : _envModulators)
                    mod->noteOff();
            }
            else
            {
                _osc[0]->frequency(noteFreqs[nextNote]);
                _osc[1]->frequency(noteFreqs[nextNote]);
            }
        }
        else
        {
            // TODO POLYPHONIC need a way of keeping track which note was lifted and therefore which voice to release
            for (auto &mod : _envModulators)
                mod->noteOff(_polyLastVoice);
        }
    }

    void clock()
    {
        static int MidiCLKcount = 0;
        MidiCLKcount++;
        // if (MidiCLKcount == 1)
        // {
        //     // lastClock = millis();
        //     //  Serial.println("midi beat");
        // }
        // // else if (MidiCLKcount == 2)
        // // {
        // //     // uint32_t now = millis();
        // //     // uint32_t elapsed = now - lastClock;
        // //     // uint32_t millisPerBeat = elapsed * (uint8_t)ClockDiv::quarter;
        // //     // Serial.print("elapsed : ");
        // //     // Serial.println(elapsed);
        // //     // float bpm = 1.0f / (millisPerBeat / 1000) * 60;
        // //     // if ((int)bpm != lastTempo)
        // //     // {
        // //     //     // lastTempo = (int)bpm;
        // //     //     // Serial.print("tempo changed : ");
        // //     //     // Serial.println( bpm);
        // //     // }
        // // }
        if (MidiCLKcount >= ClockDiv::quarter)
            MidiCLKcount = 0;
    }

    void pitchBend(byte channel, int pitch) {}

    void afterTouch(byte channel, byte pressure) {}

    void controlChange(byte channel, byte control, byte value) {}

private:
    VoiceMode _voiceMode = Unison;
    uint8_t _polyLastVoice = 0;
    std::vector<LXEnvModulatorBank *> _envModulators;
    std::vector<LXOscillator *> _osc;
    uint8_t noteBuffer[VOICES] = {255, 255, 255, 255};
    uint8_t nbIndex = 0;
} synth;

// Wrapper methods for midi callbacks
void myNoteOn(byte channel, byte note, byte velocity)
{
    // printf("note on channel: %d. note %d, velocity %d\n", channel, note, velocity);
    synth.noteOn(channel, note, velocity);
}
void myNoteOff(byte channel, byte note, byte velocity) { synth.noteOff(channel, note, velocity); }
void myClock() { synth.clock(); }
void myPitchChange(byte channel, int pitch) { synth.pitchBend(channel, pitch); }
void myAfterTouch(byte channel, byte pressure) { synth.afterTouch(channel, pressure); }
void myControlChange(byte channel, byte control, byte value) { synth.controlChange(channel, control, value); }
