#include "AllegroEventQueue.h"

using namespace Pong;

////////////////////////////////////////////////////////////////////////////////
AllegroEventQueue::~AllegroEventQueue()
{
    Destroy();
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroEventQueue::Create()
{
    if (mEventQueue == nullptr)
    {
        mEventQueue = al_create_event_queue();
        return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroEventQueue::Destroy()
{
    if (mEventQueue != nullptr)
    {
        al_destroy_event_queue(mEventQueue);
        mEventQueue = nullptr;
        return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroEventQueue::Wait(ALLEGRO_EVENT* evt)
{
    if (mEventQueue != nullptr)
    {
        al_wait_for_event(mEventQueue, evt);
        return true;
    }
    return false;
}

bool Pong::AllegroEventQueue::IsEmpty() const
{
    return al_is_event_queue_empty(mEventQueue);
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroEventQueue::RegisterEventSource(const IEventSource& eventSource)
{
    if (mEventQueue != nullptr)
    {
        al_register_event_source(mEventQueue, eventSource.GetEventSource());
        return true;
    }
    return false;
}
