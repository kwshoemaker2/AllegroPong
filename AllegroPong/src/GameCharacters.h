#include <string>
#include "AllegroBitmap.h"
#include "AllegroMouseEvent.h"
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

        FLOAT32 Height() const;
        FLOAT32 Width() const;

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

    private:
        const CHAR* sBitmapPath = "image.png";
        const KeyPressHandler& mKeyPressHandler;
    };
}
