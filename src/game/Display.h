#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>
#include <iostream>
#include "Menu.h"


using namespace std;
class Display {
public:
    Display();
    ~Display();

    void intro();
    void logo();
    void clear();
    void wait(int seconds);
    int MainMenu();


private:
    // Add private members and methods as needed
};

#endif // DISPLAY_H