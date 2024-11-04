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

/**
 * @class Game
 * @brief Manages the main game logic and flow for the city simulation.
 */
class Game
{
public:
    /**
     * @brief Constructs a Game object.
     */
    Game();

    /**
     * @brief Destructs the Game object.
     */
    ~Game();

    /**
     * @brief Starts the main game loop, running the simulation.
     */
    void run();

    /**
     * @brief Displays and manages the main menu.
     */
    void MainMenu();

    /**
     * @brief Displays and manages the in-game menu.
     */
    void GameMenu();

private:
    /**
     * @brief Display object used for showing menus and game information.
     */
    Display display;
};

#endif // GAME_H
