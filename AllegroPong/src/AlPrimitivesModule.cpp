#include "AlPrimitivesModule.h"

namespace Pong {

////////////////////////////////////////////////////////////////////////////////
AlPrimitivesModule::~AlPrimitivesModule()
{
    Destroy();
}

////////////////////////////////////////////////////////////////////////////////
bool AlPrimitivesModule::Init()
{
    bool retval = true;
    if (!IsInitialized())
    {
        retval = al_init_primitives_addon();
        mInitialized = retval;
    }
    return retval;
}

////////////////////////////////////////////////////////////////////////////////
bool AlPrimitivesModule::IsInitialized() const
{
    return mInitialized;
}

////////////////////////////////////////////////////////////////////////////////
bool AlPrimitivesModule::Destroy()
{
    if (IsInitialized())
    {
        al_shutdown_primitives_addon();
    }
    return true;
}

}