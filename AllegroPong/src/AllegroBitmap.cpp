#include "AllegroBitmap.h"

using namespace Pong;

////////////////////////////////////////////////////////////////////////////////
AllegroBitmap::~AllegroBitmap()
{
    Destroy();
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroBitmap::Load(const CHAR* path)
{
    if (mBitmap == nullptr)
    {
        mBitmap = al_load_bitmap("image.png");
        return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroBitmap::Destroy()
{
    if (mBitmap != nullptr)
    {
        al_destroy_bitmap(mBitmap);
        mBitmap = nullptr;
        return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::AllegroBitmap::Draw(FLOAT32 dx, FLOAT32 dy, INT32 flags)
{
    al_draw_bitmap(mBitmap, dx, dy, 0);
    return true;
}

////////////////////////////////////////////////////////////////////////////////
INT32 Pong::AllegroBitmap::GetWidth() const
{
    return al_get_bitmap_width(mBitmap);
}

////////////////////////////////////////////////////////////////////////////////
INT32 Pong::AllegroBitmap::GetHeight() const
{
    return al_get_bitmap_height(mBitmap);
}
