#pragma once
#include "ParmKeys.h"

enum ItemType 
{
    TCollectionLiteItem,
    TLXParameter,
    TLXModule,
    TLXEnvModulatorBank,
    TLXFilterBank,
    TLXPulseWidthMod,
    TLXCrossModulation,
    TLXRingModulation,
    TLXNoiseGen,
    TLXPartMixer,
    TLXWaveShaper,
    TLXOscillator,
    TLXVoiceMixer,

    TLXController,
    TLXPotentiometer,
    TLXButton,
    TLXRotary,

    TLXView,
    TLXOverview
};

const char *ItemTypeToName(ItemType type)
{
    switch (type)
    {
    case ItemType::TCollectionLiteItem: return "CollectionItem";
    case ItemType::TLXParameter: return "LXParameter";
    case ItemType::TLXModule: return "LXModule";
    case ItemType::TLXEnvModulatorBank : return "LXEnvModulatorBank";
    case ItemType::TLXFilterBank : return "LXFilterBank";
    case ItemType::TLXPulseWidthMod : return "LXPulseWidthMod";
    case ItemType::TLXCrossModulation : return "LXCrossModulation";
    case ItemType::TLXRingModulation : return "LXRingModulation";
    case ItemType::TLXNoiseGen : return "LXNoiseGen";
    case ItemType::TLXPartMixer : return "LXPartMixer";
    case ItemType::TLXWaveShaper : return "LXWaveShaper";
    case ItemType::TLXOscillator : return "LXOscillator";
    case ItemType::TLXVoiceMixer : return "LXVoiceMixer";
    case ItemType::TLXController : return "LXController";
    case ItemType::TLXPotentiometer : return "LXPotentiometer";
    case ItemType::TLXButton : return "LXButton";
    case ItemType::TLXRotary : return "LXRotary";
    case ItemType::TLXView : return "LXView";
    case ItemType::TLXOverview : return "LXOverview";
    default: return "Unknown";
    }
}

template<typename KeyType>
class CollectionLiteItem
{
public:
    KeyType key;
    CollectionLiteItem(KeyType key) : key(key) {}
    virtual ~CollectionLiteItem() {}
    virtual const ItemType getType()  { return ItemType::TCollectionLiteItem; }
     bool isType(ItemType type) { return type == getType(); }
     const char *typeName() { return ItemTypeToName(getType()); }    
     virtual void update() { }    
    //virtual void serialize(PS::StringBuilder *sb) {}
};