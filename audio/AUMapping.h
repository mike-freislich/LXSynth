#pragma once

#ifdef BUILD_FOR_TEENSY
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#else
#include "AudioStub.h"
#endif

// GUItool: begin automatically generated code
AudioSynthWaveformDc     auDC_PITCHENV;  //xy=157,1539.5
AudioEffectEnvelope      auENV_PITCH_V2; //xy=212,1635.5
AudioEffectEnvelope      auENV_PITCH_V3; //xy=213,1670.5
AudioEffectEnvelope      auENV_PITCH_V4; //xy=213,1704.5
AudioEffectEnvelope      auENV_PITCH_V1; //xy=214.66666412353516,1600.499981880188
AudioSynthWaveform       auWAVE_PWM_b;   //xy=354,2153.5
AudioSynthWaveform       auWAVE_PWM_a;   //xy=390,1150.5
AudioSynthWaveformDc     auDC_PITCHBEND; //xy=447,1666.5
AudioAmplifier           auAMP_PWM_b;    //xy=539,2153.5
AudioAmplifier           auAMP_PWM_a;    //xy=582,1148.5
AudioMixer4              auMIXER_FM_v1b; //xy=599,1892.5
AudioMixer4              auMIXER_FM_v2b; //xy=599,1958.5
AudioMixer4              auMIXER_FM_v3b; //xy=599,2021.5
AudioMixer4              auMIXER_FM_v4b; //xy=599,2087.5
AudioMixer4              auMIXER_FM_v4a; //xy=603,1225.5
AudioMixer4              auMIXER_FM_v3a; //xy=604,1289.5
AudioMixer4              auMIXER_FM_v2a; //xy=604,1353.5
AudioMixer4              auMIXER_FM_v1a; //xy=604,1418.5
AudioSynthWaveformModulated auLFO_PITCH;    //xy=650,1665.5
AudioSynthWaveformModulated auDCO_V3a;      //xy=821,1181.5
AudioSynthWaveformModulated auDCO_V1a;      //xy=821,1249.5
AudioSynthWaveformModulated auDCO_V4a;      //xy=822,1147.5
AudioSynthWaveformModulated auDCO_V2a;      //xy=822,1215.5
AudioSynthWaveformModulated auDCO_v1b;      //xy=827,2048.5
AudioSynthWaveformModulated auDCO_v2b;      //xy=830,2083.5
AudioSynthWaveformModulated auDCO_v3b;      //xy=831,2118.5
AudioSynthWaveformModulated auDCO_v4b;      //xy=831,2153.5
AudioSynthWaveformDc     auDC_XMOD_a;    //xy=892,1645.5
AudioSynthWaveformDc     auDC_XMOD_b;    //xy=892,1687.5
AudioEffectMultiply      auMULT_XMOD_v2a; //xy=903,1427.5
AudioEffectMultiply      auMULT_XMOD_v1a; //xy=903,1462.5
AudioEffectMultiply      auMULT_XMOD_v4a; //xy=904,1358.5
AudioEffectMultiply      auMULT_XMOD_v3a; //xy=904,1393.5
AudioEffectMultiply      auMULT_XMOD_v4b; //xy=914,1954.5
AudioEffectMultiply      auMULT_XMOD_v3b; //xy=915,1919.5
AudioEffectMultiply      auMULT_XMOD_v2b; //xy=917,1884.5
AudioEffectMultiply      auMULT_XMOD_v1b; //xy=918,1849.5
AudioSynthWaveformDc     auDC_RINGMOD;   //xy=1121,1665.5
AudioSynthWaveform       auWAVE_RINGMOD; //xy=1213,1628.5
AudioMixer4              auMIXER_AM_V4a; //xy=1222,1188.5
AudioMixer4              auMIXER_AM_V3a; //xy=1222,1252.5
AudioMixer4              auMIXER_AM_V2a; //xy=1224,1315.5
AudioMixer4              auMIXER_AM_V1a; //xy=1224,1381.5
AudioMixer4              auMIXER_AM_V1b; //xy=1222,1941.5
AudioMixer4              auMIXER_AM_V4b; //xy=1222,2135.5
AudioMixer4              auMIXER_AM_V2b; //xy=1223,2006.5
AudioMixer4              auMIXER_AM_V3b; //xy=1223,2071.5
AudioEffectMultiply      au_MULT_ring;   //xy=1334,1666.5
AudioEffectMultiply      auMULT_AM_POST_V4b; //xy=1450,2132.5
AudioEffectMultiply      auMULT_AM_POST_V4a; //xy=1454,1182.5
AudioEffectMultiply      auMULT_AM_POST_V1b; //xy=1452,1935.5
AudioEffectMultiply      auMULT_AM_POST_V2b; //xy=1452,2001.5
AudioEffectMultiply      auMULT_AM_POST_V1a; //xy=1455,1374.5
AudioEffectMultiply      auMULT_AM_POST_V3b; //xy=1453,2069.5
AudioEffectMultiply      auMULT_AM_POST_V2a; //xy=1457,1312.5
AudioEffectMultiply      auMULT_AM_POST_V3a; //xy=1458,1246.5
AudioSynthNoiseWhite     auNOISE_WHITE;  //xy=1550,1559.5
AudioSynthNoisePink      auNOISE_PINK;   //xy=1557,1593.5
AudioMixer4              auMIXER_NOISE;  //xy=1649.5555267333984,1657.499984741211
AudioMixer4              auMIXER_WAVE_V3a; //xy=1724,1251.5
AudioMixer4              auMIXER_WAVE_V4a; //xy=1725,1188.5
AudioMixer4              auMIXER_WAVE_V2a; //xy=1725,1316.5
AudioMixer4              auMIXER_WAVE_V1a; //xy=1725,1380.5
AudioMixer4              auMIXER_WAVE_V4b; //xy=1728,2140.5
AudioMixer4              auMIXER_WAVE_V2b; //xy=1729,2010.5
AudioMixer4              auMIXER_WAVE_V3b; //xy=1729,2075.5
AudioMixer4              auMIXER_WAVE_V1b; //xy=1730,1945.5
AudioSynthWaveformDc     auDC_FILTERENV; //xy=1949,1169.5
AudioMixer4              auMIXER_PRESHAPE_V3; //xy=2027,1733.5
AudioMixer4              auMIXER_PRESHAPE_V2; //xy=2028,1667.5
AudioMixer4              auMIXER_PRESHAPE_V4; //xy=2028,1798.5
AudioMixer4              auMIXER_PRESHAPE_V1; //xy=2029,1602.5
AudioEffectEnvelope      auENV_FILTER_V1; //xy=2143,1302.5
AudioEffectEnvelope      auENV_FILTER_V2; //xy=2144,1334.5
AudioEffectEnvelope      auENV_FILTER_V3; //xy=2145,1366.5
AudioEffectEnvelope      auENV_FILTER_V4; //xy=2145,1399.5
AudioSynthWaveformModulated auLFO_FILTER;   //xy=2156,1220.5
AudioAmplifier           auAMP_SHAPER_PREAMP_V4; //xy=2331,2070.5
AudioAmplifier           auAMP_SHAPER_PREAMP_V3; //xy=2335,1905.5
AudioAmplifier           auAMP_SHAPER_PREAMP_V1; //xy=2339,1570.5
AudioMixer4              auMIXER_SHAPER_BYPASS_V4; //xy=2338,2149.5
AudioAmplifier           auAMP_SHAPER_PREAMP_V2; //xy=2340,1745.5
AudioMixer4              auMIXER_SHAPER_BYPASS_V1; //xy=2344,1657.5
AudioMixer4              auMIXER_SHAPER_BYPASS_V3; //xy=2343,1989.5
AudioMixer4              auMIXER_SHAPER_BYPASS_V2; //xy=2344,1828.5
AudioEffectWaveshaper    auSHAPER_V2;    //xy=2345,1779.5
AudioEffectWaveshaper    auSHAPER_V4;    //xy=2344,2103.5
AudioEffectWaveshaper    auSHAPER_V3;    //xy=2349,1940.5
AudioEffectWaveshaper    auSHAPER_V1;    //xy=2351,1607.5
AudioMixer4              auMIXER_FILTERMOD_V1; //xy=2419,1223.5
AudioMixer4              auMIXER_FILTERMOD_V2; //xy=2419,1287.5
AudioMixer4              auMIXER_FILTERMOD_V3; //xy=2420,1351.5
AudioMixer4              auMIXER_FILTERMOD_V4; //xy=2420,1419.5
AudioFilterStateVariable auFILTER_SV_V2; //xy=2676,1775.5
AudioFilterStateVariable auFILTER_SV_V1; //xy=2677,1586.5
AudioFilterStateVariable auFILTER_SV_V4; //xy=2678,2093.5
AudioFilterStateVariable auFILTER_SV_V3; //xy=2679,1931.5
AudioFilterLadder        auFILTER_LADDER_V2; //xy=2695,1824.5
AudioFilterLadder        auFILTER_LADDER_V1; //xy=2697,1635.5
AudioFilterLadder        auFILTER_LADDER_V3; //xy=2698,1979.5
AudioFilterLadder        auFILTER_LADDER_V4; //xy=2698,2140.5
AudioSynthWaveformDc     auDC_AMPENV;    //xy=2729.841262817383,1201.1189985275269
AudioEffectEnvelope      auENV_AMP_V1;   //xy=2948.142738342285,1288.499942779541
AudioEffectEnvelope      auENV_AMP_V2;   //xy=2948.142738342285,1323.499942779541
AudioEffectEnvelope      auENV_AMP_V3;   //xy=2948.142738342285,1357.499942779541
AudioEffectEnvelope      auENV_AMP_V4;   //xy=2948.142738342285,1391.499942779541
AudioSynthWaveformModulated auLFO_AMP;      //xy=2977,1229.5
AudioMixer4              auMIXER_FILTER_BLOCK_V2; //xy=3005,1671.5
AudioMixer4              auMIXER_FILTER_BLOCK_V3; //xy=3005,1735.5
AudioMixer4              auMIXER_FILTER_BLOCK_V4; //xy=3005,1800.5
AudioMixer4              auMIXER_FILTER_BLOCK_V1; //xy=3006,1608.5
AudioMixer4              auMIXER_FINAL_R; //xy=3088,2079.5
AudioMixer4              auMIXER_FINAL_L; //xy=3089,2013.5
AudioMixer4              _auMIXER_AMPMOD_V1; //xy=3255,1236.5
AudioMixer4              _auMIXER_AMPMOD_V2; //xy=3256,1298.5
AudioMixer4              _auMIXER_AMPMOD_V3; //xy=3256,1361.5
AudioMixer4              _auMIXER_AMPMOD_V4; //xy=3256,1423.5
AudioAmplifier           auAMP_POST_FILTER_V3; //xy=3275,1723.5
AudioAmplifier           auAMP_POST_FILTER_V4; //xy=3275,1758.5
AudioAmplifier           auAMP_POST_FILTER_V1; //xy=3276,1651.5
AudioAmplifier           auAMP_POST_FILTER_V2; //xy=3276,1687.5
AudioAmplifier           auAMP_MASTER_GAIN_L; //xy=3321,2021.5
AudioAmplifier           auAMP_MASTER_GAIN_R; //xy=3321,2061.5
AudioMixer4              auMIXER_AMPMOD_TOTAL;         //xy=3530.0001487731934,1324.2856216430664
AudioEffectMultiply      auMULT_AENV_POST_V2; //xy=3550,1689.5
AudioEffectMultiply      auMULT_AENV_POST_V3; //xy=3550,1723.5
AudioEffectMultiply      auMULT_AENV_POST_V4; //xy=3550,1758.5
AudioEffectMultiply      auMULT_AENV_POST_V1; //xy=3551,1656.5
AudioAnalyzePeak         auPEAK_R;       //xy=3550,2117.5
AudioAnalyzePeak         auPEAK_L;       //xy=3551,1975.5
AudioOutputUSB           auSTEREO_OUT;   //xy=3571,2079.5
AudioMixer4              auMIXER_SCOPE;  //xy=3575,2026.5
AudioAnalyzePeak         auPEAK_AMPMOD_TOTAL;          //xy=3659.999797821045,1231.4286012649536
AudioMixer4              auMixer_AM_POST;         //xy=3838.5712928771973,1627.1428470611572
AudioAnalyzePeak         auPEAK_AM_POST;          //xy=3899.999969482422,1552.8571691513062
AudioConnection          patchCord1(auDC_PITCHENV, auENV_PITCH_V1);
AudioConnection          patchCord2(auDC_PITCHENV, auENV_PITCH_V2);
AudioConnection          patchCord3(auDC_PITCHENV, auENV_PITCH_V3);
AudioConnection          patchCord4(auDC_PITCHENV, auENV_PITCH_V4);
AudioConnection          patchCord5(auENV_PITCH_V2, 0, auMIXER_FM_v2b, 0);
AudioConnection          patchCord6(auENV_PITCH_V2, 0, auMIXER_FM_v3a, 0);
AudioConnection          patchCord7(auENV_PITCH_V3, 0, auMIXER_FM_v3b, 0);
AudioConnection          patchCord8(auENV_PITCH_V3, 0, auMIXER_FM_v2a, 0);
AudioConnection          patchCord9(auENV_PITCH_V4, 0, auMIXER_FM_v4b, 0);
AudioConnection          patchCord10(auENV_PITCH_V4, 0, auMIXER_FM_v1a, 0);
AudioConnection          patchCord11(auENV_PITCH_V1, 0, auMIXER_FM_v1b, 0);
AudioConnection          patchCord12(auENV_PITCH_V1, 0, auMIXER_FM_v4a, 0);
AudioConnection          patchCord13(auWAVE_PWM_b, auAMP_PWM_b);
AudioConnection          patchCord14(auWAVE_PWM_a, auAMP_PWM_a);
AudioConnection          patchCord15(auDC_PITCHBEND, 0, auMIXER_FM_v1a, 1);
AudioConnection          patchCord16(auDC_PITCHBEND, 0, auMIXER_FM_v1b, 1);
AudioConnection          patchCord17(auDC_PITCHBEND, 0, auMIXER_FM_v2a, 1);
AudioConnection          patchCord18(auDC_PITCHBEND, 0, auMIXER_FM_v3a, 1);
AudioConnection          patchCord19(auDC_PITCHBEND, 0, auMIXER_FM_v4a, 1);
AudioConnection          patchCord20(auDC_PITCHBEND, 0, auMIXER_FM_v2b, 1);
AudioConnection          patchCord21(auDC_PITCHBEND, 0, auMIXER_FM_v3b, 1);
AudioConnection          patchCord22(auDC_PITCHBEND, 0, auMIXER_FM_v4b, 1);
AudioConnection          patchCord23(auAMP_PWM_b, 0, auDCO_v1b, 1);
AudioConnection          patchCord24(auAMP_PWM_b, 0, auDCO_v2b, 1);
AudioConnection          patchCord25(auAMP_PWM_b, 0, auDCO_v3b, 1);
AudioConnection          patchCord26(auAMP_PWM_b, 0, auDCO_v4b, 1);
AudioConnection          patchCord27(auAMP_PWM_a, 0, auDCO_V4a, 1);
AudioConnection          patchCord28(auAMP_PWM_a, 0, auDCO_V3a, 1);
AudioConnection          patchCord29(auAMP_PWM_a, 0, auDCO_V2a, 1);
AudioConnection          patchCord30(auAMP_PWM_a, 0, auDCO_V1a, 1);
AudioConnection          patchCord31(auMIXER_FM_v1b, 0, auDCO_v1b, 0);
AudioConnection          patchCord32(auMIXER_FM_v2b, 0, auDCO_v2b, 0);
AudioConnection          patchCord33(auMIXER_FM_v3b, 0, auDCO_v3b, 0);
AudioConnection          patchCord34(auMIXER_FM_v4b, 0, auDCO_v4b, 0);
AudioConnection          patchCord35(auMIXER_FM_v4a, 0, auDCO_V4a, 0);
AudioConnection          patchCord36(auMIXER_FM_v3a, 0, auDCO_V3a, 0);
AudioConnection          patchCord37(auMIXER_FM_v2a, 0, auDCO_V2a, 0);
AudioConnection          patchCord38(auMIXER_FM_v1a, 0, auDCO_V1a, 0);
AudioConnection          patchCord39(auLFO_PITCH, 0, auMIXER_FM_v1a, 2);
AudioConnection          patchCord40(auLFO_PITCH, 0, auMIXER_FM_v1b, 2);
AudioConnection          patchCord41(auLFO_PITCH, 0, auMIXER_FM_v2a, 2);
AudioConnection          patchCord42(auLFO_PITCH, 0, auMIXER_FM_v3a, 2);
AudioConnection          patchCord43(auLFO_PITCH, 0, auMIXER_FM_v4a, 2);
AudioConnection          patchCord44(auLFO_PITCH, 0, auMIXER_FM_v2b, 2);
AudioConnection          patchCord45(auLFO_PITCH, 0, auMIXER_FM_v3b, 2);
AudioConnection          patchCord46(auLFO_PITCH, 0, auMIXER_FM_v4b, 2);
AudioConnection          patchCord47(auDCO_V3a, 0, auMULT_XMOD_v3a, 0);
AudioConnection          patchCord48(auDCO_V3a, 0, auMULT_AM_POST_V3a, 0);
AudioConnection          patchCord49(auDCO_V3a, 0, auMIXER_WAVE_V3a, 0);
AudioConnection          patchCord50(auDCO_V1a, 0, auMIXER_WAVE_V1a, 0);
AudioConnection          patchCord51(auDCO_V1a, 0, auMULT_AM_POST_V1a, 0);
AudioConnection          patchCord52(auDCO_V1a, 0, auMULT_XMOD_v1a, 0);
AudioConnection          patchCord53(auDCO_V4a, 0, auMULT_XMOD_v4a, 0);
AudioConnection          patchCord54(auDCO_V4a, 0, auMULT_AM_POST_V4a, 0);
AudioConnection          patchCord55(auDCO_V4a, 0, auMIXER_WAVE_V4a, 0);
AudioConnection          patchCord56(auDCO_V2a, 0, auMULT_XMOD_v2a, 0);
AudioConnection          patchCord57(auDCO_V2a, 0, auMULT_AM_POST_V2a, 0);
AudioConnection          patchCord58(auDCO_V2a, 0, auMIXER_WAVE_V2a, 0);
AudioConnection          patchCord59(auDCO_v1b, 0, auMIXER_WAVE_V1b, 0);
AudioConnection          patchCord60(auDCO_v1b, 0, auMULT_AM_POST_V1b, 0);
AudioConnection          patchCord61(auDCO_v1b, 0, auMULT_XMOD_v1b, 0);
AudioConnection          patchCord62(auDCO_v2b, 0, auMULT_XMOD_v2b, 0);
AudioConnection          patchCord63(auDCO_v2b, 0, auMIXER_WAVE_V2b, 0);
AudioConnection          patchCord64(auDCO_v3b, 0, auMULT_XMOD_v3b, 0);
AudioConnection          patchCord65(auDCO_v3b, 0, auMIXER_WAVE_V3b, 0);
AudioConnection          patchCord66(auDCO_v4b, 0, auMULT_XMOD_v4b, 0);
AudioConnection          patchCord67(auDCO_v4b, 0, auMIXER_WAVE_V4b, 0);
AudioConnection          patchCord68(auDC_XMOD_a, 0, auMULT_XMOD_v1a, 1);
AudioConnection          patchCord69(auDC_XMOD_a, 0, auMULT_XMOD_v2a, 1);
AudioConnection          patchCord70(auDC_XMOD_a, 0, auMULT_XMOD_v3a, 1);
AudioConnection          patchCord71(auDC_XMOD_a, 0, auMULT_XMOD_v4a, 1);
AudioConnection          patchCord72(auDC_XMOD_b, 0, auMULT_XMOD_v1b, 1);
AudioConnection          patchCord73(auDC_XMOD_b, 0, auMULT_XMOD_v2b, 1);
AudioConnection          patchCord74(auDC_XMOD_b, 0, auMULT_XMOD_v3b, 1);
AudioConnection          patchCord75(auDC_XMOD_b, 0, auMULT_XMOD_v4b, 1);
AudioConnection          patchCord76(auMULT_XMOD_v2a, 0, auMIXER_AM_V2b, 0);
AudioConnection          patchCord77(auMULT_XMOD_v1a, 0, auMIXER_AM_V1b, 0);
AudioConnection          patchCord78(auMULT_XMOD_v4a, 0, auMIXER_AM_V4b, 0);
AudioConnection          patchCord79(auMULT_XMOD_v3a, 0, auMIXER_AM_V3b, 0);
AudioConnection          patchCord80(auMULT_XMOD_v4b, 0, auMIXER_AM_V4a, 0);
AudioConnection          patchCord81(auMULT_XMOD_v3b, 0, auMIXER_AM_V3a, 0);
AudioConnection          patchCord82(auMULT_XMOD_v2b, 0, auMIXER_AM_V2a, 0);
AudioConnection          patchCord83(auMULT_XMOD_v1b, 0, auMIXER_AM_V1a, 0);
AudioConnection          patchCord84(auDC_RINGMOD, 0, au_MULT_ring, 1);
AudioConnection          patchCord85(auWAVE_RINGMOD, 0, au_MULT_ring, 0);
AudioConnection          patchCord86(auMIXER_AM_V4a, 0, auMULT_AM_POST_V4a, 1);
AudioConnection          patchCord87(auMIXER_AM_V3a, 0, auMULT_AM_POST_V3a, 1);
AudioConnection          patchCord88(auMIXER_AM_V2a, 0, auMULT_AM_POST_V2a, 1);
AudioConnection          patchCord89(auMIXER_AM_V1a, 0, auMULT_AM_POST_V1a, 1);
AudioConnection          patchCord90(auMIXER_AM_V1b, 0, auMULT_AM_POST_V1b, 1);
AudioConnection          patchCord91(auMIXER_AM_V4b, 0, auMULT_AM_POST_V4b, 1);
AudioConnection          patchCord92(auMIXER_AM_V2b, 0, auMULT_AM_POST_V2b, 1);
AudioConnection          patchCord93(auMIXER_AM_V3b, 0, auMULT_AM_POST_V3b, 1);
AudioConnection          patchCord94(au_MULT_ring, 0, auMIXER_AM_V1a, 1);
AudioConnection          patchCord95(au_MULT_ring, 0, auMIXER_AM_V1b, 1);
AudioConnection          patchCord96(au_MULT_ring, 0, auMIXER_AM_V2a, 1);
AudioConnection          patchCord97(au_MULT_ring, 0, auMIXER_AM_V3a, 1);
AudioConnection          patchCord98(au_MULT_ring, 0, auMIXER_AM_V4a, 1);
AudioConnection          patchCord99(au_MULT_ring, 0, auMIXER_AM_V2b, 1);
AudioConnection          patchCord100(au_MULT_ring, 0, auMIXER_AM_V3b, 1);
AudioConnection          patchCord101(au_MULT_ring, 0, auMIXER_AM_V4b, 1);
AudioConnection          patchCord102(auMULT_AM_POST_V4b, 0, auMIXER_WAVE_V4b, 1);
AudioConnection          patchCord103(auMULT_AM_POST_V4a, 0, auMIXER_WAVE_V4a, 1);
AudioConnection          patchCord104(auMULT_AM_POST_V1b, 0, auMIXER_WAVE_V1b, 1);
AudioConnection          patchCord105(auMULT_AM_POST_V2b, 0, auMIXER_WAVE_V2b, 1);
AudioConnection          patchCord106(auMULT_AM_POST_V1a, 0, auMIXER_WAVE_V1a, 1);
AudioConnection          patchCord107(auMULT_AM_POST_V3b, 0, auMIXER_WAVE_V3b, 1);
AudioConnection          patchCord108(auMULT_AM_POST_V2a, 0, auMIXER_WAVE_V2a, 1);
AudioConnection          patchCord109(auMULT_AM_POST_V3a, 0, auMIXER_WAVE_V3a, 1);
AudioConnection          patchCord110(auNOISE_WHITE, 0, auMIXER_NOISE, 0);
AudioConnection          patchCord111(auNOISE_PINK, 0, auMIXER_NOISE, 1);
AudioConnection          patchCord112(auMIXER_NOISE, 0, auMIXER_WAVE_V1a, 2);
AudioConnection          patchCord113(auMIXER_NOISE, 0, auMIXER_WAVE_V2a, 2);
AudioConnection          patchCord114(auMIXER_NOISE, 0, auMIXER_WAVE_V3a, 2);
AudioConnection          patchCord115(auMIXER_NOISE, 0, auMIXER_WAVE_V4a, 2);
AudioConnection          patchCord116(auMIXER_NOISE, 0, auMIXER_WAVE_V1b, 2);
AudioConnection          patchCord117(auMIXER_NOISE, 0, auMIXER_WAVE_V2b, 2);
AudioConnection          patchCord118(auMIXER_NOISE, 0, auMIXER_WAVE_V3b, 2);
AudioConnection          patchCord119(auMIXER_NOISE, 0, auMIXER_WAVE_V4b, 2);
AudioConnection          patchCord120(auMIXER_WAVE_V3a, 0, auMIXER_PRESHAPE_V3, 0);
AudioConnection          patchCord121(auMIXER_WAVE_V4a, 0, auMIXER_PRESHAPE_V4, 0);
AudioConnection          patchCord122(auMIXER_WAVE_V2a, 0, auMIXER_PRESHAPE_V2, 0);
AudioConnection          patchCord123(auMIXER_WAVE_V1a, 0, auMIXER_PRESHAPE_V1, 0);
AudioConnection          patchCord124(auMIXER_WAVE_V4b, 0, auMIXER_PRESHAPE_V4, 1);
AudioConnection          patchCord125(auMIXER_WAVE_V2b, 0, auMIXER_PRESHAPE_V2, 1);
AudioConnection          patchCord126(auMIXER_WAVE_V3b, 0, auMIXER_PRESHAPE_V3, 1);
AudioConnection          patchCord127(auMIXER_WAVE_V1b, 0, auMIXER_PRESHAPE_V1, 1);
AudioConnection          patchCord128(auDC_FILTERENV, auENV_FILTER_V1);
AudioConnection          patchCord129(auDC_FILTERENV, auENV_FILTER_V2);
AudioConnection          patchCord130(auDC_FILTERENV, auENV_FILTER_V3);
AudioConnection          patchCord131(auDC_FILTERENV, auENV_FILTER_V4);
AudioConnection          patchCord132(auMIXER_PRESHAPE_V3, auAMP_SHAPER_PREAMP_V3);
AudioConnection          patchCord133(auMIXER_PRESHAPE_V3, 0, auMIXER_SHAPER_BYPASS_V3, 0);
AudioConnection          patchCord134(auMIXER_PRESHAPE_V2, auAMP_SHAPER_PREAMP_V2);
AudioConnection          patchCord135(auMIXER_PRESHAPE_V2, 0, auMIXER_SHAPER_BYPASS_V2, 0);
AudioConnection          patchCord136(auMIXER_PRESHAPE_V4, auAMP_SHAPER_PREAMP_V4);
AudioConnection          patchCord137(auMIXER_PRESHAPE_V4, 0, auMIXER_SHAPER_BYPASS_V4, 0);
AudioConnection          patchCord138(auMIXER_PRESHAPE_V1, auAMP_SHAPER_PREAMP_V1);
AudioConnection          patchCord139(auMIXER_PRESHAPE_V1, 0, auMIXER_SHAPER_BYPASS_V1, 0);
AudioConnection          patchCord140(auENV_FILTER_V1, 0, auMIXER_FILTERMOD_V1, 0);
AudioConnection          patchCord141(auENV_FILTER_V2, 0, auMIXER_FILTERMOD_V2, 0);
AudioConnection          patchCord142(auENV_FILTER_V3, 0, auMIXER_FILTERMOD_V3, 0);
AudioConnection          patchCord143(auENV_FILTER_V4, 0, auMIXER_FILTERMOD_V4, 0);
AudioConnection          patchCord144(auLFO_FILTER, 0, auMIXER_FILTERMOD_V1, 1);
AudioConnection          patchCord145(auLFO_FILTER, 0, auMIXER_FILTERMOD_V2, 1);
AudioConnection          patchCord146(auLFO_FILTER, 0, auMIXER_FILTERMOD_V3, 1);
AudioConnection          patchCord147(auLFO_FILTER, 0, auMIXER_FILTERMOD_V4, 1);
AudioConnection          patchCord148(auAMP_SHAPER_PREAMP_V4, auSHAPER_V4);
AudioConnection          patchCord149(auAMP_SHAPER_PREAMP_V3, auSHAPER_V3);
AudioConnection          patchCord150(auAMP_SHAPER_PREAMP_V1, auSHAPER_V1);
AudioConnection          patchCord151(auMIXER_SHAPER_BYPASS_V4, 0, auFILTER_SV_V4, 0);
AudioConnection          patchCord152(auMIXER_SHAPER_BYPASS_V4, 0, auFILTER_LADDER_V4, 0);
AudioConnection          patchCord153(auAMP_SHAPER_PREAMP_V2, auSHAPER_V2);
AudioConnection          patchCord154(auMIXER_SHAPER_BYPASS_V1, 0, auFILTER_SV_V1, 0);
AudioConnection          patchCord155(auMIXER_SHAPER_BYPASS_V1, 0, auFILTER_LADDER_V1, 0);
AudioConnection          patchCord156(auMIXER_SHAPER_BYPASS_V3, 0, auFILTER_SV_V3, 0);
AudioConnection          patchCord157(auMIXER_SHAPER_BYPASS_V3, 0, auFILTER_LADDER_V3, 0);
AudioConnection          patchCord158(auMIXER_SHAPER_BYPASS_V2, 0, auFILTER_SV_V2, 0);
AudioConnection          patchCord159(auMIXER_SHAPER_BYPASS_V2, 0, auFILTER_LADDER_V2, 0);
AudioConnection          patchCord160(auSHAPER_V2, 0, auMIXER_SHAPER_BYPASS_V2, 1);
AudioConnection          patchCord161(auSHAPER_V4, 0, auMIXER_SHAPER_BYPASS_V4, 1);
AudioConnection          patchCord162(auSHAPER_V3, 0, auMIXER_SHAPER_BYPASS_V3, 1);
AudioConnection          patchCord163(auSHAPER_V1, 0, auMIXER_SHAPER_BYPASS_V1, 1);
AudioConnection          patchCord164(auMIXER_FILTERMOD_V1, 0, auFILTER_SV_V1, 1);
AudioConnection          patchCord165(auMIXER_FILTERMOD_V1, 0, auFILTER_LADDER_V1, 1);
AudioConnection          patchCord166(auMIXER_FILTERMOD_V2, 0, auFILTER_SV_V2, 1);
AudioConnection          patchCord167(auMIXER_FILTERMOD_V2, 0, auFILTER_LADDER_V2, 1);
AudioConnection          patchCord168(auMIXER_FILTERMOD_V3, 0, auFILTER_SV_V3, 1);
AudioConnection          patchCord169(auMIXER_FILTERMOD_V3, 0, auFILTER_LADDER_V3, 1);
AudioConnection          patchCord170(auMIXER_FILTERMOD_V4, 0, auFILTER_SV_V4, 1);
AudioConnection          patchCord171(auMIXER_FILTERMOD_V4, 0, auFILTER_LADDER_V4, 1);
AudioConnection          patchCord172(auFILTER_SV_V2, 0, auMIXER_FILTER_BLOCK_V2, 0);
AudioConnection          patchCord173(auFILTER_SV_V2, 1, auMIXER_FILTER_BLOCK_V2, 1);
AudioConnection          patchCord174(auFILTER_SV_V2, 2, auMIXER_FILTER_BLOCK_V2, 2);
AudioConnection          patchCord175(auFILTER_SV_V1, 0, auMIXER_FILTER_BLOCK_V1, 0);
AudioConnection          patchCord176(auFILTER_SV_V1, 1, auMIXER_FILTER_BLOCK_V1, 1);
AudioConnection          patchCord177(auFILTER_SV_V1, 2, auMIXER_FILTER_BLOCK_V1, 2);
AudioConnection          patchCord178(auFILTER_SV_V4, 0, auMIXER_FILTER_BLOCK_V4, 0);
AudioConnection          patchCord179(auFILTER_SV_V4, 1, auMIXER_FILTER_BLOCK_V4, 1);
AudioConnection          patchCord180(auFILTER_SV_V4, 2, auMIXER_FILTER_BLOCK_V4, 2);
AudioConnection          patchCord181(auFILTER_SV_V3, 0, auMIXER_FILTER_BLOCK_V3, 0);
AudioConnection          patchCord182(auFILTER_SV_V3, 1, auMIXER_FILTER_BLOCK_V3, 1);
AudioConnection          patchCord183(auFILTER_SV_V3, 2, auMIXER_FILTER_BLOCK_V3, 2);
AudioConnection          patchCord184(auFILTER_LADDER_V2, 0, auMIXER_FILTER_BLOCK_V2, 3);
AudioConnection          patchCord185(auFILTER_LADDER_V1, 0, auMIXER_FILTER_BLOCK_V1, 3);
AudioConnection          patchCord186(auFILTER_LADDER_V3, 0, auMIXER_FILTER_BLOCK_V3, 3);
AudioConnection          patchCord187(auFILTER_LADDER_V4, 0, auMIXER_FILTER_BLOCK_V4, 3);
AudioConnection          patchCord188(auDC_AMPENV, auENV_AMP_V1);
AudioConnection          patchCord189(auDC_AMPENV, auENV_AMP_V2);
AudioConnection          patchCord190(auDC_AMPENV, auENV_AMP_V3);
AudioConnection          patchCord191(auDC_AMPENV, auENV_AMP_V4);
AudioConnection          patchCord192(auENV_AMP_V1, 0, _auMIXER_AMPMOD_V1, 0);
AudioConnection          patchCord193(auENV_AMP_V2, 0, _auMIXER_AMPMOD_V2, 0);
AudioConnection          patchCord194(auENV_AMP_V3, 0, _auMIXER_AMPMOD_V3, 0);
AudioConnection          patchCord195(auENV_AMP_V4, 0, _auMIXER_AMPMOD_V4, 0);
AudioConnection          patchCord196(auLFO_AMP, 0, _auMIXER_AMPMOD_V1, 1);
AudioConnection          patchCord197(auLFO_AMP, 0, _auMIXER_AMPMOD_V2, 1);
AudioConnection          patchCord198(auLFO_AMP, 0, _auMIXER_AMPMOD_V3, 1);
AudioConnection          patchCord199(auLFO_AMP, 0, _auMIXER_AMPMOD_V4, 1);
AudioConnection          patchCord200(auMIXER_FILTER_BLOCK_V2, auAMP_POST_FILTER_V2);
AudioConnection          patchCord201(auMIXER_FILTER_BLOCK_V3, auAMP_POST_FILTER_V3);
AudioConnection          patchCord202(auMIXER_FILTER_BLOCK_V4, auAMP_POST_FILTER_V4);
AudioConnection          patchCord203(auMIXER_FILTER_BLOCK_V1, auAMP_POST_FILTER_V1);
AudioConnection          patchCord204(auMIXER_FINAL_R, auAMP_MASTER_GAIN_R);
AudioConnection          patchCord205(auMIXER_FINAL_L, auAMP_MASTER_GAIN_L);
AudioConnection          patchCord206(_auMIXER_AMPMOD_V1, 0, auMULT_AENV_POST_V1, 1);
AudioConnection          patchCord207(_auMIXER_AMPMOD_V1, 0, auMIXER_AMPMOD_TOTAL, 0);
AudioConnection          patchCord208(_auMIXER_AMPMOD_V2, 0, auMULT_AENV_POST_V2, 1);
AudioConnection          patchCord209(_auMIXER_AMPMOD_V2, 0, auMIXER_AMPMOD_TOTAL, 1);
AudioConnection          patchCord210(_auMIXER_AMPMOD_V3, 0, auMULT_AENV_POST_V3, 1);
AudioConnection          patchCord211(_auMIXER_AMPMOD_V3, 0, auMIXER_AMPMOD_TOTAL, 2);
AudioConnection          patchCord212(_auMIXER_AMPMOD_V4, 0, auMULT_AENV_POST_V4, 1);
AudioConnection          patchCord213(_auMIXER_AMPMOD_V4, 0, auMIXER_AMPMOD_TOTAL, 3);
AudioConnection          patchCord214(auAMP_POST_FILTER_V3, 0, auMULT_AENV_POST_V3, 0);
AudioConnection          patchCord215(auAMP_POST_FILTER_V4, 0, auMULT_AENV_POST_V4, 0);
AudioConnection          patchCord216(auAMP_POST_FILTER_V1, 0, auMULT_AENV_POST_V1, 0);
AudioConnection          patchCord217(auAMP_POST_FILTER_V2, 0, auMULT_AENV_POST_V2, 0);
AudioConnection          patchCord218(auAMP_MASTER_GAIN_L, auPEAK_L);
AudioConnection          patchCord219(auAMP_MASTER_GAIN_L, 0, auSTEREO_OUT, 0);
AudioConnection          patchCord220(auAMP_MASTER_GAIN_L, 0, auMIXER_SCOPE, 0);
AudioConnection          patchCord221(auAMP_MASTER_GAIN_R, 0, auSTEREO_OUT, 1);
AudioConnection          patchCord222(auAMP_MASTER_GAIN_R, auPEAK_R);
AudioConnection          patchCord223(auAMP_MASTER_GAIN_R, 0, auMIXER_SCOPE, 1);
AudioConnection          patchCord224(auMIXER_AMPMOD_TOTAL, auPEAK_AMPMOD_TOTAL);
AudioConnection          patchCord225(auMULT_AENV_POST_V2, 0, auMIXER_FINAL_L, 1);
AudioConnection          patchCord226(auMULT_AENV_POST_V2, 0, auMIXER_FINAL_R, 1);
AudioConnection          patchCord227(auMULT_AENV_POST_V2, 0, auMixer_AM_POST, 1);
AudioConnection          patchCord228(auMULT_AENV_POST_V3, 0, auMIXER_FINAL_L, 2);
AudioConnection          patchCord229(auMULT_AENV_POST_V3, 0, auMIXER_FINAL_R, 2);
AudioConnection          patchCord230(auMULT_AENV_POST_V3, 0, auMixer_AM_POST, 2);
AudioConnection          patchCord231(auMULT_AENV_POST_V4, 0, auMIXER_FINAL_R, 3);
AudioConnection          patchCord232(auMULT_AENV_POST_V4, 0, auMIXER_FINAL_L, 3);
AudioConnection          patchCord233(auMULT_AENV_POST_V4, 0, auMixer_AM_POST, 3);
AudioConnection          patchCord234(auMULT_AENV_POST_V1, 0, auMIXER_FINAL_L, 0);
AudioConnection          patchCord235(auMULT_AENV_POST_V1, 0, auMIXER_FINAL_R, 0);
AudioConnection          patchCord236(auMULT_AENV_POST_V1, 0, auMixer_AM_POST, 0);
AudioConnection          patchCord237(auMixer_AM_POST, auPEAK_AM_POST);
// GUItool: end automatically generated code
