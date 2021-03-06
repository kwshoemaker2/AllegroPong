#pragma once
#include <allegro5/allegro.h>
#include "AllegroPong.h"
#include "IEventSource.h"

namespace Pong {
    ////////////////////////////////////////////////////////////////////////////
    class AllegroEventQueue
    {
    public:
        ////////////////////////////////////////////////////////////////////////
        AllegroEventQueue() = default;

        ////////////////////////////////////////////////////////////////////////
        ~AllegroEventQueue();

        ////////////////////////////////////////////////////////////////////////
        bool Create();

        ////////////////////////////////////////////////////////////////////////
        bool Destroy();

        ////////////////////////////////////////////////////////////////////////
        bool Wait(ALLEGRO_EVENT* evt);

        bool IsEmpty() const;

        ////////////////////////////////////////////////////////////////////////
        bool RegisterEventSource(const IEventSource& eventSource);

    private:
        ALLEGRO_EVENT_QUEUE* mEventQueue = nullptr;
    };
}

