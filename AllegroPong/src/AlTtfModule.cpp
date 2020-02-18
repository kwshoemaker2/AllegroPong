#include <allegro5/allegro_ttf.h>
#include "AlTtfModule.h"

namespace Pong {

AlTtfModule::~AlTtfModule()
{
    Destroy();
}

bool AlTtfModule::Init()
{
    bool retval = true;
    if (!IsInitialized())
    {
        retval = al_init_ttf_addon();
        mInitialized = retval;
    }
    return retval;
}

bool AlTtfModule::Destroy()
{
    if (IsInitialized())
    {
        al_shutdown_ttf_addon();
    }
    return true;
}

}
