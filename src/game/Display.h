#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>
#include <iostream>


using namespace std;
class Display {
public:
    Display();
    ~Display();

    void intro();
    void logo();
    void clear();
    void wait(int seconds);
    void loadscreen();

    int MainMenu();
    void displayMenu(vector<string> options);


private:
    // Add private members and methods as needed
};

#endif // DISPLAY_H