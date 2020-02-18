#include "AllegroDisplay.h"

namespace Pong {

////////////////////////////////////////////////////////////////////////////////
AllegroDisplay::~AllegroDisplay()
{
    Close();
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroDisplay::Create(INT32 width, INT32 height)
{
    if (mAllegroDisplay == nullptr)
    {
        mAllegroDisplay = al_create_display(width, height);
    }

    return (mAllegroDisplay != nullptr);
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroDisplay::Update()
{
    al_flip_display();
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroDisplay::SetColor(INT32 r, INT32 g, INT32 b)
{
    al_clear_to_color(al_map_rgb(r, g, b));
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroDisplay::SetColorA(INT32 r, INT32 g, INT32 b, INT32 a)
{
    al_clear_to_color(al_map_rgba(r, g, b, a));
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroDisplay::SetColor(FLOAT32 r, FLOAT32 g, FLOAT32 b)
{
    al_clear_to_color(al_map_rgb_f(r, g, b));
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroDisplay::SetColorA(FLOAT32 r, FLOAT32 g, FLOAT32 b, FLOAT32 a)
{
    al_clear_to_color(al_map_rgba_f(r, g, b, a));
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroDisplay::Close()
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

////////////////////////////////////////////////////////////////////////////////
INT32 AllegroDisplay::GetWidth() const
{
    return al_get_display_width(mAllegroDisplay);
}

////////////////////////////////////////////////////////////////////////////////
INT32 AllegroDisplay::GetHeight() const
{
    return al_get_display_height(mAllegroDisplay);
}

////////////////////////////////////////////////////////////////////////////////
EventSource* AllegroDisplay::GetEventSource() const
{
    return al_get_display_event_source(mAllegroDisplay);
}

}
