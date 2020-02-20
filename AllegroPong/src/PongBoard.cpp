#include <allegro5/allegro_primitives.h>
#include "PongBoard.h"

namespace Pong {

////////////////////////////////////////////////////////////////////////////////
PongBoard::PongBoard(FLOAT32 displayWidth, FLOAT32 displayHeight)
    :mDisplayWidth(displayWidth),
     mHalfDisplayWidth(displayWidth / 2.0F),
     mDisplayHeight(displayHeight)
{
}

////////////////////////////////////////////////////////////////////////////////
void PongBoard::Draw()
{
    const auto thickness = 5.0F;
    const auto white = al_map_rgb(255, 255, 255);

    al_draw_line(mHalfDisplayWidth, 0.0F,
                 mHalfDisplayWidth, mDisplayHeight,
                 white,
                 thickness);

    al_draw_rectangle(thickness, thickness,
                      (mDisplayWidth - thickness), (mDisplayHeight - thickness),
                      white,
                      thickness);
}

}
