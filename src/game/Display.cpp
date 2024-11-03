#include "Display.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include "../../libs/tabulate/include/tabulate/table.hpp"
#include <stdlib.h>

/// constructor for display purposes
Display::Display() : map(Map::getInstance())
{
    stats = make_shared<Statistics>();
}

Display::~Display()
{
}

void Display::clear()
{
    system("clear");
}

int Display::getInput(int min, int max)
{
    int input;
    bool valid = false;

    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while (!valid)
    {
        stats->updateStats();
        std::cin >> input;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (errorCount == 7)
            {
                errorCount = 0;
            }
            std::cout << errorMsg[errorCount] << std::endl;
            errorCount++;
        }
        else if (input > max || input < min)
        {
            if (errorCount == 7)
            {
                errorCount = 0;
            }
            std::cout << errorMsg[errorCount] << std::endl;
            errorCount++;
        }
        else
        {
            valid = true;
            return input;
        }
    }
}

void Display::logo()
{
    std::cout << R"(
            _________ .__  __           _________                _____  __   
            \_   ___ \|__|/  |_ ___.__. \_   ___ \____________ _/ ____\/  |_ 
            /    \  \/|  \   __<   |  | /    \  \/\_  __ \__  \\   __\\   __\
            \     \___|  ||  |  \___  | \     \____|  | \// __ \|  |   |  |  
             \______  /__||__|  / ____|  \______  /|__|  (____  /__|   |__|  
                    \/          \/              \/            \/             
)" << std::endl;
}

void Display::displayMenu(string title, vector<string> options)
{
    for (int i = 0; i < options.size(); i++)
    {
        options[i] = to_string(i + 1) + ". " + options[i];
    }

    tabulate::Table menuOptions;
    if (options.size() == 1)
    {
        menuOptions.add_row({options[0]});
    }
    else if (options.size() == 2)
    {
        menuOptions.add_row({options[0], options[1]});
    }
    else if (options.size() == 3)
    {
        menuOptions.add_row({options[0], options[1], options[2]});
    }
    else if (options.size() == 4)
    {
        menuOptions.add_row({options[0], options[1], options[2], options[3]});
    }
    else if (options.size() == 5)
    {
        menuOptions.add_row({options[0], options[1], options[2], options[3], options[4]});
    }
    else if (options.size() == 6)
    {
        menuOptions.add_row({options[0], options[1], options[2], options[3], options[4], options[5]});
    }
    else if (options.size() == 7)
    {
        menuOptions.add_row({options[0], options[1], options[2], options[3], options[4], options[5], options[6]});
    }
    else if (options.size() == 8)
    {
        menuOptions.add_row({options[0], options[1], options[2], options[3], options[4], options[5], options[6], options[7]});
    }
    else if (options.size() == 9)
    {
        menuOptions.add_row({options[0], options[1], options[2], options[3], options[4], options[5], options[6], options[7], options[8]});
    }
    else if (options.size() == 10)
    {
        menuOptions.add_row({options[0], options[1], options[2], options[3], options[4], options[5], options[6], options[7], options[8], options[9]});
    }
    else
    {
        throw "Display::displayMenu: Too many options or no options";
    }

    menuOptions.format().width(20);
    menuOptions.format().font_align(tabulate::FontAlign::center);
    menuOptions.format().font_style({tabulate::FontStyle::bold});

    tabulate::Table menu;
    menu.add_row({title});
    menu.add_row({menuOptions});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
}
void Display::displayMenu(string title, string options)
{
    tabulate::Table menu;
    menu.add_row({title});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
}

void Display::displayTable(vector<vector<string>> table)
{
    tabulate::Table tab;
    int rowWidth = table[0].size();
    // check if all rows are the same width
    for (int i = 0; i < table.size(); i++)
    {
        if (table[i].size() != rowWidth)
        {
            throw "Display::displayTable: Rows are not the same width";
        }
        for (int j = 0; j < table[i].size(); j++)
        {
            if (table[i][j].empty())
            {
                table[i][j] = " ";
            }
            else if (table[i][j] == "")
            {
                table[i][j] = " ";
            }
        }
    }

    if (rowWidth == 1)
    {
        for (int i = 0; i < table.size(); i++)
        {
            tab.add_row({table[i][0]});
        }
    }
    else if (rowWidth == 2)
    {
        for (int i = 0; i < table.size(); i++)
        {
            tab.add_row({table[i][0], table[i][1]});
        }
    }
    else if (rowWidth == 3)
    {
        for (int i = 0; i < table.size(); i++)
        {
            tab.add_row({table[i][0], table[i][1], table[i][2]});
        }
    }
    else if (rowWidth == 4)
    {
        for (int i = 0; i < table.size(); i++)
        {
            tab.add_row({table[i][0], table[i][1], table[i][2], table[i][3]});
        }
    }
    else if (rowWidth == 5)
    {
        for (int i = 0; i < table.size(); i++)
        {
            tab.add_row({table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]});
        }
    }
    else
    {
        throw "Display::displayTable: Too many columns or no columns";
    }

    tab.format().width(20);
    tab.format().font_align(tabulate::FontAlign::center);
    tab.format().font_style({tabulate::FontStyle::bold});

    std::cout << tab << std::endl;
}
void Display::Display::displayRow(vector<string> row)
{
    tabulate::Table table;
    if (row.size() == 0)
    {
        throw "Display::displayRow: No data to display";
    }

    if (row.size() == 1)
    {
        table.add_row({row[0]});
        table[0][0].format().font_color(tabulate::Color::blue);
    }
    else if (row.size() == 2)
    {
        table.add_row({row[0], row[1]});
    }
    else if (row.size() == 3)
    {
        table.add_row({row[0], row[1], row[2]});
        table[0][2].format().font_color(tabulate::Color::blue);
    }
    else if (row.size() == 4)
    {
        table.add_row({row[0], row[1], row[2], row[3]});
    }
    else if (row.size() == 5)
    {
        table.add_row({row[0], row[1], row[2], row[3], row[4]});
    }
    else
    {
        throw "Display::displayRow: Too many columns or no columns";
    }

    table.format().width(21);
    table.format().font_align(tabulate::FontAlign::center);
    table.format().font_style({tabulate::FontStyle::bold});

    std::cout << table << std::endl;
}
void Display::wait(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int Display::MainMenu()
{
    clear();
    logo();

    displayMenu("Main Menu", {"New Game", "Load Game", "Save", "Exit"});
    int input = getInput(1, 4);
    return input;
}

void Display::loadscreen()
{
    for (int i = 0; i < 3; i++)
    {
        clear();
        logo();
        wait(1);
    }
}

int Display::GameMenu()
{

    clear();
    logo();

    displayStats();

    tabulate::Table options;
    options.add_row({"1. Build", "2. Upgrade", "3. View", "4. Destroy", "5. Government"});
    options.add_row({"6. Citizens", "7. Transport", "8. Detailed Stats", "9. Save", "10. Exit"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});

    tabulate::Table menu;
    menu.add_row({"Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input = getInput(1, 10);
    if (input == 1)
    {
        buildMenu();
    }
    else if (input == 2)
    {
        upgradeMenu();
    }
    else if (input == 3)
    {
        // viewMenu();
    }
    else if (input == 4)
    {
        // destroyMenu();
    }
    else if (input == 5)
    {
        governmentMenu();
    }
    else if (input == 6)
    {
        // citizensMenu();
    }
    else if (input == 7)
    {
        // transportMenu();
    }
    else if (input == 8)
    {
        // detailedStatsMenu();
    }
    else if (input == 9)
    {
        // saveMenu();
    }
    else if (input == 10)
    {
        // exitMenu();
    }
    else
    {
        std::cout << "Invalid option. Please try again." << std::endl;
    }

    return input;
}

void Display::displayStats()
{
    stats->updateStats();

    string money = "$" + to_string(stats->getMoney());
    string income = "$" + to_string(stats->getIncome());
    string population = to_string(stats->getPopulation()) + " / " + to_string(stats->getMaxPopulation());
    string satisfaction = to_string(stats->getSatisfaction()) + "%";
    string water = to_string(stats->getWaterConsumption()) + " / " + to_string(stats->getWaterSupply());
    string power = to_string(stats->getPowerConsumption()) + " / " + to_string(stats->getPowerSupply());
    string waste = to_string(stats->getWasteProduction()) + " / " + to_string(stats->getWasteCapacity());
    string sewage = to_string(stats->getSewageProduction()) + " / " + to_string(stats->getSewageCapacity());

    tabulate::Table stats;
    stats.add_row({"Money", "Income", "Population", "Satisfaction", "Water", "Electricity", "Waste", "Sewage"});
    stats.add_row({money, income, population, satisfaction, water, power, waste, sewage});

    stats.format().width(10);
    stats.format().font_align(tabulate::FontAlign::center);
    stats.format().font_style({tabulate::FontStyle::bold});

    tabulate::Table gridmap;

    string Apartment1 = check("Apartment", 1);
    string Apartment2 = check("Apartment", 2);
    string Apartment3 = check("Apartment", 3);
    string Apartment4 = check("Apartment", 4);
    string Apartment5 = check("Apartment", 5);

    string House1 = check("House", 1);
    string House2 = check("House", 2);
    string House3 = check("House", 3);

    string TownHouse1 = check("TownHouse", 1);
    string TownHouse2 = check("TownHouse", 2);
    string TownHouse3 = check("TownHouse", 3);

    string Store1 = check("Store", 1);
    string Store2 = check("Store", 2);
    string Store3 = check("Store", 3);
    string Store4 = check("Store", 4);
    string Store5 = check("Store", 5);
    string Store6 = check("Store", 6);
    string Store7 = check("Store", 7);

    string Office1 = check("Office", 1);
    string Office2 = check("Office", 2);
    string Office3 = check("Office", 3);

    string Mall1 = check("Mall", 1);
    string Mall2 = check("Mall", 2);

    string Factory1 = check("Factory", 1);
    string Factory2 = check("Factory", 2);
    string Factory3 = check("Factory", 3);
    string Factory4 = check("Factory", 4);

    string Manufacturer1 = check("Manufacturer", 1);
    string Manufacturer2 = check("Manufacturer", 2);

    string Warehouse1 = check("Warehouse", 1);
    string Warehouse2 = check("Warehouse", 2);
    string Warehouse3 = check("Warehouse", 3);
    string Warehouse4 = check("Warehouse", 4);

    string PowerPlant1 = check("PowerPlant", 1);
    string PowerPlant2 = check("PowerPlant", 2);
    string PowerPlant3 = check("PowerPlant", 3);
    string PowerPlant4 = check("PowerPlant", 4);

    string WaterSupply1 = check("WaterSupply", 1);
    string WaterSupply2 = check("WaterSupply", 2);
    string WaterSupply3 = check("WaterSupply", 3);
    string WaterSupply4 = check("WaterSupply", 4);

    string SewagePlant1 = check("SewagePlant", 1);
    string SewagePlant2 = check("SewagePlant", 2);
    string SewagePlant3 = check("SewagePlant", 3);
    string SewagePlant4 = check("SewagePlant", 4);

    string Landfill1 = check("Landfill", 1);
    string Landfill2 = check("Landfill", 2);
    string Landfill3 = check("Landfill", 3);
    string Landfill4 = check("Landfill", 4);

    string Park1 = check("Park", 1);
    string Park2 = check("Park", 2);

    string CulturalCenter1 = check("CulturalCenter", 1);
    string CulturalCenter2 = check("CulturalCenter", 2);

    string Monument1 = check("Monument", 1);
    string Monument2 = check("Monument", 2);

    string BusStation1 = check("Bus Station", 1);
    string BusStation2 = check("Bus Station", 2);

    string TrainStation1 = check("Train Station", 1);
    string TrainStation2 = check("Train Station", 2);

    string Airport1 = check("Airport", 1);
    string Airport2 = check("Airport", 2);

    string Estate = check("Estate", 1);

    // a1 to o15

    gridmap.add_row({Apartment1, Apartment1, "", House1, House1, House1, Apartment5, " ", House3, House3, TownHouse2, TownHouse2, "", Estate, Estate});
    gridmap.add_row({TownHouse1, TownHouse1, " ", House1, House1, House1, Apartment5, " ", House3, House3, TownHouse2, TownHouse2, "", Estate, Estate});
    gridmap.add_row({TownHouse1, TownHouse1, " ", House2, House2, House2, Apartment2, " ", House3, House3, TownHouse3, TownHouse3, "", Estate, Estate});
    gridmap.add_row({Apartment4, Apartment4, " ", House2, House2, House2, Apartment2, " ", Apartment3, Apartment3, TownHouse3, TownHouse3, "", Estate, Estate});
    gridmap.add_row({BusStation1, "", "", "", "", "", "", "", "", "", "", "", "", Estate, Estate});
    gridmap.add_row({Park1, CulturalCenter1, "", Monument1, Store3, Office2, Office2, "", Store5, Office3, Office3, Monument2, Park2, Estate, Estate});
    gridmap.add_row({Park1, CulturalCenter1, "", Monument1, Store4, Office2, Office2, "", Store6, Office3, Office3, Monument2, Park2, CulturalCenter2, CulturalCenter2});
    gridmap.add_row({Office1, Office1, "", Mall1, Mall1, Airport1, Airport1, "", "", "", "", "", "", "", BusStation2});
    gridmap.add_row({Office1, Office1, "", Mall1, Mall1, Airport1, Airport1, Mall2, Mall2, Mall2, Landfill1, Landfill2, "", WaterSupply1, WaterSupply2});
    gridmap.add_row({Store1, Store2, "", Mall1, Mall1, Store7, BusStation1, Mall2, Mall2, Mall2, Landfill3, Landfill4, "", WaterSupply3, WaterSupply4});
    gridmap.add_row({"", "", "", "", "", "", "", "", "", "", "", "", "", SewagePlant1, SewagePlant2});
    gridmap.add_row({TrainStation1, Warehouse1, Warehouse1, Factory1, Manufacturer1, Warehouse3, Warehouse3, Factory3, Manufacturer2, PowerPlant1, PowerPlant2, Airport2, Airport2, SewagePlant3, SewagePlant4});
    gridmap.add_row({TrainStation1, Warehouse2, Warehouse2, Factory2, Manufacturer1, Warehouse4, Warehouse4, Factory4, Manufacturer2, PowerPlant3, PowerPlant4, Airport2, Airport2, TrainStation2, TrainStation2});
    gridmap.add_row({"", "", "", "", "", "", "", "", "", "", "", "", "", "", ""});

    gridmap.format().width(12);
    gridmap.format().height(2);
    gridmap.format().font_align(tabulate::FontAlign::center);

    tabulate::Table Stats_and_map;
    Stats_and_map.add_row({stats});
    Stats_and_map.add_row({gridmap});

    std::cout << Stats_and_map << std::endl;
}

void Display::buildMenu()
{
    clear();
    logo();

    displayMenu("Build Menu", {"Residential", "Commercial", "Industrial", "Utility", "Landmark", "Infrastructure"});
    int input = getInput(1, 6);

    if (input == 1)
    {
        residentialMenu();
    }
    else if (input == 2)
    {
        commercialMenu();
    }
    else if (input == 3)
    {
        industrialMenu();
    }
    else if (input == 4)
    {
        utilityMenu();
    }
    else if (input == 5)
    {
        landmarkMenu();
    }
    else if (input == 6)
    {
        infrastructureMenu();
    }

    throw "Display::buildMenu: Invalid option";
}

void Display::residentialMenu()
{
    clear();
    logo();

    displayMenu("Residential Menu", {"Apartment", "Town House", "House"});

    int input = getInput(1, 3);

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;

    int money = stats->getMoney();
    if (input == 1)
    {
        if (money >= 100)
        {
            int count = map.numBuildings("Apartment");
            if (count >= 5)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Apartments" << std::endl;
                wait(1);
                GameMenu();
            }

            stats->setMoney(money - 100);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("Apartment", "Residential", 0, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            stats->updateStats();
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 2)
    {
        if (money >= 200)
        {
            int count = map.numBuildings("TownHouse");
            if (count >= 3)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Town Houses" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 200);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("TownHouse", "Residential", 1, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 3)
    {
        if (money >= 400)
        {
            int count = map.numBuildings("House");
            if (count >= 3)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Houses" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 400);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("House", "Residential", 2, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 4)
    {
        if (money >= 800)
        {
            stats->setMoney(money - 800);
            int count = map.numBuildings("Estate");
            if (count >= 1)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Estates" << std::endl;
                wait(1);
                GameMenu();
            }

            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("Estate", "Residential", 20, 0);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
}

void Display::commercialMenu()
{
    clear();
    logo();

    displayMenu("Commercial Menu", {"Store", "Office", "Mall"});
    int input = getInput(1, 3);

    int money = stats->getMoney();
    if (input == 1)
    {
        if (money >= 100)
        {
            int count = map.numBuildings("Store");
            if (count >= 7)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Stores" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 100);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("Store", "Commercial", 3, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 2)
    {
        if (money >= 200)
        {
            int count = map.numBuildings("Office");
            if (count >= 3)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Offices" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 200);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("Office", "Commercial", 4, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 3)
    {
        if (money >= 300)
        {
            int count = map.numBuildings("Mall");
            if (count >= 2)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Malls" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 300);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("Mall", "Commercial", 5, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
}

void Display::industrialMenu()
{
    clear();
    logo();

    displayMenu("Industrial Menu", {"Factory", "Warehouse", "Manufacturer"});
    int input = getInput(1, 3);
    int money = stats->getMoney();
    if (input == 1)
    {
        if (money >= 100)
        {
            int count = map.numBuildings("Factory");
            if (count >= 4)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Factories" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 100);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("Factory", "Industrial", 6, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 2)
    {
        if (money >= 200)
        {
            int count = map.numBuildings("Warehouse");
            if (count >= 4)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Warehouses" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 200);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("Warehouse", "Industrial", 7, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 3)
    {
        if (money >= 300)
        {
            stats->setMoney(money - 300);
            int count = map.numBuildings("Manufacturer");
            if (count >= 2)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Manufacturers" << std::endl;
                wait(1);
                GameMenu();
            }
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;

            map.build("Manufacturer", "Industrial", 8, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
}

void Display::utilityMenu()
{
    clear();
    logo();
    displayMenu("Utility Menu", {"Power Plant", "Water Supply", "Sewage Plant", "Landfill"});
    int input = getInput(1, 4);

    int money = stats->getMoney();
    if (input == 1)
    {
        if (money >= 100)
        {
            int count = map.numBuildings("PowerPlant");
            if (count >= 4)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Power Plants" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 100);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("PowerPlant", "Utility", 9, count);
            wait(1);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 2)
    {
        if (money >= 200)
        {
            int count = map.numBuildings("WaterSupply");
            if (count >= 4)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Water Supplies" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 200);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;

            map.build("WaterSupply", "Utility", 10, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 3)
    {
        if (money >= 300)
        {
            stats->setMoney(money - 300);
            int count = map.numBuildings("SewagePlant");
            if (count >= 4)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Sewage Plants" << std::endl;
                wait(1);
                GameMenu();
            }
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;

            map.build("SewagePlant", "Utility", 11, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 4)
    {
        if (money >= 400)
        {
            stats->setMoney(money - 400);
            int count = map.numBuildings("Landfill");
            if (count >= 4)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Landfills" << std::endl;
                wait(1);
                GameMenu();
            }
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;

            map.build("Landfill", "Utility", 12, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
}

void Display::landmarkMenu()
{
    clear();
    logo();
    displayMenu("Landmark Menu", {"Park", "Monument", "Cultural Center"});
    int input = getInput(1, 3);

    int money = stats->getMoney();
    if (input == 1)
    {
        if (money >= 100)
        {
            int count = map.numBuildings("Park");
            if (count >= 2)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Parks" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 100);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;

            map.build("Park", "Landmark", 13, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 2)
    {
        if (money >= 200)
        {
            int count = map.numBuildings("Monument");
            if (count >= 2)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Monuments" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 200);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("Monument", "Landmark", 14, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 3)
    {
        if (money >= 300)
        {
            int count = map.numBuildings("CulturalCenter");
            if (count >= 2)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Cultural Centers" << std::endl;
                wait(1);
                GameMenu();
            }

            stats->setMoney(money - 300);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("CulturalCenter", "Landmark", 15, count);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
}

void Display::infrastructureMenu()
{
    clear();
    logo();

    displayMenu("Infrastructure Menu", std::vector<std::string>{"Road", "Railway"});

    int input = getInput(1, 2);

    int money = stats->getMoney();
    if (input == 1)
    {
        if (money >= 100)
        {
            stats->setMoney(money - 100);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;

            map.build("Road", "Infrastructure", 0, 0);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
    else if (input == 2)
    {
        if (money >= 200)
        {
            stats->setMoney(money - 200);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("Railway", "Infrastructure", 0, 0);
            std::cout << "Construction finsihsed!!" << std::endl;
            wait(1);
            GameMenu();
        }
        else
        {
            std::cout << "Can't do that" << std::endl;
            wait(1);
            std::cout << "You're too Broke." << std::endl;
            wait(1);
            std::cout << "Go Hustle Big Guy" << std::endl;
            wait(2);
            GameMenu();
        }
    }
}

string Display::check(string var, int num)
{
    int count = map.numBuildings(var);
    if (count >= num)
    {
        return var + " " + to_string(num);
    }
    else
    {
        return "";
    }
}

void Display::upgradeMenu()
{
    clear();
    logo();

    vector<string> apartmentUpgrades = getUpgrades("Apartment", 1);
}

vector<string> Display::getUpgrades(string var, int num)
{
    vector<string> upgrades;
    int count = map.numBuildings(var);
    if (count >= num)
    {
    }
    else
    {
        return upgrades;
    }
}

void Display::governmentMenu()
{
    clear();
    logo();

    displayMenu("Government Menu", {"Tax", "Policies", "Services", "Budget", "Statistics", "Back"});
    int input = getInput(1, 6);

    if (input == 1)
    {
        taxMenu();
    }
    else if (input == 2)
    {
        policiesMenu();
    }
    else if (input == 3)
    {
        servicesMenu();
    }
    else if (input == 4)
    {
        budgetMenu();
    }
    else if (input == 5)
    {
        statisticsMenu();
    }
    else if (input == 6)
    {
        GameMenu();
    }
}

void Display::taxMenu()
{
    clear();
    logo();

    displayTaxStats();
    displayMenu("Tax Menu", {"Business", "Personal", "Back"});

    int input = getInput(1, 3);
    switch (input)
    {
    case 1:
        businessTaxMenu();
        break;
    case 2:
        personalTaxMenu();
        break;
    case 3:
        governmentMenu();
        break;
    }
}

void Display::displayTaxStats()
{
    vector<string> taxStats;
    taxStats.push_back("Business Tax:");
    string bTax = std::to_string(stats->getGovernment()->getBusinessTaxRate()) + "%";
    taxStats.push_back(bTax);
    taxStats.push_back("Personal Tax:");
    string pTax = std::to_string(stats->getGovernment()->getPersonalTaxRate()) + "%";
    taxStats.push_back(pTax);
    displayRow(taxStats);

    // availble for collection
    tabulate::Table taxTable;
    string business = std::to_string(stats->getUncollectedTax("business"));
    string personal = std::to_string(stats->getUncollectedTax("personal"));
    taxTable.add_row({"Business: ", business, "Personal: ", personal});

    taxTable.format().font_align(tabulate::FontAlign::center);
    taxTable[0][0].format().font_color(tabulate::Color::blue);

    tabulate::Table uncollected;
    uncollected.add_row({"Uncollected Taxes"});
    uncollected.add_row({taxTable});
    uncollected.format().font_align(tabulate::FontAlign::center);
    uncollected[0][0].format().font_color(tabulate::Color::blue);
    std::cout << uncollected << std::endl;
}
void Display::businessTaxMenu()
{
    clear();
    logo();

    displayTaxStats();
    displayMenu("Business Tax Menu", {"Increase", "Decrease", "Collect", "Back"});
    int input = getInput(1, 4);

    if (input == 1)
    {
        std::cout << "What do you want to increase the current tax rate by?" << std::endl;
        double Increase = getInput(0, 100);
        while (Increase + stats->getGovernment()->getBusinessTaxRate() > 100)
        {
            std::cout << "The total tax rate cannot exceed 100%. Please enter a lower value." << std::endl;
            Increase = getInput(0, 100);
        }
        stats->changeBusinessTax(Increase, "increase");
        businessTaxMenu();
    }
    else if (input == 2)
    {
        std::cout << "What do you want to decrease the current tax rate by?" << std::endl;
        double Decrease = getInput(0, stats->getGovernment()->getBusinessTaxRate());
        while (Decrease + stats->getGovernment()->getBusinessTaxRate() < 0)
        {
            std::cout << "The total tax rate cannot be negative. Please enter a lower value." << std::endl;
            Decrease = getInput(0, stats->getGovernment()->getBusinessTaxRate());
        }
        stats->changeBusinessTax(Decrease, "decrease");
        businessTaxMenu();
    }
    else if (input == 3)
    {
        stats->collectBusinessTax();
        businessTaxMenu();
    }
    else if (input == 4)
    {
        taxMenu();
    }
}

void Display::personalTaxMenu()
{
    clear();
    logo();
    displayTaxStats();
    displayMenu("Personal Tax Menu", {"Increase", "Decrease", "Collect", "Back"});

    int input = getInput(1, 4);

    switch (input)
    {
    case 1:
    { // Increase tax
        double Increase;
        std::cout << "What do you want to increase the current tax rate by?" << std::endl;
        while (true)
        {
            std::cin >> Increase;

            if (std::cin.fail() || Increase <= 0)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a positive value to increase the tax rate." << std::endl;
            }
            else
            {
                break;
            }
        }
        stats->changePersonalTax(Increase, "increase");
        personalTaxMenu();
        break;
    }
    case 2:
    { // Decrease tax
        double Decrease;
        std::cout << "What do you want to decrease the current tax rate by?" << std::endl;
        while (true)
        {
            std::cin >> Decrease;

            if (std::cin.fail() || Decrease <= 0)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a positive value to decrease the tax rate." << std::endl;
            }
            else
            {
                break;
            }
        }
        stats->changePersonalTax(Decrease, "decrease");
        personalTaxMenu();
        break;
    }
    case 3: // Collect tax
        stats->collectPersonalTax();
        personalTaxMenu();
        break;
    case 4: // Back to tax menu
        taxMenu();
        break;
    }
}

void Display::policiesMenu()
{
    clear();
    logo();
    
    if (stats->getImplementedPolicies().empty())
    {

        displayRow({"No policies have been implemented."});
    }
    else
    {
        displayTable(stats->getImplementedPolicies());
    }
    
    if (stats->getAvailablePolicies().empty())
    {
        displayRow({"No policies available to implement."});
        std::cout << "Press any key to go back." << std::endl;
        std::cin.ignore();
        std::cin.get();
        governmentMenu();
    }
    else
    {
        displayMenu("Policies Menu", stats->getAvailablePolicies());
        int input = getInput(1, stats->getAvailablePolicies().size());
        string implementedPolicy = stats->implementPolicy(stats->getAvailablePolicies()[input - 1]);
        std::cout << implementedPolicy << " has been implemented." << std::endl;
        policiesMenu();
    }
}

void Display::servicesMenu()
{
    clear();
    logo();

    displayMenu("Services Menu", {"Police", "Education", "Healthcare", "Back"});

    int input = getInput(1, 4);

    string answer;
    switch (input)
    {
    case 1:
        std::cout << "Would you like to add or remove funds to the Police? (Add/Remove)" << std::endl;
        while (true)
        {
            std::cin >> answer;
            transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

            if (answer == "add")
            {
                stats->changeBudget("police", "increase");
                break;
            }
            else if (answer == "remove")
            {
                stats->changeBudget("police", "decrease");
                break;
            }
            else
            {
                std::cout << "Invalid input. Please enter 'Add' or 'Remove'." << std::endl;
            }
        }
        break;
    case 2:
        std::cout << "Would you like to add or remove funds to the Education? (Add/Remove)" << std::endl;
        while (true)
        {
            std::cin >> answer;
            transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

            if (answer == "add")
            {
                stats->changeBudget("education", "increase");
                break;
            }
            else if (answer == "remove")
            {
                stats->changeBudget("education", "decrease");
                break;
            }
            else
            {
                std::cout << "Invalid input. Please enter 'Add' or 'Remove'." << std::endl;
            }
        }
        break;
    case 3:
        std::cout << "Would you like to add or remove funds to the Healthcare? (Add/Remove)" << std::endl;
        while (true)
        {
            std::cin >> answer;
            transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

            if (answer == "add")
            {
                stats->changeBudget("healthcare", "increase");
                break;
            }
            else if (answer == "remove")
            {
                stats->changeBudget("healthcare", "decrease");
                break;
            }
            else
            {
                std::cout << "Invalid input. Please enter 'Add' or 'Remove'." << std::endl;
            }
        }
        break;
    case 4:
        cout << "Exiting menu." << endl;
        governmentMenu();
        break;
    default:
        break;
    }
}

void Display::budgetMenu()
{
    throw "Budget Menu not implemented";
}

void Display::statisticsMenu()
{
    throw "Statistics Menu not implemented";
}
