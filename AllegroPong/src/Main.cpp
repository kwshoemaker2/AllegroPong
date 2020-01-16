#include <iostream>
#include <allegro5/allegro.h>
#include "AllegroDisplay.h"

////////////////////////////////////////////////////////////////////////////////
int main()
{
    if (al_init() == 0)
    {
        std::cerr << "Failed to initialize Allegro" << std::endl;
        return -1;
    }

    Pong::AllegroDisplay display;

    if (display.Create(640, 480) == true)
    {
        display.SetColor(0, 0, 0);
        display.Update();

        al_rest(10.0);
    }

    return 0;
}