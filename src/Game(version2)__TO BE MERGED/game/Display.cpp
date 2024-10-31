#include "Display.h"
#include <iostream>
#include <thread>

// #include <curses.h>

/// constructor for display purposes
Display::Display()
{
}
///
Display::~Display()
{
}
string Display::getvariant()
{
    return variant;
}
void Display::settype(const string &variant)
{
    this->variant = variant;
}

void Display::intro()
{
    system("clear");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << BLUE;
    std::cout << " _______________________________________________________________" << std::endl;
    std::cout << "|                                                               |" << std::endl;
    std::cout << "|                Welcome to CityCraft!                          |" << std::endl;
    std::cout << "|                                                               |" << std::endl;
    std::cout << "|_______________________________________________________________|" << std::endl;


    wait(2);
    std::cout << GREEN <<"\n\nPress Enter to start the game." << std::endl;
    std::cin.get();
    clear();
    wait(1);
    logo();
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get();
}

void Display::clear()
{
    system("clear");
}

void Display::logo()
{
    clear(); // CLEAR THE TERMINAL
    // Array of colors
    std::string colors[] = {RED, GREEN, BLUE, MAGENTA, CYAN};

    std::string logo = R"(
        
_________ .__  __           _________                _____  __   
\_   ___ \|__|/  |_ ___.__. \_   ___ \____________ _/ ____\/  |_ 
/    \  \/|  \   __<   |  | /    \  \/\_  __ \__  \\   __\\   __\
\     \___|  ||  |  \___  | \     \____|  | \// __ \|  |   |  |  
 \______  /__||__|  / ____|  \______  /|__|  (____  /__|   |__|  
        \/          \/              \/            \/             
)";

    // Loop to create the glitch effect by printing the logo multiple times
    for (int i = 0; i < 10; ++i)
    {
        std::cout << RESET; // Clear screen and reset cursor to top

        // Random color from the colors array for each "glitch" print
        std::string color = colors[rand() % 5];
        clear(); // CLEAR THE TERMINAL
        std::cout << color << logo << RESET << std::endl;

        usleep(100000); // Delay between glitches (100 milliseconds)
    }
}

void Display::wait(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int Display::MainMenu()
{
    std::cout << RESET << std::endl;

    std::vector<std::string> options = {"New Game", "Load Game", "Exit"};
    bool running = true;
    while (running)
    {
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
int Display::buildingtypemenu()
{

    std::vector<std::string> options = {"Utility", "Industrial", "Residential", "Commercial"};
    bool running = true;
    while (running)
    {
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

void Display::displayMenu(std::vector<std::string> options)
{
    for (std::vector<std::string>::size_type i = 0; i < options.size(); i++)
    {
        std::cout << i + 1 << ". " << options[i] << std::endl;
    }
}

void Display::loadscreen()
{
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
     std::cout << std::endl;
}
int Display::Utilitymenu()
{
    cout << "Please select the utility you wish to build.\n";
    variant = "Utility";
    std::vector<std::string> options = {"PowerPlant", "LandFill", "SewagePlant", "WaterSupply"};
    bool running = true;
    while (running)
    {
        clear();
        logo();

        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        if (input == 1)
        {
            settype("PowerPlant");
        }
        else if (input == 2)
        {
            settype("LandFill");
        }
        else if (input == 3)
        {
            settype("SewagePlant");
        }
        else if (input == 4)
        {
            settype("WaterSupply");
        }
        else
        {
            cout << "Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;
}
int Display::Residentialmenu()
{
    cout << "Please select the residential property you wish to build.\n";
    variant = "Residential";
    std::vector<std::string> options = {"Apartment", "Estate", "House", "TownHouse"};
    bool running = true;
    while (running)
    {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        if (input == 1)
        {
            settype("Apartment");
        }
        else if (input == 2)
        {
            settype("Estate");
        }
        else if (input == 3)
        {
            settype("House");
        }
        else if (input == 4)
        {
            settype("TownHouse");
        }
        else
        {
            cout << "Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;
}
int Display::Commercialmenu()
{
    cout << "Please select the Commercial property you wish to build.\n";
    variant = "Commercial";
    std::vector<std::string> options = {"Store", "Mall", "Office"};
    bool running = true;
    while (running)
    {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;

        if (input == 1)
        {
            settype("Store");
        }
        else if (input == 2)
        {
            settype("Mall");
        }
        else if (input == 3)
        {
            settype("Office");
        }
        else
        {
            cout << "Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;
}
int Display::Industrialmenu()
{
    cout << "Please select the industrial property you wish to build.\n";
    variant = "Industrial";
    std::vector<std::string> options = {"Warehouse", "Factory", "Manufacturer"};
    bool running = true;
    while (running)
    {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        if (input == 1)
        {
            settype("Warehouse");
        }
        else if (input == 2)
        {
            settype("Factory");
        }
        else if (input == 3)
        {
            settype("Manufacturer");
        }
        else
        {
            cout << "Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;
}
int Display::LandMarkmenu()
{
    cout << "Please select the landmark you wish to build.\n";
    std::vector<std::string> options = {"Monument", "Park", "Cultural Center"};
    bool running = true;
    while (running)
    {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        if (input == 1)
        {
            settype("Monument");
        }
        else if (input == 2)
        {
            settype("Park");
        }
        else if (input == 3)
        {
            settype("Cultural Centre");
        }
        else
        {
            cout << "Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;
}
int Display::GameMenu()
{
    std::vector<std::string> options = {"Show buildings", "Create a building", "Upgrade a building", "Demolish a building", "Return to main menu"};
    bool running = true;
    while (running)
    {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        return input;
    }
    return -1;
}
