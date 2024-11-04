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

class Display {

public:
    Display();
    ~Display();


    //Display functions
    void logo();
    void clear();
    void wait(int seconds);
    void loadscreen();
    int getInput(int max, int min);
    void displayMenu(string title, vector<string> options);
    void displayMenu(string title, string options);
    void displayRow(vector<string> row);
    void displayTaxStats();

    void displayTable(vector<vector<string>> table);
    void displayStats();
    void easterMenu();

    //Menus
    int MainMenu();
    int GameMenu();

    //Building Menus
    void buildMenu();
    void residentialMenu();
    void commercialMenu();
    void industrialMenu();
    void utilityMenu();
    void landmarkMenu();
    void infrastructureMenu();
    void destroyAll();
    void buildAll();

    //Upgrade Menus
    void upgradeMenu();

    //Government Menus
    void governmentMenu();
    void CitizenMenu();
    void taxMenu();
    void businessTaxMenu();
    void personalTaxMenu();
    void policiesMenu();
    void servicesMenu();
    void budgetMenu();
    
    void statisticsMenu();

    //helper functions
    string check(string var, int num); // check if building is built
    vector<string> getUpgrades(string var, int num); // get available upgrades for building

    //destroy function
    void destroyMenu();
    //transport menu
    void transportMenu();
    void intro();

   
    //view the inner workings of all the buildings
    void viewMenu();
 
private:

    Map& map;
    shared_ptr<Statistics> stats;

};

#endif // DISPLAY_H