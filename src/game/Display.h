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
    int GameMenu(); //for creation of buildings
    int Utilitymenu();//options for specific creation
    int Residentialmenu();
    int Commercialmenu();
    int Industrialmenu();
    int LandMarkmenu();
    int buildingtypemenu();
    string getvariant();
    void settype(const string& variant);



private:
    // Add private members and methods as needed
    string variant;
};

#endif // DISPLAY_H