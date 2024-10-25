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
    display.intro();
    MainMenu();
}
void Game::MainMenu()
{
    int choice = display.MainMenu();

    bool valid = false;
    while (!valid){
        switch (choice)
        {
        case 1:
            newGame();
            valid = true;
            break;
        case 2:
            loadGame();
            valid = true;
            break;
        case 3:
            display.clear();
            std::cout << "Goodbye!" << std::endl;
            display.wait(1);
            return;
        default:
            std::cout << "Invalid choice. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = display.MainMenu();
            break;
        }

    }
}

void Game::newGame()
{
    display.clear();
    display.logo();
   
    std::cout<< "Enter your name: " << std::endl;
    std::cin >> playerName;
    
    std::cout << "Starting new game..." << std::endl;
    display.wait(1);

    std::cout<< "Welcome " << playerName << "!" << std::endl;
    display.wait(1);

    std::cout<< "Generating map..." << std::endl;
    map = new Map(-1);

    display.wait(1);
    std::cout<< "Setting up construction..." << std::endl;

    display.wait(1);
    std::cout<< "Getting people to move in..." << std::endl;

    display.wait(1);
    std::cout<< "Establishing a government..." << std::endl;

    display.loadscreen();
}

void Game::loadGame()
{
    underConstruction();
}




void Game::underConstruction()
{
    display.clear();
    display.logo();
    std::cout << "Under Construction..." << std::endl;
    display.wait(2);
    std::cout << "Press any key to go back to main" << std::endl;
    string input;
    std::cin >> input;
    MainMenu();
}

