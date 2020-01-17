#include <iostream>
#include <allegro5/allegro.h>
#include "AllegroDisplay.h"
#include "AllegroKeyboard.h"

using namespace Pong;

////////////////////////////////////////////////////////////////////////////////
int main()
{
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_TIMER* timer;

    al_init();

    AllegroDisplay display;
    display.Create(640, 480);

    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60.0);

    AllegroKeyboard keyboard;
    keyboard.Create();

    al_register_event_source(queue, keyboard.GetEventSource());
    al_register_event_source(queue, display.GetEventSource());
    al_register_event_source(queue, al_get_timer_event_source(timer));

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
            display.Update();
        }
    }

    display.Close();
    keyboard.Destroy();

    al_destroy_timer(timer);

    return 0;
}
