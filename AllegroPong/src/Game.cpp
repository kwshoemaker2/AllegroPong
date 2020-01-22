#include <iostream>
#include "Game.h"

const std::string Pong::Game::sImagePath = "image.png";
const FLOAT64 Pong::Game::sFps = 60.0;

////////////////////////////////////////////////////////////////////////////////
bool Pong::Game::Init()
{
    if (!mInitialized && !mRunning)
    {
        const bool mainModuleInit = mMainModule.Create();
        if (mainModuleInit == false)
        {
            std::cerr << "Could not initialize main module" << std::endl;
            return false;
        }

        const bool imageAddonInit = al_init_image_addon();
        if (imageAddonInit == false)
        {
            std::cerr << "Could not intialize image addon" << std::endl;
            return false;
        }

        const bool displayCreated = mDisplay.Create(sDisplayWidth, sDisplayHeight);
        if(displayCreated == false)
        {
            std::cerr << "Could not create display" << std::endl;
        }

        mEventQueue.Create();

        mKeyboard.Create();

        mTimer.Create(1.0 / sFps);

        mMouse.Create();

        mEventQueue.RegisterEventSource(mKeyboard);
        mEventQueue.RegisterEventSource(mDisplay);
        mEventQueue.RegisterEventSource(mMouse);
        mEventQueue.RegisterEventSource(mTimer);

        mUserIcon.Bitmap.Load(sImagePath.c_str());
        mCpuIcon.Bitmap.Load(sImagePath.c_str());

        mInitialized = true;
    }

    return mInitialized;
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::Game::Run()
{
    bool success = false;
    if (mInitialized)
    {
        success = GameLoop();
    }
    return success;
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::Game::GameLoop()
{
    mRunning = true;

    mTimer.Start();

    bool redraw = false;

    while (mRunning)
    {
        ALLEGRO_EVENT event;

        mEventQueue.Wait(&event);
        switch (event.type)
        {
            case ALLEGRO_EVENT_TIMER:
            {
                HandleUserMovement(mUserIcon.X, mUserIcon.Y);
                HandleCpuMovement(mCpuIcon.X, mCpuIcon.Y);
                redraw = true;
                break;
            }
            case ALLEGRO_EVENT_KEY_DOWN:
            {
                mKeyPressHandler.KeyDown(event.keyboard.keycode);
                break;
            }
            case ALLEGRO_EVENT_KEY_UP:
            {
                mKeyPressHandler.KeyUp(event.keyboard.keycode);
                break;
            }
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
            {
                mRunning = false;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:
            {
                mUserIcon.X = event.mouse.x;
                mUserIcon.Y = event.mouse.y;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            {
                mUserIcon.X = mUserIcon.Y = 0;
                mMouse.SetXY(mDisplay, 0, 0);
                break;
            }
            default:
            {
                break;
            }
        }

        if (redraw && mEventQueue.IsEmpty())
        {
            mDisplay.SetColor(0, 0, 0);
            mUserIcon.Draw();
            mCpuIcon.Draw();
            mDisplay.Update();
            redraw = false;
        }
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
void Pong::Game::HandleUserMovement(FLOAT32& x, FLOAT32& y)
{
    if (mKeyPressHandler.KeyWasPressed(ALLEGRO_KEY_RIGHT))
    {
        x++;
    }
    if (mKeyPressHandler.KeyWasPressed(ALLEGRO_KEY_LEFT))
    {
        x--;
    }
    if (mKeyPressHandler.KeyWasPressed(ALLEGRO_KEY_UP))
    {
        y--;
    }
    if (mKeyPressHandler.KeyWasPressed(ALLEGRO_KEY_DOWN))
    {
        y++;
    }

    mKeyPressHandler.ClearPresses();
}

////////////////////////////////////////////////////////////////////////////////
void Pong::Game::HandleCpuMovement(FLOAT32& x, FLOAT32& y)
{
    static FLOAT32 dx = 2;
    static FLOAT32 dy = -2;

    if (mCpuIcon.DoesCollide(mUserIcon))
    {
        dx = -dx;
        dy = -dy;
    }

    const auto farX = mCpuIcon.Width() + x;
    if (farX >= mDisplay.GetWidth())
    {
        dx = -dx;
    }
    else if (x < 0)
    {
        dx = -dx;
    }
    x += dx;

    const auto farY = mCpuIcon.Height() + y;
    if (farY >= mDisplay.GetHeight())
    {
        dy = -dy;
    }
    else if (y < 0)
    {
        dy = -dy;
    }
    y += dy;

}

////////////////////////////////////////////////////////////////////////////////
void Pong::GameIcon::Draw()
{
    Bitmap.Draw(X, Y, 0);
}

////////////////////////////////////////////////////////////////////////////////
bool Pong::GameIcon::DoesCollide(const GameIcon& other) const
{
    // AABB - AABB collision
    // Collision x-axis?
    const bool collisionX = ((this->X + this->Width()) >= other.X) &&
        ((other.X + other.Width()) >= this->X);
    // Collision y-axis?
    const bool collisionY = ((this->Y + this->Height()) >= other.Y) &&
        ((other.Y + other.Height()) >= this->Y);
    // Collision only if on both axes
    return collisionX && collisionY;
}

////////////////////////////////////////////////////////////////////////////////
FLOAT32 Pong::GameIcon::Height() const
{
    return static_cast<FLOAT32>(Bitmap.GetHeight());
}

////////////////////////////////////////////////////////////////////////////////
FLOAT32 Pong::GameIcon::Width() const
{
    return static_cast<FLOAT32>(Bitmap.GetWidth());
}
