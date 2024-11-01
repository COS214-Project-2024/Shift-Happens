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

    void buildMenu();
    void residentialMenu();
    void commercialMenu();
    void industrialMenu();
    void utilityMenu();
    void landmarkMenu();
    void infrastructureMenu();


    
    string check(string var, int num);





 
private:

    Map& map;
    shared_ptr<Statistics> stats;

};

#endif // DISPLAY_H