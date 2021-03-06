#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "AllegroPong.h"

namespace Pong {
    ////////////////////////////////////////////////////////////////////////////
    class AllegroBitmap
    {
    public:
        ////////////////////////////////////////////////////////////////////////
        AllegroBitmap() = default;

        ////////////////////////////////////////////////////////////////////////
        ~AllegroBitmap();

        ////////////////////////////////////////////////////////////////////////
        bool Load(const CHAR* path);

        ////////////////////////////////////////////////////////////////////////
        bool Destroy();

        ////////////////////////////////////////////////////////////////////////
        bool Draw(FLOAT32 dx, FLOAT32 dy, INT32 flags);

        ////////////////////////////////////////////////////////////////////////
        INT32 GetWidth() const;

        ////////////////////////////////////////////////////////////////////////
        INT32 GetHeight() const;

    private:
        ALLEGRO_BITMAP* mBitmap = nullptr;
    };
}


