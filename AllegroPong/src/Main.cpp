#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "AllegroDisplay.h"
#include "AllegroEventQueue.h"
#include "AllegroKeyboard.h"
#include "AllegroBitmap.h"

using namespace Pong;

int main()
{
    al_init();

    AllegroDisplay display;
    display.Create(640, 480);

    AllegroEventQueue queue;
    queue.Create();

    AllegroKeyboard keyboard;
    keyboard.Create();

    queue.RegisterEventSource(keyboard);
    queue.RegisterEventSource(display);

    al_init_image_addon();
    AllegroBitmap bitmap;
    bitmap.Load("image.png");


    bool running = true;
    float x = 0;

    int width = display.GetDisplayWidth();
    while (running) {
        al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));
        bitmap.Draw(x += 0.01, 0, 0);
        al_flip_display();


        if (x > width) x = -bitmap.GetWidth();

        ALLEGRO_EVENT event;

        if (!queue.IsEmpty()) {
            queue.Wait(&event);
            if (event.type == ALLEGRO_EVENT_KEY_UP || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                running = false;
            }
        }
    }

    display.Close();
    keyboard.Destroy();
    bitmap.Destroy();

    return 0;
}