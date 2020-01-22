#pragma once
#include <string>
#include <array>
#include "AllegroPong.h"
#include "AllegroDisplay.h"
#include "AllegroEventQueue.h"
#include "AllegroKeyboard.h"
#include "AllegroKeyboardState.h"
#include "AllegroMouse.h"
#include "AllegroBitmap.h"
#include "AllegroTimer.h"
#include "AlMainModule.h"
#include "KeyPressHandler.h"

namespace Pong {
    ////////////////////////////////////////////////////////////////////////////
    class GameIcon
    {
    public:
        void Draw();

        bool DoesCollide(const GameIcon& other) const;

        FLOAT32 Height() const;
        FLOAT32 Width() const;

        FLOAT32 X = 0.0f;
        FLOAT32 Y = 0.0f;
        AllegroBitmap Bitmap;
    };

    ////////////////////////////////////////////////////////////////////////////
    class Game
    {
    public:
        ////////////////////////////////////////////////////////////////////////////
        Game() = default;

        ////////////////////////////////////////////////////////////////////////////
        ~Game() = default;

        ////////////////////////////////////////////////////////////////////////////
        bool Init();

        ////////////////////////////////////////////////////////////////////////////
        bool Run();
    private:
        ////////////////////////////////////////////////////////////////////////////
        bool GameLoop();

        ////////////////////////////////////////////////////////////////////////////
        void HandleUserMovement(FLOAT32& x, FLOAT32& y);

        ////////////////////////////////////////////////////////////////////////////
        void HandleCpuMovement(FLOAT32& x, FLOAT32& y);

        bool mInitialized = false;
        bool mRunning = false;

        AlMainModule mMainModule;

        static const INT32 sDisplayWidth = 640;
        static const INT32 sDisplayHeight = 480;
        AllegroDisplay mDisplay;

        AllegroEventQueue mEventQueue;

        AllegroKeyboard mKeyboard;
        AllegroMouse mMouse;
        KeyPressHandler mKeyPressHandler;

        static const std::string sImagePath;
        GameIcon mUserIcon;
        GameIcon mCpuIcon;

        static const FLOAT64 sFps;
        AllegroTimer mTimer;
    };
}



