#include <allegro5/allegro_font.h>
#include "AlFontModule.h"

AlFontModule::~AlFontModule()
{
    if (IsInitialized())
    {
        Destroy();
    }
}

bool AlFontModule::Init()
{
    bool retval = true;
    if (!IsInitialized())
    {
        retval = al_init_font_addon();
        mInitialized = retval;
    }
    return retval;
}

bool AlFontModule::IsInitialized() const
{
    return mInitialized;
}

bool AlFontModule::Destroy()
{
    if (IsInitialized())
    {
        al_shutdown_font_addon();
    }
    return true;
}
