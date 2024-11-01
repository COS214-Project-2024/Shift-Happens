#include "Game.h"
#include "../map/Map.h"
#include <iostream>
#include <thread>

Game::Game()
{
    variantop = 0;
    var = "";
}
string Game::getVar() { return var; }
void Game::setvar(const string &var)
{
    this->var = var;
}
Game::~Game()
{
}
int Game::getvariantop()
{
    return variantop;
}
void Game::setvariantop(const int &op)
{
    this->variantop = op;
}

void Game::run()
{
    display.intro();
    MainMenu();
    showMap();
    buldingmenu();
    // display.wait(6000);
}
void Game::MainMenu()
{
    int choice = display.MainMenu();

    bool valid = false;
    while (!valid)
    {
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

    // map->render();

    std::cout << "Enter your name: " << std::endl;
    std::cin >> playerName;

    std::cout << "Starting new game..." << std::endl;
    display.wait(1);

    std::cout << "Welcome " << playerName << "!" << std::endl;
    display.wait(1);

    std::cout << "Generating map.." << std::endl;
    map = new Map(15, 15); // [15 X 15]

    // display.wait(1);
    // std::cout << "Setting up construction..." << std::endl;
    // display.wait(1);
    // std::cout << "Getting people to move in..." << std::endl;

    // display.wait(1);
    // std::cout << "Establishing a government..." << std::endl;

    display.loadscreen();
    display.clear();

    display.wait(1);
    // std::cout << endl;
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

void Game::buldingmenu()
{

    cout << "Lets get started with the simulation!\n";
    int choice = display.GameMenu();
    bool valid = false;
    while (!valid)
    {
        switch (choice)
        {
        case 1:
            showBuildings();
            valid = true;
            break;
        case 2:
            createBuidling();
            valid = true;
            break;
        case 3:
            upgradeBuilding();
            valid = true;
            break;
        case 4:
            demolishbuilding();
            valid = true;
            break;
        case 5:
            MainMenu();

        default:
            std::cout << "Invalid choice. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // choice = display.MainMenu();
            choice = display.GameMenu();
            break;
        }
    }
}

void Game::showBuildings()
{
    std::cout << "\nCreated buildings:\n";
    vector<vector<string>> mapComponents = map->getComponents();
    bool isEmpty = true;
    for (int i = 0; i < map->getWidth(); i++)
    {
        for (int j = 0; j < map->getHeight(); j++)
        {
            if (mapComponents[i][j] != "")
            {
                isEmpty = false;
                cout << "* " << BLUE << mapComponents[i][j] << RESET << " is located at (" << BLUE << i << "," << j << ")\n"
                     << RESET;
            }
        }
    }
    
    if(isEmpty == true){
        system("clear");
        std::cout << "\n0 buildings... Start creating something it's easy\n";
    }

    // 7 second delay
    display.wait(7);

    // show menu options
    buldingmenu();
}

void Game::createBuidling()
{
    std::cout << "You have chosen to create a building.\n";
    std::cout << "What type variant do you wish to create? ";
    int choice = display.buildingtypemenu();
    int choice2;
    bool valid = false;
    while (!valid)
    {
        switch (choice)
        {
        case 1:
            choice2 = display.Utilitymenu();
            setvariantop(choice2);
            setvar("Utility");

            createVariant(getvariantop());

            valid = true;
            break;
        case 2:

            choice2 = display.Industrialmenu();

            setvariantop(choice2);
            setvar("Industrial");
            createVariant(getvariantop());
            valid = true;
            break;
        case 3:
            choice2 = display.Residentialmenu();

            setvariantop(choice2);
            setvar("Residential");
            createVariant(getvariantop());

            valid = true;
            break;
        case 4:
            choice2 = display.Commercialmenu();
            setvariantop(choice2);
            setvar("Commercial");
            createVariant(getvariantop());

            valid = true;

            break;

        default:
            std::cout << "Invalid choice. taking you to back." << std::endl;
            std::cin.clear();
            display.wait(1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // choice = display.MainMenu();
            // createBuidling();
            display.buildingtypemenu();
            break;
        }
    }
}
void Game::createVariant(const int &op)
{

    bool valid2 = false;
    while (!valid2)
    {
        switch (op)
        {
        case 1:
            cout << "Getting ready to build " << getVar() << " building >> " << display.getvariant() << endl;
            valid2 = true;
            break;
        case 2:
            cout << "Getting ready to build" << getVar() << " building >> " << display.getvariant() << endl;
            valid2 = true;
            break;
        case 3:
            cout << "Getting ready to build " << getVar() << " building >> " << display.getvariant() << endl;
            valid2 = true;
            break;
        case 4:
            cout << "Getting ready to build " << getVar() << " building >> " << display.getvariant() << endl;
            valid2 = true;
            break;
        default:
            std::cout << "Invalid choice. taking you to back." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            createBuidling();
            break;
        }
    }

    // Prompt for coordinates after confirming the building variant
    std::pair<int, int> coordinates = getBuildCoordinates();

    // use concat(building name, and Variant first letters),
    std::string compName = getVar().substr(0, 1) + display.getvariant().substr(0, 1);
    map->add(compName, coordinates.first, coordinates.second);

    std::cout << "Building " << compName << " at coordinates (" << coordinates.first << ", " << coordinates.second << ")." << std::endl;

    // display the map
    showMap();
    // display.wait(10);   //10 seconds delay

    // show menu
    buldingmenu();
}

void Game::showMap()
{
    display.clear();
    display.logo();
    cout << endl;
    map->render();
    cout << "\n " << BLUE << "Press C to proceed" << RESET << endl;
    string s = "";
    cin >> s;
    if (s.length() == 0)
    {
        showMap();
    }
    else{
        return;
    }
}

void Game::demolishvariant(const int &op)
{
    bool valid2 = false;
    while (!valid2)
    {
        switch (op)
        {
        case 1:
            cout << "Now demolishing " << getVar() << " building >> " << display.getvariant() << endl;
            valid2 = true;
            break;
        case 2:
            cout << "Now demolishing" << getVar() << " building >> " << display.getvariant() << endl;
            valid2 = true;
            break;
        case 3:
            cout << "Now demolishing " << getVar() << " building >> " << display.getvariant() << endl;
            valid2 = true;
            break;
        case 4:
            cout << "Now demolishing" << getVar() << " building >> " << display.getvariant() << endl;
            valid2 = true;
            break;
        default:
            std::cout << "Invalid choice. taking you to back." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            createBuidling();
            break;
        }
    }

    // Prompt for coordinates after confirming the building variant
    std::pair<int, int> coordinates = getDestroyedBuilding();

    // use concat(building name, and Variant first letters),
    std::string compName = getVar().substr(0, 1) + display.getvariant().substr(0, 1);
    map->remove(coordinates.first, coordinates.second);

    std::cout << "Demolished " << compName << " at coordinates (" << coordinates.first << ", " << coordinates.second << ")." << std::endl;

    // display the map
    showMap();
    // display.wait(10);   //10 seconds delay

    // show menu
    buldingmenu();
}
void Game::upgradevariant(const int &op)
{
    bool valid2 = false;
    while (!valid2)
    {
        switch (op)
        {
        case 1:
            cout << "Now upgrading " << getVar() << " building: " << display.getvariant() << endl;
            valid2 = true;
            break;
        case 2:
            cout << "Now upgrading" << getVar() << " buidling: " << display.getvariant() << endl;
            valid2 = true;
            break;
        case 3:
            cout << "Now upgrading" << getVar() << "building: " << display.getvariant() << endl;
            valid2 = true;
            break;
        case 4:
            cout << "Now upgrading" << getVar() << " building: " << display.getvariant() << endl;
            valid2 = true;
            break;
        default:
            std::cout << "Invalid choice. taking you to back." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            createBuidling();
            break;
        }
    }

    // Prompt for coordinates after confirming the building variant
    std::pair<string, std::pair<int, int>> coordinates = getUpgradedBuilding();

    // use concat(building name, and Variant first letters),
    std::string compName = coordinates.first;
    map->remove(coordinates.second.first, coordinates.second.second);
    map->add(compName, coordinates.second.first, coordinates.second.second);

    string coordinatesPair = "(" + std::to_string(coordinates.second.first) + std::to_string(coordinates.second.second) + ")";

    map->upgraded_tiles.emplace_back(coordinates.first, coordinatesPair);

    std::cout << "Upgraded " << compName << " at coordinates (" << coordinates.second.first << ", " << coordinates.second.second << ")." << std::endl;

    display.wait(2);
    
    // display the map
    showMap();
    // display.wait(10);   //10 seconds delay

    // show menu
    buldingmenu();
}

void Game::demolishbuilding()
{
    std::cout << "You have chosen to demolish a building.\n";
    std::cout << "What type variant do you wish to demolish? ";
    int choice = display.buildingtypemenu();
    int choice2;
    bool valid = false;
    while (!valid)
    {
        switch (choice)
        {
        case 1:
            choice2 = display.Utilitymenu();
            setvariantop(choice2);
            setvar("Utility");

            createVariant(getvariantop());

            valid = true;
            break;
        case 2:

            choice2 = display.Industrialmenu();

            setvariantop(choice2);
            setvar("Industrial");
            demolishvariant(getvariantop());
            valid = true;
            break;
        case 3:
            choice2 = display.Residentialmenu();

            setvariantop(choice2);
            setvar("Residential");
            demolishvariant(getvariantop());

            valid = true;
            break;
        case 4:
            choice2 = display.Commercialmenu();
            setvariantop(choice2);
            setvar("Commercial");
            demolishvariant(getvariantop());

            valid = true;

            break;

        default:
            std::cout << "Invalid choice. taking you to back." << std::endl;
            std::cin.clear();
            display.wait(1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // choice = display.MainMenu();
            // createBuidling();
            display.buildingtypemenu();
            break;
        }
    }
}
void Game::upgradeBuilding()
{
    std::cout << "You have chosen to upgrade a building.\n";
    std::cout << "What type variant do you wish to upgrade? ";
    int choice = display.buildingtypemenu();
    int choice2;
    bool valid = false;
    while (!valid)
    {
        switch (choice)
        {
        case 1:
            choice2 = display.Utilitymenu();
            setvariantop(choice2);
            setvar("Utility");

            upgradevariant(getvariantop());

            valid = true;
            break;
        case 2:

            choice2 = display.Industrialmenu();

            setvariantop(choice2);
            setvar("Industrial");
            upgradevariant(getvariantop());
            valid = true;
            break;
        case 3:
            choice2 = display.Residentialmenu();

            setvariantop(choice2);
            setvar("Residential");
            upgradevariant(getvariantop());

            valid = true;
            break;
        case 4:
            choice2 = display.Commercialmenu();
            setvariantop(choice2);
            setvar("Commercial");
            upgradevariant(getvariantop());

            valid = true;

            break;

        default:
            std::cout << "Invalid choice. taking you to back." << std::endl;
            std::cin.clear();
            display.wait(1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // choice = display.MainMenu();
            // createBuidling();
            display.buildingtypemenu();
            break;
        }
    }
}
bool Game::validatevariant(string &variant)
{
    bool valid = false;
    if (variant == "Utility" || variant == "Industrial" || variant == "Commercial" || variant == "Residential")
    {
        valid = true;
    }
    return valid;
}

// #################################################
// We use these below for building and destroying
// #################################################

// Builder coordinates
std::pair<int, int> Game::getBuildCoordinates()
{
    int x, y;

    std::cout << "Enter the coordinates for the new building's location";
    std::cout << "\nEnter the x coordinate:";
    std::cin >> x;

    std::cout << "\nEnter the y coordinate:";
    std::cin >> y;

    // validate coordinates
    if (map->getComponent(x, y) != "")
    {
        cout << "Location occupied, choose another location.";
        return getBuildCoordinates();
    }

    // no error, cool
    return std::make_pair(x, y);
}

// Demolisher coordinates and nane
std::pair<int, int> Game::getDestroyedBuilding()
{

    int x, y;
    string buildingName;

    // get location on map
    std::cout << "Enter the coordinates for the building you want to detroy";
    std::cout << "\nEnter the x coordinate:";
    std::cin >> x;

    std::cout << "\nEnter the y coordinate:";
    std::cin >> y;

    // validate coordinates
    if (map->getComponent(x, y) == "")
    {
        cout << "No building at such location, choose another location.";
        return getDestroyedBuilding();
    }

    // get name of building or component from map
    // std::cout << "Enter the name for the building you want to detroy: ";
    // std::cin >> buildingName;

    // // validate name
    // if (map->getComponent(x, y) != buildingName)
    // {
    //     cout << "No building at such location, choose another location.";
    //     return getDestroyedBuilding();
    // }

    // no error, cool
    string name = map->getComponent(x, y);
    cout << GREEN << name << "Commercial building is being being destroyed." << RESET;
    
    return make_pair(x, y);
}

// Upgrader coordinates
std::pair<string, std::pair<int, int>> Game::getUpgradedBuilding()
{

    int x, y;
    string buildingName;

    // get location on map
    std::cout << "Enter the coordinates for the building you want to upgrade. ";
    std::cout << "\nEnter the x coordinate:";
    std::cin >> x;

    std::cout << "\nEnter the y coordinate:";
    std::cin >> y;

    // validate coordinates
    if (map->getComponent(x, y) == "")
    {
        cout << "No building at such location, choose another location.";
        return getUpgradedBuilding();
    }

    // get name of building or component from map
    std::cout << "Enter the name for the building you want to upgrade: ";
    std::cin >> buildingName;

    // validate name
    // if (map->getComponent(x, y) != buildingName)
    // {
    //     cout << "No building at such location, choose another location.";
    //     return getUpgradedBuilding();
    // }

    // got it, cool!
    if (buildingName.at(0) == 'C')
    {
        cout << GREEN << "Commercial building is being upgraded.";
    }
    else if (buildingName.at(0) == 'U')
    {
        cout << GREEN << "Utility building is being upgraded.";
    }
    else if (buildingName.at(0) == 'I')
    {
        cout << GREEN << "Industrial building is being upgraded.";
    }
    else if (buildingName.at(0) == 'R')
    {
        cout << GREEN << "Residential building is being upgraded.";
    }

    // map->change(buildingName, x, y);

    // no error, cool
    return std::make_pair(buildingName, make_pair(x, y));
}