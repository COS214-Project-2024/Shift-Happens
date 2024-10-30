#ifndef GAME_H
#define GAME_H

#include "Display.h"
#include "../map/MapComponent.h"
#include "../map/Map.h"
#include <string>
#include"../buildings/Building.h"
#include"../buildingFactories/UtilityBuildingFactory.h"
#include"../buildingFactories/CommercialBuildingFactory.h"
#include"../buildingFactories/ResidentialBuildingFactory.h"
#include"../buildingFactories/InfrastructureFactory.h"
#include"../buildingFactories/LandmarkBuildingFactory.h"
#include"../buildingFactories/IndustrialBuildingFactory.h"
/**
 * @class Game
 * @brief Manages the main game operations including menus, player actions, and map interactions.
 * 
 * The Game class serves as the core class for handling game state, player actions,
 * and interactions with the Display class for menu navigation and user input.
 */
//FUNCTION AND THEN DOXYGEN COMMENT UNDER IT. UNDER NOT ABOVE.

class Game
{
public:
    Game();
     /**
     * @brief Constructor for the Game class.
     */


    ~Game();
    /**
     * @brief Destructor for the Game class.
     */
    void createUtilityBuilding(const std::string& variant);  // Building creation
    void createResidentialBuilding(const std::string& variant);  // Building creation
    void createCommercialBuilding(const std::string& variant);  // Building creation
    void createInfrastructureBuilding(const std::string& variant);  // Building creation
    void createLandMarkBuilding(const std::string& variant);  // Building creation
    void createIndustrialBuilding(const std::string& variant);  // Building creation

   
    

    void run();
    /**
     * @brief Runs the main game loop, starting with the intro and main menu.
     */
    private: //client only has access to above


    void MainMenu();
    /**
     * @brief Displays the main menu and handles user selection.
     */

    void newGame();
    /**
     * @brief Starts a new game and initializes the map.
     */

    void loadGame();
    /**
     * @brief Handles the load game functionality (currently under construction).
     */
    void underConstruction();
    /**
     * @brief Displays an under construction message.
     */
   

    void render();
     /**
     * @brief Renders the map and displays the building menu.
     */

    void createBuidling();
    /**
     * @brief Prompts the user to select a building variant and initiates creation.
     */
    
    void upgradeBuilding();
     /**
     * @brief Prompts the user to select a building variant and initiates upgrade.
     */

    void demolishbuilding();
    /**
     * @brief Prompts the user to select a building variant and initiates demolition.
     */

    void buldingmenu();
    /**
     * @brief Displays and manages the building menu for different actions.
     */

    bool validatevariant(string& variant);//useless

    void createVariant(const int& option);//use option to create specific variant
    /**
     * @brief Creates a building based on a variant option.
     * @param option The variant option for building creation.
     */

    void demolishvariant(const int& option);
    /**
     * @brief Demolishes a building based on a variant option.
     * @param option The variant option for building demolition.
     */

    void upgradevariant(const int& option);
    /**
     * @brief Upgrades a building based on a variant option.
     * @param option The variant option for building upgrade.
     */

    int getvariantop();//option for variant menu
    /**
     * @brief Retrieves the selected variant option.
     * @return int The selected variant option.
     */

    void setvariantop(const int& op);
    /**
     * @brief Sets the variant option.
     * @param op The variant option to set.
     */

    void setvar(const string& var); //varaint name eg. Utility
    /**
     * @brief Sets the variant name for the building type.
     * @param var The variant name to set.
     */

    string getVar();
    /**
     * @brief Retrieves the current variant name.
     * @return std::string The current variant name.
     */
    

//private:
    Display display;///< Display object for handling user interface elements
    string playerName;///<Stores the players name and uses it in intro.
    MapComponent * map; ///>Pointer to the map
    string var;///< Stores the variant name for a building type
    int variantop;///< Stores the option selected for a building variant

    //std::unique_ptr<MapComponent> map;
    std::shared_ptr<Building> buildings;  // Container for created buildings
    //factories
    std::shared_ptr<UtilityBuildingFactory> utilityfactory;
    std::shared_ptr<IndustrialBuildingFactory> Industsrialfactory;
    std::shared_ptr<CommercialBuildingFactory> Commerecialfactory;
    std::shared_ptr<LandmarkBuildingFactory> LandMarkfactory;
    std::shared_ptr<ResidentialBuildingFactory> Residentialfactory;
    std::shared_ptr<InfrastructureFactory> Infrastructurefactory;

    //
};

#endif // GAME_H