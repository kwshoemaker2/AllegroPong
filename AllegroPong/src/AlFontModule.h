#pragma once

#include <allegro5/allegro_font.h>
#include "AllegroPong.h"

class AlFontModule
{
public:
    AlFontModule() = default;

    ~AlFontModule();

    bool Init();
    bool IsInitialized() const;
    bool Destroy();
private:
    bool mInitialized = false;
};

