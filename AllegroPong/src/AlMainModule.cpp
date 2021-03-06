#include <allegro5/allegro.h>
#include "AlMainModule.h"

namespace Pong {

////////////////////////////////////////////////////////////////////////////////
AlMainModule::~AlMainModule()
{
    Destroy();
}

////////////////////////////////////////////////////////////////////////////////
bool AlMainModule::Create()
{
    return al_init();
}

////////////////////////////////////////////////////////////////////////////////
bool AlMainModule::IsInitialized() const
{
    return al_is_system_installed();
}

////////////////////////////////////////////////////////////////////////////////
bool AlMainModule::Destroy()
{
    if (IsInitialized())
    {
        al_uninstall_system();
        return true;
    }
    return false;
}

}
