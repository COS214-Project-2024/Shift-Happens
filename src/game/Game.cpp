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

    render();
    display.wait(1);
    //std::cout << endl;
   // buldingmenu();

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

void Game::render(){
    display.clear();
    display.logo();
    map->render();
    display.wait(5);
    /*//MainMenu();
    int input;
    cin>>input;*/
    buldingmenu();
    
}
void Game::buldingmenu(){
    cout <<"Lets get started with the simulation!\n";
    int choice = display.GameMenu();
    bool valid = false;
    while (!valid){
        switch (choice)
        {
        case 1:
            createBuidling();
            valid = true;
            break;
        case 2:
            upgradeBuilding();
            valid = true;
            break;
        case 3:
            demolishbuilding();
            valid = true;
            break;
        case 4:
        MainMenu();

        default:
            std::cout << "Invalid choice. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = display.MainMenu();
            break;
        }

    }

}
void Game::createBuidling()
{
    std::cout << "You have chosen to create a building.\n";
            std::cout << "What type variant do you wish to create? ";
            std::cin >> var;
             bool val = validatevariant(var);
            if(val == false){
                cout << var <<" is not a  valid variant ,try again!\n";
                createBuidling();
                
            }else {
                 std::cout << "Now creating building of type " << var << endl;
            //TO-DO ATTACH CREATION LOGIC

            }

           

}
void Game::demolishbuilding()
{
    std::cout <<"You have chosen to demolish a building.\n";
            std::cout <<"What type variant do you wish to demolish? ";
            std::cin >> var ;
             bool val = validatevariant(var);
            if(val == false){
                cout << var << " is not a valid variant ,try again!\n";
                demolishbuilding();
                
            }else {
                 std::cout <<"Now demolishing building of type" << var << endl;

            }
           
}
void Game::upgradeBuilding()
{
    std::cout <<"You have chosen to upgrade a building.\n";
            std::cout <<"What type variant do you wish to upgrade? ";
            std::cin >> var ;
            bool val = validatevariant(var);
            if(val == false){
                cout << var << "is not a valid variant ,try again!\n";
                upgradeBuilding();
                
            }else{
            std::cout <<"Now upgrading building of type" << var << endl;}
            //DISPLAY CURRENT BUILDINGS AND CHOOSE UPGRADE?}
}
bool Game::validatevariant(string& variant)
{
    bool valid = false;
    if(variant == "Utility" || variant == "Industrial" || variant == "Commercial" || variant== "Residential")
    {
        valid = true;

    } else {valid == false;}
    return valid;

}