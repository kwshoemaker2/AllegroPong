#include <string>
#include <allegro5/allegro_font.h>
#include "ScoreBoard.h"

namespace Pong {

////////////////////////////////////////////////////////////////////////////////
ScoreBoard::ScoreBoard(const AllegroTtfFont& font, FLOAT32 drawX, FLOAT32 drawY)
    :mDrawX(drawX),
     mDrawY(drawY),
     mAllegroFont(font)
{
}

////////////////////////////////////////////////////////////////////////////////
void ScoreBoard::Update(UINT32 newScore)
{
    mDrawScore = newScore;
}

////////////////////////////////////////////////////////////////////////////////
void ScoreBoard::Draw()
{
    const auto scoreStr = std::to_string(mDrawScore);
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
    al_draw_text(mAllegroFont.GetFont(), white, mDrawX, mDrawY, 0, scoreStr.c_str());
}

}
