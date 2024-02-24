#pragma once

enum ViewKeys {
    overview
};

FLASHMEM const char *viewKeyToString(ViewKeys key)
{
    switch (key)
    {
        case overview: return "overview";
        default:
            return "unknown";
    }
};