#ifndef GAME_H
#define GAME_H

#include "Display.h"
#include "Menu.h"
#include "Handler.h"

class Game {
public:
    Game();
    ~Game();

    void initialize();
    void run();

private:
    Display display;
};

#endif // GAME_H