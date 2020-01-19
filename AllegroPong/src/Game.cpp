#include "Game.h"

const std::string Pong::Game::sImagePath = "image.png";
const FLOAT64 Pong::Game::sFps = 60.0;

bool Pong::Game::Init()
{
    if (!mInitialized && !mRunning)
    {
        mMainModule.Create();
        al_init_image_addon();

        mDisplay.Create(sDisplayWidth, sDisplayHeight);

        mEventQueue.Create();

        mKeyboard.Create();

        mMouse.Create();

        mEventQueue.RegisterEventSource(mKeyboard);
        mEventQueue.RegisterEventSource(mDisplay);
        mEventQueue.RegisterEventSource(mMouse);

        mBitmap.Load(sImagePath.c_str());

        mTimer.Create(1.0 / sFps);

        mInitialized = true;
    }

    return mInitialized;
}

bool Pong::Game::Run()
{
    bool success = false;
    if (mInitialized)
    {
        success = GameLoop();
    }
    return true;
}

bool Pong::Game::GameLoop()
{
    mRunning = true;
    float x = 0, y = 0;

    int width = mDisplay.GetWidth();
    while (mRunning)
    {
        mDisplay.SetColor(0, 0, 0);
        mBitmap.Draw(x, y, 0);
        mDisplay.Update();

        ALLEGRO_EVENT event;

        if (!mEventQueue.IsEmpty())
        {
            mEventQueue.Wait(&event);
            switch (event.type)
            {
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                {
                    mRunning = false;
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_AXES:
                {
                    x = event.mouse.x;
                    y = event.mouse.y;
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                {
                    x = y = 0;
                    mMouse.SetXY(mDisplay, 0, 0);
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

        // Actively poll the keyboard
        mKeyboardState.Refresh();

        FLOAT64 moveSpeed = 0.01;
        if (mKeyboardState.KeyIsDown(ALLEGRO_KEY_LCTRL))
        {
            moveSpeed = 0.1;
        }

        if (mKeyboardState.KeyIsDown(ALLEGRO_KEY_RIGHT))
        {
            x += moveSpeed;
        }

        if (mKeyboardState.KeyIsDown(ALLEGRO_KEY_LEFT))
        {
            x -= moveSpeed;
        }
    }

    return true;
}
