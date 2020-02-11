#include "GameCharacters.h"

////////////////////////////////////////////////////////////////////////////////
void Pong::Character::Draw()
{
    mBitmap.Draw(mCoords.X, mCoords.Y, 0);
}

////////////////////////////////////////////////////////////////////////////////
FLOAT32 Pong::Character::Height() const
{
    return static_cast<FLOAT32>(mBitmap.GetHeight());
}

////////////////////////////////////////////////////////////////////////////////
FLOAT32 Pong::Character::Width() const
{
    return static_cast<FLOAT32>(mBitmap.GetWidth());
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::Player::Init()
{
    mCoords.X = 50.0F;
    return mBitmap.Load(sBitmapPath);
}

////////////////////////////////////////////////////////////////////////////////
void Pong::Player::Move()
{
    if (mKeyPressHandler.KeyWasPressed(ALLEGRO_KEY_UP))
    {
        mCoords.Y--;
    }
    if (mKeyPressHandler.KeyWasPressed(ALLEGRO_KEY_DOWN))
    {
        mCoords.Y++;
    }
}

////////////////////////////////////////////////////////////////////////////////
void Pong::Player::DoMouseEvent(const AllegroMouseEvent& mouseEvent)
{
    mCoords.Y = static_cast<FLOAT32>(mouseEvent.GetMouseY());
}
