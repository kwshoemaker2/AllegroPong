#pragma once
#include <allegro5/allegro.h>
#include "AllegroPong.h"

namespace Pong {
    class AllegroMouseEvent
    {
    public:
        AllegroMouseEvent(const ALLEGRO_EVENT& evt)
            :mEvent(evt)
        {
        }

        INT32 GetMouseX() const { return mEvent.mouse.x; }
        INT32 GetMouseY() const { return mEvent.mouse.y; }

    private:
        const ALLEGRO_EVENT& mEvent;
    };
}
