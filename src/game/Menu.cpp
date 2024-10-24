#include "Menu.h"

Menu::Menu(vector<string> options, int selected) {
    this->options = options;
    this->selected = selected;
}

Menu::~Menu() {
    
}

void Menu::moveUp() {
    if (selected > 0) {
        selected--;
    }
}

void Menu::moveDown() {
    if (selected < options.size() - 1) {
        selected++;
    }
}

void Menu::display() {
    for (int i = 0; i < options.size(); i++) {
        if (i == selected) {
            cout << "> ";
        } else {
            cout << "  ";
        }
        cout << options[i] << endl;
    }
}

int Menu::getSelected() {
    return selected;
}

void Menu::setSelected(int selected) {
    this->selected = selected;
}

void Menu::addOption(string option) {
    options.push_back(option);
}

void Menu::removeOption(string option) {
    for (int i = 0; i < options.size(); i++) {
        if (options[i] == option) {
            options.erase(options.begin() + i);
            break;
        }
    }
}

void Menu::clearOptions() {
    options.clear();
}
