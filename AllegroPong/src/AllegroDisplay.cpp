#include "AllegroDisplay.h"

using namespace Pong;

////////////////////////////////////////////////////////////////////////////////
AllegroDisplay::~AllegroDisplay()
{
    Close();
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroDisplay::Create(INT32 width, INT32 height)
{
    if (mAllegroDisplay == nullptr)
    {
        mAllegroDisplay = al_create_display(width, height);
    }

    return (mAllegroDisplay != nullptr);
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroDisplay::Update()
{
    al_flip_display();
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroDisplay::SetColor(INT32 r, INT32 g, INT32 b)
{
    al_clear_to_color(al_map_rgb(r, g, b));
    return true;
}

bool Pong::AllegroDisplay::Close()
{
    bool success = false;
    if (mAllegroDisplay != nullptr)
    {
        al_destroy_display(mAllegroDisplay);
        mAllegroDisplay = nullptr;
        success = true;
    }

    return success;
}

EventSource* AllegroDisplay::GetEventSource() const
{
    return al_get_display_event_source(mAllegroDisplay);
}
