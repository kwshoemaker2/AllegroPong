#include "KeyPressHandler.h"

#define KEY_SEEN (1 << 0)
#define KEY_RELEASED (1 << 1)

namespace Pong {

////////////////////////////////////////////////////////////////////////////////
bool KeyPressHandler::KeyWasPressed(INT32 keyCode) const
{
    return (mKeyPresses[keyCode] != 0);
}

////////////////////////////////////////////////////////////////////////////////
void KeyPressHandler::ClearPresses()
{
    for (auto& keyPress : mKeyPresses)
    {
        keyPress &= KEY_SEEN;
    }
}

////////////////////////////////////////////////////////////////////////////////
void KeyPressHandler::KeyDown(INT32 keyCode)
{
    mKeyPresses[keyCode] = KEY_SEEN | KEY_RELEASED;
}

////////////////////////////////////////////////////////////////////////////////
void KeyPressHandler::KeyUp(INT32 keyCode)
{
    mKeyPresses[keyCode] &= KEY_RELEASED;
}

}
