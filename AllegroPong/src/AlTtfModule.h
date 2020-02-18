#pragma once

#include "AllegroPong.h"

namespace Pong {

class AlTtfModule
{
public:
    AlTtfModule() = default;
    ~AlTtfModule();

    bool Init();
    bool IsInitialized() const { return mInitialized; }
    bool Destroy();
private:
    bool mInitialized = false;
};

}

