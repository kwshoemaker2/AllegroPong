#pragma once
#include <allegro5/allegro.h>
#include "AllegroPong.h"
#include "IEventSource.h"

namespace Pong {
    ////////////////////////////////////////////////////////////////////////////
    class AllegroDisplay : public IEventSource
    {
    public:
        ////////////////////////////////////////////////////////////////////////
        AllegroDisplay() = default;

        ////////////////////////////////////////////////////////////////////////
        ~AllegroDisplay();

        ////////////////////////////////////////////////////////////////////////
        bool Create(INT32 width, INT32 height);

        ////////////////////////////////////////////////////////////////////////
        bool Update();

        ////////////////////////////////////////////////////////////////////////
        bool SetColor(INT32 r, INT32 g, INT32 b);

        ////////////////////////////////////////////////////////////////////////
        bool SetColorA(INT32 r, INT32 g, INT32 b, INT32 a);

        ////////////////////////////////////////////////////////////////////////
        bool SetColor(FLOAT32 r, FLOAT32 g, FLOAT32 b);

        ////////////////////////////////////////////////////////////////////////
        bool SetColorA(FLOAT32 r, FLOAT32 g, FLOAT32 b, FLOAT32 a);

        ////////////////////////////////////////////////////////////////////////
        bool Close();

        ////////////////////////////////////////////////////////////////////////
        INT32 GetWidth() const;

        ////////////////////////////////////////////////////////////////////////
        INT32 GetHeight() const;

        ////////////////////////////////////////////////////////////////////////
        EventSource* GetEventSource() const override;

        ////////////////////////////////////////////////////////////////////////
        ALLEGRO_DISPLAY* GetRaw() { return mAllegroDisplay; }

    private:
        ALLEGRO_DISPLAY* mAllegroDisplay = nullptr;
    };
}

