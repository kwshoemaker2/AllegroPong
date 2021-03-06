#include <string>
#include "AllegroBitmap.h"
#include "AllegroMouseEvent.h"
#include "AllegroDisplay.h"
#include "KeyPressHandler.h"

namespace Pong {
    struct Coordinates
    {
        FLOAT32 X = 0.0F;
        FLOAT32 Y = 0.0F;
    };

    class Character
    {
    public:
        virtual bool Init() = 0;
        virtual void Move() = 0;

        void Draw();

        FLOAT32 GetHeight() const;
        FLOAT32 GetWidth() const;

        FLOAT32 GetX() const { return mCoords.X; }
        FLOAT32 GetY() const { return mCoords.Y; }

    protected:
        AllegroBitmap mBitmap;
        Coordinates mCoords;
    };

    class Player : public Character
    {
    public:
        Player() = delete;

        explicit Player(const KeyPressHandler& keyPressHandler)
            :mKeyPressHandler(keyPressHandler)
        {}

        bool Init() override;

        void Move() override;

        void DoMouseEvent(const AllegroMouseEvent& mouseEvent);

        void HandleCollisionWithDisplay(const AllegroDisplay& display);
        void HandleCollisionWithCharacter(const Character& character);

    private:
        const CHAR* sBitmapPath = "paddle.png";
        static constexpr FLOAT32 sSpeed = 5.0F;
        const KeyPressHandler& mKeyPressHandler;
    };

    class Opponent : public Character
    {
    public:
        Opponent() = delete;
        Opponent(const Character& ball);

        bool Init() override;
        void Move() override;

        void HandleCollisionWithDisplay(const AllegroDisplay& display);

    private:
        FLOAT32 mDy = sSpeed;
        const CHAR* sBitmapPath = "paddle.png";
        const Character& mBall;
        static constexpr FLOAT32 sSpeed = 5.0F;
    };

    class Ball : public Character
    {
    public:
        Ball() = delete;
        Ball(FLOAT32 displayWidth, FLOAT32 displayHeight);

        bool Init() override;
        void Move() override;

        void HandleCollisionWithDisplay(const AllegroDisplay& display);
        void HandleCollisionWithCharacter(const Character& character);

        bool HandleCharacterMiss(const Character& character);

    private:
        void MoveToInitCoords();

        const FLOAT32 mInitX;
        const FLOAT32 mInitY;
        FLOAT32 mDx = sSpeed;
        FLOAT32 mDy = sSpeed;
        const CHAR* sBitmapPath = "ball.png";
        static constexpr FLOAT32 sSpeed = 4.0F;
    };
}
