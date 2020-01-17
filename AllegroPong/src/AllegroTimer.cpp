#include "AllegroTimer.h"

using namespace Pong;

////////////////////////////////////////////////////////////////////////////////
AllegroTimer::~AllegroTimer()
{
    Destroy();
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroTimer::Create(FLOAT64 seconds)
{
    if (mAllegroTimer == nullptr)
    {
        mAllegroTimer = al_create_timer(seconds);
    }

    return (mAllegroTimer != nullptr);
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroTimer::Destroy()
{
    if (mAllegroTimer != nullptr)
    {
        Stop();
        al_destroy_timer(mAllegroTimer);
        mAllegroTimer = nullptr;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroTimer::Start()
{
    if (al_get_timer_started(mAllegroTimer) == false)
    {
        al_start_timer(mAllegroTimer);
        return true;
    }

    return false;
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroTimer::Stop()
{
    if (al_get_timer_started(mAllegroTimer))
    {
        al_stop_timer(mAllegroTimer);

        return true;
    }

    return false;
}

////////////////////////////////////////////////////////////////////////////////
EventSource* Pong::AllegroTimer::GetEventSource() const
{
    return al_get_timer_event_source(mAllegroTimer);
}
