#include <iostream>
#include <allegro5/allegro.h>
#include "AllegroDisplay.h"
#include "AllegroKeyboard.h"
#include "AllegroTimer.h"

using namespace Pong;

////////////////////////////////////////////////////////////////////////////////
int main()
{
    ALLEGRO_EVENT_QUEUE* queue;

    al_init();

    AllegroDisplay display;
    display.Create(640, 480);

    queue = al_create_event_queue();

    AllegroTimer timer;
    timer.Create(1.0 / 60.0);

    AllegroKeyboard keyboard;
    keyboard.Create();

    al_register_event_source(queue, keyboard.GetEventSource());
    al_register_event_source(queue, display.GetEventSource());
    al_register_event_source(queue, timer.GetEventSource());

    timer.Start();
    INT32 sentinel = 0;
    bool running = true;
    while (running)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
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

    timer.Stop();
    timer.Destroy();

    return 0;
}
