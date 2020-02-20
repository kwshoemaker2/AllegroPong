#pragma once

#include <allegro5/allegro_primitives.h>
#include "AllegroPong.h"

namespace Pong {

    class AlPrimitivesModule
    {
    public:
        AlPrimitivesModule() = default;
        ~AlPrimitivesModule();

        bool Init();
        bool IsInitialized() const;
        bool Destroy();
    private:
        bool mInitialized = false;
    };
}



