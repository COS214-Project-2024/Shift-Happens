#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>
#include <memory>

#include <iostream>
#include "../map/Map.h"
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

    void displayStats();

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


    //Upgrade Menus
    void upgradeMenu();

    //Government Menus
    void governmentMenu(std::shared_ptr<Government> government);

    void taxMenu(std::shared_ptr<Government> government);
    void businessTaxMenu(std::shared_ptr<Government> government);
    void personalTaxMenu(std::shared_ptr<Government> government);
    void policiesMenu(std::shared_ptr<Government> government);
    void servicesMenu(std::shared_ptr<Government> government);
    void budgetMenu(std::shared_ptr<Government> government);
    
    void statisticsMenu();



    //helper functions
    string check(string var, int num); // check if building is built
    vector<string> getUpgrades(string var, int num); // get available upgrades for building






 
private:

    Map& map;
    shared_ptr<Statistics> stats;

};

#endif // DISPLAY_H