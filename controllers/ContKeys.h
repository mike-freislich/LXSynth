#pragma once

enum ContKeys
{
    // Board 1: envelope board
    b1_Fader1,
    b1_Fader2,
    b1_Fader3,
    b1_Fader4,
    b1_Pot1,
    b1_Pot2,
    b1_Pot3,

    // Board 2: display board
    potDataA,
    potDataB,
    potDataC,
    potDataD,
    rotA,
    btnRotA,
    
    btnShift,
    btnCtrl,
    btnEnter
};

FLASHMEM const char * contKey_cstr(ContKeys key)
{
    switch (key)
    {
    case b1_Fader1: return "b1_Fader1"; 
    case b1_Fader2: return "b1_Fader2";
    case b1_Fader3: return "b1_Fader3";
    case b1_Fader4: return "b1_Fader4";    
    case b1_Pot1: return "b1_Pot1";
    case b1_Pot2: return "b1_Pot2";
    case b1_Pot3: return "b1_Pot3";
    case potDataA: return "potDataA";
    case potDataB: return "potDataB";
    case potDataC: return "potDataC";
    case potDataD: return "potDataD";
    case rotA: return "rotA";

    case btnRotA: return "btnRotA";
    case btnShift: return "btnShift";
    case btnCtrl: return "btnCtrl";
    case btnEnter: return "btnEnter";
    default: return "unknown";
    }
}