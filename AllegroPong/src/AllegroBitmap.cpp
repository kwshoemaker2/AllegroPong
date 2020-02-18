#include "AllegroBitmap.h"

namespace Pong {

////////////////////////////////////////////////////////////////////////////////
AllegroBitmap::~AllegroBitmap()
{
    Destroy();
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroBitmap::Load(const CHAR* path)
{
    if (mBitmap == nullptr)
    {
        mBitmap = al_load_bitmap(path);
        return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
bool AllegroBitmap::Destroy()
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
bool AllegroBitmap::Draw(FLOAT32 dx, FLOAT32 dy, INT32 flags)
{
    al_draw_bitmap(mBitmap, dx, dy, 0);
    return true;
}

////////////////////////////////////////////////////////////////////////////////
INT32 AllegroBitmap::GetWidth() const
{
    return al_get_bitmap_width(mBitmap);
}

////////////////////////////////////////////////////////////////////////////////
INT32 AllegroBitmap::GetHeight() const
{
    return al_get_bitmap_height(mBitmap);
}

}
