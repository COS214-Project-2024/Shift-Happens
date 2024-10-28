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
    void createVariant(const int& option);//use option to create specific variant
    void demolishvariant(const int& option);
    void upgradevariant(const int& option);
    int getvariantop();//option for variant menu
    void setvariantop(const int& op);
    void setvar(const string& var); //varaint name eg. Utility
    string getVar();
    

private:
    Display display;
    string playerName;
    MapComponent * map;
    string var;
    int variantop;
};

#endif // GAME_H