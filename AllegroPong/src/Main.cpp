#include <iostream>
#include <allegro5/allegro.h>
#include "AllegroDisplay.h"
#include "AllegroKeyboard.h"
#include "AllegroTimer.h"
#include "AllegroEventQueue.h"

using namespace Pong;

////////////////////////////////////////////////////////////////////////////////
int main()
{
    al_init();

    AllegroDisplay display;
    display.Create(640, 480);

    AllegroEventQueue queue;
    queue.Create();

    AllegroTimer timer;
    timer.Create(1.0 / 60.0);

    AllegroKeyboard keyboard;
    keyboard.Create();

    queue.RegisterEventSource(keyboard);
    queue.RegisterEventSource(display);
    queue.RegisterEventSource(timer);

    timer.Start();
    INT32 sentinel = 0;
    bool running = true;
    while (running)
    {
        ALLEGRO_EVENT event;
        queue.Wait(&event);
        if (event.type == ALLEGRO_EVENT_KEY_UP || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            running = false;
        }

        if (event.type == ALLEGRO_EVENT_TIMER)
        {
            display.SetColor(sentinel, sentinel % 2, sentinel % 3);
            display.Update();
            sentinel++;
        }
    }

    display.Close();
    keyboard.Destroy();
    timer.Destroy();
    queue.Destroy();

    return 0;
}
