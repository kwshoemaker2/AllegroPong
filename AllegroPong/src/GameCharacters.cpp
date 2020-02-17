#include "GameCharacters.h"

////////////////////////////////////////////////////////////////////////////////
void Pong::Character::Draw()
{
    mBitmap.Draw(mCoords.X, mCoords.Y, 0);
}

////////////////////////////////////////////////////////////////////////////////
FLOAT32 Pong::Character::GetHeight() const
{
    return static_cast<FLOAT32>(mBitmap.GetHeight());
}

////////////////////////////////////////////////////////////////////////////////
FLOAT32 Pong::Character::GetWidth() const
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
    const auto lowerHeight = display.GetHeight() - GetHeight();
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
void Pong::Player::HandleCollisionWithCharacter(const Character& character)
{
    const bool collidesX = ((GetX() + GetWidth()) >= character.GetX()) &&
        ((character.GetX() + character.GetWidth()) >= GetX());

    const bool collidesY = ((GetY() + GetHeight()) >= character.GetY()) &&
        ((character.GetY() + character.GetHeight()) >= GetY());

    if (collidesX && collidesY)
    {
        mCoords.Y -= sSpeed;
    }
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::Opponent::Init()
{
    bool retval = mBitmap.Load(sBitmapPath);
    if (retval)
    {
        mCoords.X = 640.0F - 50.0F;
        mCoords.X -= GetWidth();
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
    const auto lowerHeight = display.GetHeight() - GetHeight();
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

Pong::Ball::Ball(FLOAT32 displayWidth, FLOAT32 displayHeight)
    :mInitX((displayWidth / 2.0F)),
     mInitY((displayHeight / 2.0F))
{
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::Ball::Init()
{
    bool retval = mBitmap.Load(sBitmapPath);
    if (retval)
    {
        MoveToInitCoords();
    }

    return retval;
}

////////////////////////////////////////////////////////////////////////////////
void Pong::Ball::Move()
{
    mCoords.X += mDx;
    mCoords.Y += mDy;
}

////////////////////////////////////////////////////////////////////////////////
void Pong::Ball::HandleCollisionWithDisplay(const AllegroDisplay& display)
{
    const auto lowerHeight = display.GetHeight() - GetHeight();
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

////////////////////////////////////////////////////////////////////////////////
void Pong::Ball::HandleCollisionWithCharacter(const Character& character)
{
    const bool collidesX = ((GetX() + GetWidth()) >= character.GetX()) &&
                           ((character.GetX() + character.GetWidth()) >= GetX());

    const bool collidesY = ((GetY() + GetHeight()) >= character.GetY()) &&
                           ((character.GetY() + character.GetHeight()) >= GetY());

    if (collidesX && collidesY)
    {
        mDx = -mDx;
        mCoords.X += mDx;
        mDy = -mDy;
        mCoords.Y += mDy;
    }
    else if (collidesX)
    {
        mDx = -mDx;
        mDy = -mDy;

        MoveToInitCoords();
    }
}

////////////////////////////////////////////////////////////////////////////////
void Pong::Ball::MoveToInitCoords()
{
    mCoords.X = mInitX - GetWidth();
    mCoords.Y = mInitY - GetHeight();
}
