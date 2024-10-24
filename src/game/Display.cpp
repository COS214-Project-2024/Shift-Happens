#include "Display.h"
#include <iostream>
#include <thread>
#include <curses.h>

Display::Display() {

}

Display::~Display() {
    
}

void Display::intro() {
    std::cout << "Welcome to CityCraft!" << std::endl;
    std::cout << "Press Enter to start the game." << std::endl;
    std::cin.get();
    clear();
    wait(1);
    logo();
    std::cout << "Press any key to continue..." << std::endl; 
    std::cin.get();
}

void Display::clear() {
    system("clear");
}

void Display::logo() {
std::cout << R"(
        
_________ .__  __           _________                _____  __   
\_   ___ \|__|/  |_ ___.__. \_   ___ \____________ _/ ____\/  |_ 
/    \  \/|  \   __<   |  | /    \  \/\_  __ \__  \\   __\\   __\
\     \___|  ||  |  \___  | \     \____|  | \// __ \|  |   |  |  
 \______  /__||__|  / ____|  \______  /|__|  (____  /__|   |__|  
        \/          \/              \/            \/             

)" << std::endl;
}

void Display::wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int Display::MainMenu() {
    std::vector<std::string> options = {"New Game", "Load Game", "Exit"};
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an option." << std::endl;
        int input;
        std::cin >> input;
        return input;
    }
    return -1;
}

void Display::displayMenu(std::vector<std::string> options) {
    for (std::vector<std::string>::size_type i = 0; i < options.size(); i++) {
        std::cout << i + 1 << ". " << options[i] << std::endl;
    }
}

void Display::loadscreen() {
    clear();
    for (int i = 0; i < 5; i++)
    {
        clear();
        logo();
        std::cout << "Loading";
        for (int j = 0; j < i; j++)
        {
            std::cout << ".";
        }
        
        wait(1);
    }
    
}
