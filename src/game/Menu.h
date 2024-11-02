#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Menu {
public:
    Menu(vector<string> options, int selected);
    ~Menu();

    void moveUp();
    void moveDown();
    void display();
    int getSelected();
    void setSelected(int selected);

    void addOption(string option);
    void removeOption(string option);
    void clearOptions();

    
private:
    vector<string> options;
    int selected;

};

#endif // MENU_H