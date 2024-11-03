#include "Game.h"
#include <iostream>
#include <thread>

Game::Game()
{
}
Game::~Game()
{
}


void Game::run()
{
    MainMenu();
}
void Game::MainMenu()
{   
    int choice;
    while (true){
        choice = display.MainMenu();
        switch (choice)
        {
        case 1:
            GameMenu();
            break;
        case 2:
            throw "error: load game not implemented";
        case 3:
            throw "error: save game not implemented";
        case 4:
            display.clear();
            std::cout << "Goodbye!" << std::endl;
            display.wait(1);
            exit(0);
        default:
            throw "error: invalid input main menu";
        }
    }
}

void Game::GameMenu()
{   
    int choice;
    while (true){
        choice = display.GameMenu();
        switch (choice)
        {
        case 1:
            
        case 2:
            
        case 3:

        case 4:
            display.clear();
            std::cout << "Goodbye!" << std::endl;
            display.wait(1);
            exit(0);
        default:
            throw "error: invalid input main menu";
        }
    }

}



