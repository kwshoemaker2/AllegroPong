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
        mCoords.Y -= sSpeed;
    }
    if (mKeyPressHandler.KeyWasPressed(ALLEGRO_KEY_DOWN))
    {
        mCoords.Y += sSpeed;
    }
}

////////////////////////////////////////////////////////////////////////////////
void Pong::Player::DoMouseEvent(const AllegroMouseEvent& mouseEvent)
{
    mCoords.Y = static_cast<FLOAT32>(mouseEvent.GetMouseY());
}

////////////////////////////////////////////////////////////////////////////////
void Pong::Player::HandleCollisionWithDisplay(const AllegroDisplay& display)
{
    const auto lowerHeight = display.GetHeight() - Height();
    if (mCoords.Y < 0)
    {
        mCoords.Y = 0;
    }
    else if (mCoords.Y > lowerHeight)
    {
        mCoords.Y = lowerHeight;
    }
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::Opponent::Init()
{
    bool retval = mBitmap.Load(sBitmapPath);
    if (retval)
    {
        mCoords.X = 640.0F - 50.0F;
        mCoords.X -= Width();
    }

    return retval;
}

////////////////////////////////////////////////////////////////////////////////
void Pong::Opponent::Move()
{
    mCoords.Y += mDy;
}

void Pong::Opponent::HandleCollisionWithDisplay(const AllegroDisplay& display)
{
    const auto lowerHeight = display.GetHeight() - Height();
    if (mCoords.Y < 0)
    {
        mCoords.Y = 0;
        mDy = -mDy;
    }
    else if (mCoords.Y > lowerHeight)
    {
        mCoords.Y = lowerHeight;
        mDy = -mDy;
    }
}
