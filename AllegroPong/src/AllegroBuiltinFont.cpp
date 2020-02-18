#include "AllegroBuiltinFont.h"

namespace Pong {
    AllegroBuiltinFont::~AllegroBuiltinFont()
    {
        Destroy();
    }

    bool AllegroBuiltinFont::Create()
    {
        bool retval = true;
        if (!Created())
        {
            mFont = al_create_builtin_font();
            retval = (mFont != nullptr);
        }
        return retval;
    }

    bool AllegroBuiltinFont::Destroy()
    {
        if (Created())
        {
            al_destroy_font(mFont);
            mFont = nullptr;
        }
        return true;
    }

}
