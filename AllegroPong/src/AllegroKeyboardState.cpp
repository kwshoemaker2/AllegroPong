#include "AllegroKeyboardState.h"

using namespace Pong;

namespace Pong {

////////////////////////////////////////////////////////////////////////////////
bool AllegroKeyboardState::Refresh()
{
    mKeyboardState = { 0 };
    al_get_keyboard_state(&mKeyboardState);
    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroKeyboardState::KeyIsDown(INT32 allegroKeyCode) const
{
    return al_key_down(&mKeyboardState, allegroKeyCode);
}

}
