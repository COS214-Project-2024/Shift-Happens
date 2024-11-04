#ifndef GAME_H
#define GAME_H

#include "Display.h"
#include "../map/MapComponent.h"
#include "../map/Map.h"
#include <string>
#include "../buildings/Building.h"
#include "../buildingFactories/UtilityBuildingFactory.h"
#include "../buildingFactories/CommercialBuildingFactory.h"
#include "../buildingFactories/ResidentialBuildingFactory.h"
#include "../buildingFactories/InfrastructureFactory.h"
#include "../buildingFactories/LandmarkBuildingFactory.h"
#include "../buildingFactories/IndustrialBuildingFactory.h"


class Game
{
public:
    Game();
    ~Game();

    void run();

    void MainMenu();
    void GameMenu();
    
    //Save and Load
    void LoadMenu();
    void SaveMenu();


    
    


private:
    Display display;
};

#endif // GAME_H