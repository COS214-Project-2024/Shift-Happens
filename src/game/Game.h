#ifndef GAME_H
#define GAME_H

#include "Display.h"
#include "../map/MapComponent.h"
#include "../map/Map.h"
#include <string>

class Game
{
public:
    Game();
    ~Game();

    void run();
    void MainMenu();
    void newGame();
    void loadGame();
    void underConstruction();
    void render();
    void createBuidling();
    void upgradeBuilding();
    void demolishbuilding();
    void buldingmenu();
    bool validatevariant(string& variant);

private:
    Display display;
    string playerName;
    MapComponent * map;
    string var;
};

#endif // GAME_H