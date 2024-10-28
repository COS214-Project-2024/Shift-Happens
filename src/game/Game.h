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
    void createVariant(const int& option);
    int getvariantop();
    void setvariantop(const int& op);
    void setvar(const string& var);
    string getVar();

private:
    Display display;
    string playerName;
    MapComponent * map;
    string var;
    int variantop;
};

#endif // GAME_H