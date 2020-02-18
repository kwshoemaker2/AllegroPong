#pragma once
#include <allegro5/allegro_font.h>
#include "AllegroPong.h"

namespace Pong {
    class AllegroTtfFont
    {
    public:
        AllegroTtfFont() = default;
        ~AllegroTtfFont();

        bool Create(const CHAR* fontFile, UINT16 size);
        bool Created() const { return mFont != nullptr; }
        bool Destroy();

        ALLEGRO_FONT* GetFont() const { return mFont; }
    private:
        ALLEGRO_FONT* mFont = nullptr;
    };
}


