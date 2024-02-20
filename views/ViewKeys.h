#pragma once

enum ViewKeys {
    overview
};

const char *viewKeyToString(ViewKeys key)
{
    switch (key)
    {
        case overview: return "overview";
        default:
            return "unknown";
    }
};