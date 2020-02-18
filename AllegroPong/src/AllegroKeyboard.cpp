#include "AllegroKeyboard.h"
#include <allegro5/allegro.h>

namespace Pong {

////////////////////////////////////////////////////////////////////////////////
AllegroKeyboard::~AllegroKeyboard()
{
    Destroy();
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroKeyboard::Create()
{
    mCreated = al_install_keyboard();
    return mCreated;
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroKeyboard::Destroy()
{
    if (mCreated)
    {
        al_uninstall_keyboard();
        mCreated = false;
        return true;
    }

    return false;
}

EventSource* AllegroKeyboard::GetEventSource() const
{
    return al_get_keyboard_event_source();
}

}
