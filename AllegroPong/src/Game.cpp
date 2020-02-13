#include <iostream>
#include "Game.h"

const std::string Pong::Game::sImagePath = "image.png";
const FLOAT64 Pong::Game::sFps = 60.0;

Pong::Game::Game()
    :mPlayer(mKeyPressHandler)
{
}

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

        mPlayer.Init();
        mOpponent.Init();

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
                mPlayer.Move();
                mOpponent.Move();
                mKeyPressHandler.ClearPresses();

                mPlayer.HandleCollisionWithDisplay(mDisplay);
                mOpponent.HandleCollisionWithDisplay(mDisplay);

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
                AllegroMouseEvent mouseEvent(event);
                mPlayer.DoMouseEvent(mouseEvent);
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
            mPlayer.Draw();
            mOpponent.Draw();

            mDisplay.Update();
            redraw = false;
        }
    }

    return true;
}
