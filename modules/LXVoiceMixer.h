#pragma once
#include "LXModule.h"

class LXVoiceMixer : public LXModule
{
public:
    LXVoiceMixer(ModKeys key) : LXModule(key)
    {
        _voiceGains = {Parameters[voice_gain0], Parameters[voice_gain1], Parameters[voice_gain2], Parameters[voice_gain3]};
        _voicePans = {Parameters[voice_pan0], Parameters[voice_pan1], Parameters[voice_pan2], Parameters[voice_pan3]};
        _masterGain = Parameters[master_gain];
        _masterPan = Parameters[master_pan];

        _voiceMixL = &auMIXER_FINAL_L;
        _voiceMixR = &auMIXER_FINAL_R;
        _masterAmpL = &auAMP_MASTER_GAIN_L;
        _masterAmpR = &auAMP_MASTER_GAIN_R;
    }

    ItemType getType() override { return ItemType::TLXVoiceMixer; }

    void getStereoGainLR(float gain, float pan, float &left, float &right)
    {
        left = (1 - pan) * gain;
        right = (1 - left) * gain;
    }

    float getVoicePan(uint8_t voice)
    {
        voice = clampf<uint8_t>(voice, 0, _voicePans.size());
        return _voicePans[voice]->getValue();
    }

    float getVoiceGain(uint8_t voice)
    {
        voice = clampf<uint8_t>(voice, 0, _voiceGains.size());
        return _voiceGains[voice]->getValue();
    }

    float getMasterPan() { return _masterPan->getValue(); }
    float getMasterGain() { return _masterGain->getValue(); }

    /**
     * @brief
     * Pans a stereo channel to the relevant position.
     * @param channel 4 channels : 0-3
     * @param position  L<<0.0 <<0.5>> 1.0>>R
     */
    void voicePan(uint8_t voice, float position)
    {
        if (voice >= 0 && voice < _voicePans.size())
        {
            position = clampf<uint8_t>(position, 0, 1.0);
            _voicePans[voice]->setValue(position);
        }
    }

    void voiceGain(uint8_t voice, float value)
    {
        if (voice >= 0 && voice < _voiceGains.size())
        {
            value = clampf<uint8_t>(value, 0, 1.0);
            _voiceGains[voice]->setValue(value);
        }
    }

    void masterPan(float value) { _masterPan->setValue(clampf<float>(value, 0, 1.0f)); }
    void masterGain(float value) { _masterGain->setValue(clampf<float>(value, 0, 1.5f)); }

    void update() override
    {
        LXModule::update();

        float left, right;

        // set mixer channel levels
        for (uint8_t voice = 0; voice < _voicePans.size(); voice++)
        {
            if (_voicePans[voice]->changed(true) || _voiceGains[voice]->changed(true))
            {
                getStereoGainLR(
                    _voiceGains[voice]->getValue(),
                    _voicePans[voice]->getValue(),
                    left, right);
                _voiceMixL->gain(voice, left);
                _voiceMixR->gain(voice, right);
            }
        }
        // set output amp levels
        if (_masterPan->changed(true) || _masterGain->changed(true))
        {
            getStereoGainLR(_masterGain->getValue(), _masterPan->getValue(), left, right);
            _masterAmpL->gain(left);
            _masterAmpR->gain(right);
        }
    }

private:
    LXParameter *_masterGain, *_masterPan;
    AudioMixer4 *_voiceMixL, *_voiceMixR;
    AudioAmplifier *_masterAmpL, *_masterAmpR;
    std::vector<LXParameter *> _voiceGains;
    std::vector<LXParameter *> _voicePans;
};
