#include <iostream>
#include "Game.h"

const std::string Pong::Game::sImagePath = "image.png";
const FLOAT64 Pong::Game::sFps = 60.0;

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

        mBitmap.Load(sImagePath.c_str());

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
    return success;
}

bool Pong::Game::GameLoop()
{
    mRunning = true;

    mTimer.Start();

    FLOAT32 x = 0;
    FLOAT32 y = 0;

    bool redraw = false;

    while (mRunning)
    {
        ALLEGRO_EVENT event;

        mEventQueue.Wait(&event);
        switch (event.type)
        {
            case ALLEGRO_EVENT_TIMER:
            {
                FLOAT32 moveSpeed = 1;
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

        if (redraw)
        {
            mDisplay.SetColor(0, 0, 0);
            mBitmap.Draw(x, y, 0);
            mDisplay.Update();
            redraw = false;
        }
    }

    return true;
}
