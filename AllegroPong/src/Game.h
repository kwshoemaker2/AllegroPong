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
    class Game
    {
    public:
        Game() = default;
        ~Game() = default;

        bool Init();

        bool Run();
    private:
        bool GameLoop();
        void HandleUserMovement(FLOAT32& x, FLOAT32& y);
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
        AllegroBitmap mUserIcon;
        AllegroBitmap mCpuIcon;

        static const FLOAT64 sFps;
        AllegroTimer mTimer;

        
    };
}



