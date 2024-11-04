#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>
#include <memory>

#include <iostream>
#include "../map/Map.h"
#include "../Statistics.h"


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
    void governmentMenu();

    void taxMenu();
    void businessTaxMenu();
    void personalTaxMenu();

    void policiesMenu();

    void servicesMenu();

    void budgetMenu();
    
    void statisticsMenu();

    //save and load menus
    int SaveMenu();
    void saveToFile();
    void saveToFile(const std::string& filename, const std::vector<std::string>& headers, const std::vector<std::vector<std::string>>& data);
    
    int LoadMenu();
    void loadFromFile();
    void loadStatsFromFile(const std::string& filename, std::vector<std::string>& headers, std::vector<std::vector<std::string>>& data);
    
    
    //helper functions
    string check(string var, int num); // check if building is built
    vector<string> getUpgrades(string var, int num); // get available upgrades for building






 
private:

    Map& map;
    shared_ptr<Statistics> stats;

};

#endif // DISPLAY_H