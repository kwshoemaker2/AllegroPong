#include <iostream>
#include <cstdlib>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Game.h"

using namespace Pong;

int main()
{
    srand(time(NULL));
    Game game;

    bool success = false;
    bool initialized = game.Init();
    if (initialized)
    {
        success = game.Run();
    }
    else
    {
        std::cerr << "Could not initialize!" << std::endl;
    }

    if (success)
    {
        return 0;
    }
    return -1;
}