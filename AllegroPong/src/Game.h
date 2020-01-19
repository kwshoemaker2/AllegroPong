#pragma once
#include <string>
#include "AllegroPong.h"
#include "AllegroDisplay.h"
#include "AllegroEventQueue.h"
#include "AllegroKeyboard.h"
#include "AllegroKeyboardState.h"
#include "AllegroMouse.h"
#include "AllegroBitmap.h"
#include "AllegroTimer.h"
#include "AlMainModule.h"


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

        bool mInitialized = false;
        bool mRunning = false;

        AlMainModule mMainModule;

        static const INT32 sDisplayWidth = 640;
        static const INT32 sDisplayHeight = 480;
        AllegroDisplay mDisplay;

        AllegroEventQueue mEventQueue;

        AllegroKeyboard mKeyboard;
        AllegroKeyboardState mKeyboardState;
        AllegroMouse mMouse;

        static const std::string sImagePath;
        AllegroBitmap mBitmap;

        static const FLOAT64 sFps;
        AllegroTimer mTimer;
    };
}



