#include "Game.h"
#include <iostream>
#include <thread>
Game::Game() {

}

Game::~Game() {
}

void Game::initialize() {
    
}

void Game::run() {
    display.intro();
    bool running = true;
    string option = "Main Menu";
    while (running)
    {
        int  display.MainMenu();
        handler.handleMain(1);

    }

}

