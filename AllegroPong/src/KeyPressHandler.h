#pragma once
#include <array>
#include <allegro5/allegro.h>
#include "AllegroPong.h"

namespace Pong {
    class KeyPressHandler
    {
    public:
        KeyPressHandler() = default;

        ~KeyPressHandler() = default;

        bool KeyWasPressed(INT32 keyCode) const;

        void ClearPresses();

        void KeyDown(INT32 keyCode);

        void KeyUp(INT32 keyCode);

    private:
        std::array<UINT8, ALLEGRO_KEY_MAX> mKeyPresses = { 0 };
    };
}
