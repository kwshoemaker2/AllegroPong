#include <allegro5/allegro_ttf.h>
#include "AllegroTtfFont.h"

namespace Pong {
    AllegroTtfFont::~AllegroTtfFont()
    {
        Destroy();
    }

    bool AllegroTtfFont::Create(const CHAR* fontFile, UINT16 size)
    {
        bool retval = true;
        if (!Created())
        {
            mFont = al_load_ttf_font(fontFile, size, 0);
            retval = (mFont != nullptr);
        }
        return retval;
    }

    bool AllegroTtfFont::Destroy()
    {
        if (Created())
        {
            al_destroy_font(mFont);
            mFont = nullptr;
        }
        return true;
    }

}
