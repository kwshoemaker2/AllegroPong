#include <cstdlib>
#include "GameCharacters.h"

namespace Pong {

////////////////////////////////////////////////////////////////////////////////
void Character::Draw()
{
    mBitmap.Draw(mCoords.X, mCoords.Y, 0);
}

////////////////////////////////////////////////////////////////////////////////
FLOAT32 Character::GetHeight() const
{
    return static_cast<FLOAT32>(mBitmap.GetHeight());
}

////////////////////////////////////////////////////////////////////////////////
FLOAT32 Character::GetWidth() const
{
    return static_cast<FLOAT32>(mBitmap.GetWidth());
}

////////////////////////////////////////////////////////////////////////////////
bool Player::Init()
{
    mCoords.X = 50.0F;
    return mBitmap.Load(sBitmapPath);
}

////////////////////////////////////////////////////////////////////////////////
void Player::Move()
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
void Player::DoMouseEvent(const AllegroMouseEvent& mouseEvent)
{
    mCoords.Y = static_cast<FLOAT32>(mouseEvent.GetMouseY());
}

////////////////////////////////////////////////////////////////////////////////
void Player::HandleCollisionWithDisplay(const AllegroDisplay& display)
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
void Player::HandleCollisionWithCharacter(const Character& character)
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

Opponent::Opponent(const Character& ball)
    :mBall(ball)
{
}

////////////////////////////////////////////////////////////////////////////////
bool Opponent::Init()
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
void Opponent::Move()
{
    if (mBall.GetY() > mCoords.Y)
    {
        // Move up
        mDy = sSpeed;
    }
    else if (mBall.GetY() < mCoords.Y)
    {
        // Move down
        mDy = -sSpeed;
    }

    mCoords.Y += mDy;
}

void Opponent::HandleCollisionWithDisplay(const AllegroDisplay& display)
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

Ball::Ball(FLOAT32 displayWidth, FLOAT32 displayHeight)
    :mInitX((displayWidth / 2.0F)),
     mInitY((displayHeight / 2.0F))
{
}

////////////////////////////////////////////////////////////////////////////////
bool Ball::Init()
{
    bool retval = mBitmap.Load(sBitmapPath);
    if (retval)
    {
        MoveToInitCoords();
    }

    return retval;
}

////////////////////////////////////////////////////////////////////////////////
void Ball::Move()
{
    mCoords.X += mDx;
    mCoords.Y += mDy;
}

////////////////////////////////////////////////////////////////////////////////
void Ball::HandleCollisionWithDisplay(const AllegroDisplay& display)
{
    const auto lowerHeight = display.GetHeight() - GetHeight();
    if (mCoords.Y < 0)
    {
        mCoords.Y = 0;
        mDy = sSpeed;
        mDy += static_cast<FLOAT32>((rand() % 3));
    }
    else if (mCoords.Y > lowerHeight)
    {
        mCoords.Y = lowerHeight;
        mDy = -sSpeed;
        mDy -= static_cast<FLOAT32>((rand() % 3));
    }
}

////////////////////////////////////////////////////////////////////////////////
void Ball::HandleCollisionWithCharacter(const Character& character)
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
}

bool Ball::HandleCharacterMiss(const Character& character)
{
    const bool collidesX = ((GetX() + GetWidth()) >= character.GetX()) &&
        ((character.GetX() + character.GetWidth()) >= GetX());

    const bool collidesY = ((GetY() + GetHeight()) >= character.GetY()) &&
        ((character.GetY() + character.GetHeight()) >= GetY());

    bool retval = false;
    if (!collidesY && collidesX)
    {
        mDx = -mDx;
        mDy = -mDy;

        MoveToInitCoords();
        retval = true;
    }
    return retval;
}

////////////////////////////////////////////////////////////////////////////////
void Ball::MoveToInitCoords()
{
    mCoords.X = mInitX - GetWidth();
    mCoords.Y = mInitY - GetHeight();
}
}

