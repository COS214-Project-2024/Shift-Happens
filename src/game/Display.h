#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>
#include <memory>

#include <iostream>
#include "../map/Map.h"
#include "../map/Transportation/TransportationStrategy.h"
#include "../map/Transportation/RoadStrategy.h"
#include "../map/Transportation/TrainStrategy.h"
#include "../map/Transportation/AirStrategy.h"
#include "../map/Transportation/PublicStrategy.h"
#include "../Statistics.h"
#include "../Government/Government.h"
#include "../Government/StandardTax.h"
#include "../Government/LowTax.h"
#include "../Government/HighTax.h"

using namespace std;

/**
 * @class Display
 * @brief Manages the display and menu options for the city simulation.
 */
class Display
{

public:
    /**
     * @brief Constructs a Display object.
     */
    Display();

    /**
     * @brief Destructs the Display object.
     */
    ~Display();

    // Display functions

    /**
     * @brief Displays the simulation's logo.
     */
    void logo();

    /**
     * @brief Clears the screen.
     */
    void clear();

    /**
     * @brief Pauses execution for a specified number of seconds.
     * @param seconds The number of seconds to wait.
     */
    void wait(int seconds);

    /**
     * @brief Displays a loading screen animation.
     */
    void loadscreen();

    /**
     * @brief Gets user input within a specified range.
     * @param max The maximum allowable input.
     * @param min The minimum allowable input.
     * @return The user's input.
     */
    int getInput(int max, int min);

    /**
     * @brief Displays a menu with options.
     * @param title The title of the menu.
     * @param options A vector of option strings.
     */
    void displayMenu(string title, vector<string> options);

    /**
     * @brief Displays a menu with options in a single string.
     * @param title The title of the menu.
     * @param options A string of options.
     */
    void displayMenu(string title, string options);

    /**
     * @brief Displays a single row of data.
     * @param row A vector representing a row of data.
     */
    void displayRow(vector<string> row);

    /**
     * @brief Displays tax statistics.
     */
    void displayTaxStats();

    /**
     * @brief Displays a table with rows and columns.
     * @param table A 2D vector representing the table.
     */
    void displayTable(vector<vector<string>> table);

    /**
     * @brief Displays general statistics.
     */
    void displayStats();

    /**
     * @brief Displays a hidden Easter menu.
     */
    void easterMenu();

    // Menus

    /**
     * @brief Displays the main menu.
     * @return The user's menu selection.
     */
    int MainMenu();

    /**
     * @brief Displays the game menu.
     * @return The user's menu selection.
     */
    int GameMenu();

    // Building Menus

    /**
     * @brief Displays the build menu.
     */
    void buildMenu();

    /**
     * @brief Displays the residential buildings menu.
     */
    void residentialMenu();

    /**
     * @brief Displays the commercial buildings menu.
     */
    void commercialMenu();

    /**
     * @brief Displays the industrial buildings menu.
     */
    void industrialMenu();

    /**
     * @brief Displays the utility buildings menu.
     */
    void utilityMenu();

    /**
     * @brief Displays the landmarks menu.
     */
    void landmarkMenu();

    /**
     * @brief Displays the infrastructure menu.
     */
    void infrastructureMenu();

    /**
     * @brief Destroys all buildings.
     */
    void destroyAll();

    /**
     * @brief Builds all available buildings.
     */
    void buildAll();

    // Upgrade Menus

    /**
     * @brief Displays the upgrade menu.
     */
    void upgradeMenu();

    // Government Menus

    /**
     * @brief Displays the government menu.
     */
    void governmentMenu();

    /**
     * @brief Displays the citizen management menu.
     */
    void CitizenMenu();

    /**
     * @brief Displays the tax menu.
     */
    void taxMenu();

    /**
     * @brief Displays the business tax menu.
     */
    void businessTaxMenu();

    /**
     * @brief Displays the personal tax menu.
     */
    void personalTaxMenu();

    /**
     * @brief Displays the government policies menu.
     */
    void policiesMenu();

    /**
     * @brief Displays the public services menu.
     */
    void servicesMenu();

    /**
     * @brief Displays the government budget menu.
     */
    void budgetMenu();

    /**
     * @brief Displays the statistics menu.
     */
    void statisticsMenu();

    // Helper functions

    /**
     * @brief Checks if a building has been constructed.
     * @param var The building name.
     * @param num The building identifier.
     * @return A string indicating the building status.
     */
    string check(string var, int num);

    /**
     * @brief Gets a list of available upgrades for a building.
     * @param var The building name.
     * @param num The building identifier.
     * @return A vector of available upgrades.
     */
    vector<string> getUpgrades(string var, int num);

    // Destroy function

    /**
     * @brief Displays the destroy menu.
     */
    void destroyMenu();

    // Transport menu

    /**
     * @brief Displays the transportation management menu.
     */
    void transportMenu();

    /**
     * @brief Displays the introduction screen.
     */
    void intro();

    // View the inner workings of all the buildings

    /**
     * @brief Displays the building inspection menu.
     */
    void viewMenu();

private:
    /**
     * @brief Reference to the Map object representing the city map.
     */
    Map &map;

    /**
     * @brief Shared pointer to a Statistics object for managing city statistics.
     */
    shared_ptr<Statistics> stats;
};

#endif // DISPLAY_H
