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
#include "AlFontModule.h"
#include "AlTtfModule.h"
#include "KeyPressHandler.h"
#include "AllegroMouseEvent.h"
#include "ScoreBoard.h"
#include "GameCharacters.h"

namespace Pong {
    ////////////////////////////////////////////////////////////////////////////
    class Game
    {
    public:
        ////////////////////////////////////////////////////////////////////////////
        Game();

        ////////////////////////////////////////////////////////////////////////////
        ~Game() = default;

        ////////////////////////////////////////////////////////////////////////////
        bool Init();

        ////////////////////////////////////////////////////////////////////////////
        bool Run();
    private:
        ////////////////////////////////////////////////////////////////////////////
        bool GameLoop();

        static const INT32 sDisplayWidth = 640;
        static const INT32 sDisplayHeight = 480;

        bool mInitialized = false;
        bool mRunning = false;

        AlMainModule mMainModule;

        AlFontModule mFontModule;
        AlTtfModule mTtfModule;
        const CHAR* mFontFile = "data-unifon.ttf";
        const UINT16 mFontSize = 72;
        AllegroTtfFont mAllegroFont;

        AllegroDisplay mDisplay;

        AllegroEventQueue mEventQueue;

        AllegroKeyboard mKeyboard;
        AllegroMouse mMouse;
        KeyPressHandler mKeyPressHandler;

        static const std::string sImagePath;

        static const FLOAT64 sFps;
        AllegroTimer mTimer;

        Ball mBall;
        Player mPlayer;
        Opponent mOpponent;

        UINT16 mPlayerScore = 0;
        UINT16 mOpponentScore = 0;

        ScoreBoard mPlayerScoreboard;
        ScoreBoard mOpponentScoreboard;
    };
}



