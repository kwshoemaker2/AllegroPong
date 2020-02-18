#pragma once

#include "AllegroPong.h"
#include "AllegroTtfFont.h"

namespace Pong {
    class ScoreBoard
    {
    public:
        ScoreBoard() = delete;
        ScoreBoard(const AllegroTtfFont& font, FLOAT32 drawX, FLOAT32 drawY);

        void Update(UINT32 newScore);
        void Draw();

    private:
        const FLOAT32 mDrawX;
        const FLOAT32 mDrawY;
        UINT32 mDrawScore = 0;
        const AllegroTtfFont& mAllegroFont;
    };
}


