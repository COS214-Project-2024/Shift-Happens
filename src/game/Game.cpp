#include "Game.h"
#include <iostream>
#include <thread>

Game::Game() {}

Game::~Game() {}

void Game::run() {
    MainMenu();
}

void Game::MainMenu() {   
    int choice;
    while (true) {
        choice = display.MainMenu();
        switch (choice) {
            case 1:
                GameMenu();
                break; // Ensure to break after handling the case
            case 2:
                LoadMenu();
                break; // Ensure to break after handling the case
            case 3:
                SaveMenu();
                break; // Ensure to break after handling the case
            case 4:
                display.clear();
                std::cout << "Goodbye!" << std::endl;
                display.wait(1);
                exit(0);
            default:
                std::cerr << "Error: Invalid input in main menu." << std::endl;
        }
    }
}

void Game::GameMenu() {   
    int choice;
    while (true) {
        choice = display.GameMenu();
        switch (choice) {
            case 1:
                // Implement your functionality for case 1
                break; // Ensure to break after handling the case
            case 2:
                display.LoadMenu();
                break; // Ensure to break after handling the case
            case 3:
                display.SaveMenu();
                break; // Ensure to break after handling the case
            case 4:
                display.clear();
                std::cout << "Exiting game..." << std::endl;
                display.wait(1);
                exit(0);
            default:
                std::cerr << "Error: Invalid input in game menu." << std::endl;
        }
    }
}

// Load Menu
void Game::LoadMenu() {
    int choice;
    while (true) {
        choice = display.LoadMenu();
        switch (choice) {
            case 1:
                display.loadFromFile(); // Load the game state
                break; // Ensure to break after handling the case
            case 2:
                std::cout << "Cancelling load operation..." << std::endl;
                display.wait(1);
                break; // Go back to the previous menu
            default:
                std::cerr << "Error: Invalid input in load menu." << std::endl;
        }
    }
}

// Save Menu
void Game::SaveMenu() {
    int choice;
    while (true) {
        choice = display.SaveMenu();
        switch (choice) {
            case 1:
                display.saveToFile(); // Save the game state
                break; // Ensure to break after handling the case
            case 2:
                std::cout << "Cancelling save operation..." << std::endl;
                display.wait(1);
                break; // Go back to the previous menu
            default:
                std::cerr << "Error: Invalid input in save menu." << std::endl;
        }
    }
}