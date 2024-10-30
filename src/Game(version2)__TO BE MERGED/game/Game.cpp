#include "Game.h"

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
    map->render();
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
    map = new Map(25, 25); // 25 by 25

    display.wait(1);
    std::cout << "Setting up construction..." << std::endl;

    display.wait(1);
    std::cout << "Getting people to move in..." << std::endl;

    display.wait(1);
    std::cout << "Establishing a government..." << std::endl;

    display.loadscreen();

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

    map->render();

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
    std::cout << "Showing you created buildings.\n";
    vector<vector<string>> mapComponents = map->getComponents();

    for (int i = 0; i < map->getWidth(); i++)
    {
        for (int j = 0; j < map->getHeight(); j++)
        {
            if (mapComponents[i][j] != "")
            {
                cout << "* " << mapComponents[i][j] << " is located at (" << i << "," << j << ")\n";
            }
        }
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
    map->render();
    display.wait(10); // 10 seconds delay

    // show menu
    buldingmenu();
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
    std::pair<int, int> coordinates = getBuildCoordinates();

    // use concat(building name, and Variant first letters),
    std::string compName = getVar().substr(0, 1) + display.getvariant().substr(0, 1);
    map->add(compName, coordinates.first, coordinates.second);

    std::cout << "Demolished " << compName << " at coordinates (" << coordinates.first << ", " << coordinates.second << ")." << std::endl;

    // display the map
    map->render();
    display.wait(10); // 10 seconds delay

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
            cout << "Now uograding" << getVar() << " buidling: " << display.getvariant() << endl;
            valid2 = true;
            break;
        case 3:
            cout << "Now uograding" << getVar() << "building: " << display.getvariant() << endl;
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

    std::cout << "Enter the coordinates for the new building (x y): ";
    std::cin >> x >> y;

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
std::pair<string, std::pair<int, int>> Game::getDetroyedBuilding()
{

    int x, y;
    string buildingName;

    // get location on map
    std::cout << "Enter the coordinates for the building you want to detroy (x y): ";
    std::cin >> x >> y;

    // validate coordinates
    if (map->getComponent(x, y) == "")
    {
        cout << "No building at such location, choose another location.";
        return getDetroyedBuilding();
    }

    // get name of building or component from map
    std::cout << "Enter the name for the building you want to detroy: ";
    std::cin >> buildingName;

    // validate name
    if (map->getComponent(x, y) != buildingName)
    {
        cout << "No such building at such location, provide a correct name.";
        return getDetroyedBuilding();
    }

    // no error, cool
    return std::make_pair(buildingName, make_pair(x, y));
}
