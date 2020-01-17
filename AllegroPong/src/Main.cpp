#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "AllegroDisplay.h"
#include "AllegroEventQueue.h"
#include "AllegroKeyboard.h"
#include "AllegroKeyboardState.h"
#include "AllegroMouse.h"
#include "AllegroBitmap.h"

using namespace Pong;

int main()
{
    al_init();
    al_init_image_addon();

    AllegroDisplay display;
    display.Create(640, 480);
    
    AllegroEventQueue queue;
    queue.Create();

    AllegroKeyboard keyboard;
    keyboard.Create();

    AllegroMouse mouse;
    mouse.Create();

    queue.RegisterEventSource(keyboard);
    queue.RegisterEventSource(display);
    queue.RegisterEventSource(mouse);

    AllegroBitmap bitmap;
    bitmap.Load("image.png");

    bool running = true;
    float x = 0, y = 0;

    int width = display.GetWidth();
    while (running) {
        display.SetColor(0, 0, 0);
        bitmap.Draw(x, y, 0);
        display.Update();

        ALLEGRO_EVENT event;

        if (!queue.IsEmpty()) {
            queue.Wait(&event);
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                running = false;
            }

            if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
                x = event.mouse.x;
                y = event.mouse.y;
            }

            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                x = y = 0;
                mouse.SetXY(display, 0, 0);
            }
        }

        // Actively poll the keyboard
        AllegroKeyboardState keyboardState;

        keyboardState.Refresh();
        if (keyboardState.KeyIsDown(ALLEGRO_KEY_RIGHT))
            if (keyboardState.KeyIsDown(ALLEGRO_KEY_LCTRL))
                x += 0.1;
            else
                x += 0.01;
        if (keyboardState.KeyIsDown(ALLEGRO_KEY_LEFT))
            if (keyboardState.KeyIsDown(ALLEGRO_KEY_LCTRL))
                x -= 0.1;
            else
                x -= 0.01;
    }

    return 0;
}