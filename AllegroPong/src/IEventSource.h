#pragma once

#include <allegro5/allegro.h>

namespace Pong {
    using EventSource = ALLEGRO_EVENT_SOURCE;

    ////////////////////////////////////////////////////////////////////////////
    class IEventSource
    {
    public:
        ////////////////////////////////////////////////////////////////////////
        virtual EventSource* GetEventSource() const = 0;
    };
}

