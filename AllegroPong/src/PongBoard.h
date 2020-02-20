#pragma once

#include "AllegroPong.h"

namespace Pong {

class PongBoard
{
public:
    PongBoard() = delete;

    PongBoard(FLOAT32 displayWidth, FLOAT32 displayHeight);

    ~PongBoard() = default;

    void Draw();

private:
    const FLOAT32 mDisplayWidth;
    const FLOAT32 mHalfDisplayWidth;
    const FLOAT32 mDisplayHeight;
};


}
