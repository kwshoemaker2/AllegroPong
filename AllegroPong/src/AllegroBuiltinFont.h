#pragma once
#include <allegro5/allegro_font.h>
#include "AllegroPong.h"

namespace Pong {
    class AllegroBuiltinFont
    {
    public:
        AllegroBuiltinFont() = default;
        ~AllegroBuiltinFont();

        bool Create();
        bool Created() const { return mFont != nullptr; }
        bool Destroy();

        ALLEGRO_FONT* GetFont() const { return mFont; }
    private:
        ALLEGRO_FONT* mFont = nullptr;
    };
}


