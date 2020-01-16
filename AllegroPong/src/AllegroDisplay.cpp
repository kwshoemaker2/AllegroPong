#include "AllegroDisplay.h"

using Pong::AllegroDisplay;

////////////////////////////////////////////////////////////////////////////////
AllegroDisplay::~AllegroDisplay()
{
    al_destroy_display(mAllegroDisplay);
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
