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

    int easterEgg = 0;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    vector<string> easterEggMsg = {"Oh no..","I can feel something coming..","My spidey senses are tingling..", "whoooo...."};
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
                easterEgg++;
                if (easterEgg == 2)
                {
                    errorMsg = easterEggMsg;
                }
                if (easterEgg == 3)
                {
                    easterMenu();
                }
                
            }
            std::cout << errorMsg[errorCount] << std::endl;
            errorCount++;
        }
        else if (input > max || input < min)
        {
            if (errorCount == 7)
            {
                errorCount = 0;
                easterEgg++;
                if (easterEgg == 2)
                {
                    errorMsg = easterEggMsg;
                }
                if (easterEgg == 3)
                {
                    easterMenu();
                }
         
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
    throw "Display::getInput: Invalid input";
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
                                                                                              By Shift Happens      
)" << std::endl;
}

void Display::displayMenu(string title, vector<string> options)
{
    for (std::vector<std::string>::size_type i = 0; i < options.size(); i++)
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
    std::vector<std::string>::size_type rowWidth = table[0].size();
    // check if all rows are the same width

    for (std::vector<std::vector<std::string>>::size_type i = 0; i < table.size(); i++)
    {

        if (table[i].size() != rowWidth)
        {
            throw "Display::displayTable: Rows are not the same width";
        }

        for (std::vector<std::string>::size_type j = 0; j < table[i].size(); j++)
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
        for (std::vector<std::vector<std::string>>::size_type i = 0; i < table.size(); i++)
        {
            tab.add_row({table[i][0]});
        }
    }
    else if (rowWidth == 2)
    {
        for (std::vector<std::vector<std::string>>::size_type i = 0; i < table.size(); i++)
        {
            tab.add_row({table[i][0], table[i][1]});
        }
    }
    else if (rowWidth == 3)
    {
        for (std::vector<std::vector<std::string>>::size_type i = 0; i < table.size(); i++)
        {
            tab.add_row({table[i][0], table[i][1], table[i][2]});
        }
    }
    else if (rowWidth == 4)
    {
        for (std::vector<std::vector<std::string>>::size_type i = 0; i < table.size(); i++)
        {
            tab.add_row({table[i][0], table[i][1], table[i][2], table[i][3]});
        }
    }
    else if (rowWidth == 5)
    {

        for (std::vector<std::vector<std::string>>::size_type i = 0; i < table.size(); i++)
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
    intro();
    logo();

    GameMenu();
    return 0;
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
    options.add_row({"1. Build", "2. View", "3. Destroy", "4. Government"});
    options.add_row({"5. Citizens", "6. Transport", "7. Exit"});
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
    int input = getInput(1, 7);
    if (input == 1)
    {
        buildMenu();
    }
    else if (input == 2)
    {
        viewMenu();
    }
    else if (input == 3)
    {
        destroyMenu();
    }
    else if (input == 4)
    {
        governmentMenu();
    }
    else if (input == 5)
    {
        CitizenMenu();
    }
    else if (input == 6)
    {
        transportMenu();
    }
    else if (input == 7)
    {
        return 0;
    }
    else
    {
        std::cout << "Invalid option. Please try again." << std::endl;
    }

    return input;
}

void Display::CitizenMenu(){
    stats->updateStats();
    clear();
    logo();
    vector<string> options ;
    std::string input = "Back";
    options.push_back(input);
    

    vector<vector<string>> citizenInfo;
    double CitizenSatisfaction = stats->getGovernment()->getSatisfaction();
    
    // satisfaction
    vector<string> temp ;
    temp.push_back("Satisfaction of citizens: "+ to_string(stats->getGovernment()->getSatisfaction()));
    temp.push_back("Employment rate: "+ to_string(stats->getGovernment()->getUnemployment()));
    temp.push_back("In school rate: "+ to_string(stats->getGovernment()->getSchoolStats()));

    citizenInfo.push_back(temp);

    displayTable(citizenInfo);
    displayMenu("Citizen Menu", options);
    int Input = getInput(1, 1);
    if (Input == 1)
    {
        GameMenu();
    }
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

    tabulate::Table statistics;
    statistics.add_row({"Money", "Income", "Population", "Satisfaction", "Water", "Electricity", "Waste", "Sewage"});
    statistics.add_row({money, income, population, satisfaction, water, power, waste, sewage});

    statistics.format().width(10);
    statistics.format().font_align(tabulate::FontAlign::center);
    statistics.format().font_style({tabulate::FontStyle::bold});

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

    vector<string> road;
    vector<string> railway;

    for (int i = 0; i < 53; i++)
    {
        string roadstr = check("Road", i + 1);
        road.push_back(roadstr);
    }

    for(int i = 0; i < 15; i++){
        string railwaystr = check("Railway", i + 1);
        railway.push_back(railwaystr);
    }

    // a1 to o15

    gridmap.add_row({Apartment1, Apartment1, road[0], House1, House1, House1, Apartment5, road[1], House3, House3, TownHouse2, TownHouse2, road[2], Estate, Estate});
    gridmap.add_row({TownHouse1, TownHouse1, road[3], House1, House1, House1, Apartment5, road[4], House3, House3, TownHouse2, TownHouse2, road[5], Estate, Estate});
    gridmap.add_row({TownHouse1, TownHouse1, road[6], House2, House2, House2, Apartment2, road[7], House3, House3, TownHouse3, TownHouse3, road[8], Estate, Estate});
    gridmap.add_row({Apartment4, Apartment4, road[9], House2, House2, House2, Apartment2, road[10], Apartment3, Apartment3, TownHouse3, TownHouse3, road[11], Estate, Estate});
    gridmap.add_row({BusStation1, road[12], road[13], road[14], road[15], road[16], road[17], road[18], road[19], road[20], road[21], road[22], road[23], Estate, Estate});
    gridmap.add_row({Park1, CulturalCenter1, road[24], Monument1, Store3, Office2, Office2, road[25], Store5, Office3, Office3, Monument2, Park2, Estate, Estate});
    gridmap.add_row({Park1, CulturalCenter1, road[26], Monument1, Store4, Office2, Office2, road[27], Store6, Office3, Office3, Monument2, Park2, CulturalCenter2, CulturalCenter2});
    gridmap.add_row({Office1, Office1, road[28], Mall1, Mall1, Airport1, Airport1, road[29], road[30], road[31], road[32], road[33], road[34], road[35], BusStation2});
    gridmap.add_row({Office1, Office1, road[36], Mall1, Mall1, Airport1, Airport1, Mall2, Mall2, Mall2, Landfill1, Landfill2, road[37], WaterSupply1, WaterSupply2});
    gridmap.add_row({Store1, Store2, road[38], Mall1, Mall1, Store7, BusStation1, Mall2, Mall2, Mall2, Landfill3, Landfill4, road[39], WaterSupply3, WaterSupply4});
    gridmap.add_row({road[40], road[41], road[42], road[43], road[44], road[45], road[46], road[47], road[48], road[49], road[50], road[51], road[52], SewagePlant1, SewagePlant2});
    gridmap.add_row({TrainStation1, Warehouse1, Warehouse1, Factory1, Manufacturer1, Warehouse3, Warehouse3, Factory3, Manufacturer2, PowerPlant1, PowerPlant2, Airport2, Airport2, SewagePlant3, SewagePlant4});
    gridmap.add_row({TrainStation1, Warehouse2, Warehouse2, Factory2, Manufacturer1, Warehouse4, Warehouse4, Factory4, Manufacturer2, PowerPlant3, PowerPlant4, Airport2, Airport2, TrainStation2, TrainStation2});
    gridmap.add_row({railway[0], railway[1], railway[2], railway[3], railway[4], railway[5], railway[6], railway[7], railway[8], railway[9], railway[10], railway[11], railway[12], railway[13], railway[14]});

    gridmap.format().width(10);
    gridmap.format().height(2);
    gridmap.format().font_align(tabulate::FontAlign::center);

    tabulate::Table Stats_and_map;
    Stats_and_map.add_row({statistics});
    Stats_and_map.add_row({gridmap});

    std::cout << gridmap << std::endl;
    std::cout << statistics << std::endl;
}

void Display::buildMenu()
{
    clear();
    logo();

    displayMenu("Build Menu", {"Residential", "Commercial", "Industrial", "Utility", "Landmark", "Infrastructure", "Back"});
    int input = getInput(1, 7);

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
    }else if(input == 7){
        GameMenu();
    }
    else
    {
        throw "Display::buildMenu: Invalid option";
    }

}

void Display::residentialMenu()
{
    clear();
    logo();

    displayMenu("Residential Menu", {"Apartment", "Town House", "House","Estate", "Back"});

    int input = getInput(1, 5);

    

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
    }else if(input == 5){
        buildMenu();
    }
    else
    {
        throw "Display::residentialMenu: Invalid option";
    }
}

void Display::commercialMenu()
{
    clear();
    logo();

    displayMenu("Commercial Menu", {"Store", "Office", "Mall", "Back"});
    int input = getInput(1, 4);

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
    else if(input == 4){
        buildMenu();
    }
    else
    {
        throw "Display::commercialMenu: Invalid option";
    }
}

void Display::industrialMenu()
{
    clear();
    logo();

    displayMenu("Industrial Menu", {"Factory", "Warehouse", "Manufacturer", "Back"});
    int input = getInput(1, 4);
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
    else if(input == 4){
        buildMenu();
    }
    else
    {
        throw "Display::industrialMenu: Invalid option";
    }
}

void Display::utilityMenu()
{
    clear();
    logo();
    displayMenu("Utility Menu", {"Power Plant", "Water Supply", "Sewage Plant", "Landfill", "Back"});
    int input = getInput(1, 5);

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
    else if(input == 5){
        buildMenu();
    }
    else
    {
        throw "Display::utilityMenu: Invalid option";
    }
}

void Display::landmarkMenu()
{
    clear();
    logo();
    displayMenu("Landmark Menu", {"Park", "Monument", "Cultural Center", "Back"});
    int input = getInput(1, 4);

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
    else if(input == 4){
        buildMenu();
    }
    else
    {
        throw "Display::landmarkMenu: Invalid option";
    }
}

void Display::infrastructureMenu()
{
    clear();
    logo();

    displayMenu("Infrastructure Menu", std::vector<std::string>{"Road", "Railway", "Back"});

    int input = getInput(1, 3);

    int money = stats->getMoney();
    if (input == 1)
    {
        if (money >= 100)
        {   
            int count = map.numBuildings("Road");
            if (count >= 53)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Roads" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 100);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            if(count < 25){
                map.build("Road", "Infrastructure", 16, count);
            }
            else{
                map.build("Road", "Infrastructure", 24, count);
            }
            map.build("Road", "Infrastructure", 17, count);
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
            int count = map.numBuildings("Railway");
            if (count >= 15)
            {
                std::cout << "Can't do that" << std::endl;
                wait(1);
                std::cout << "You've reached the maximum number of Railways" << std::endl;
                wait(1);
                GameMenu();
            }
            stats->setMoney(money - 200);
            std::cout << "Construction Worker: Why am I always doing this backbreaking work?" << std::endl;
            wait(1);
            std::cout << "Construction Worker: I should have listened to my mother and become a doctor." << std::endl;
            std::cout << "Building.." << std::endl;
            map.build("Railway", "Infrastructure", 18, count);
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
    else if(input == 3){
        buildMenu();
    }
    else
    {
        throw "Display::infrastructureMenu: Invalid option";
    }
}

string Display::check(string var, int num)
{
    if (var == "Road")
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

void Display::viewMenu()
{
    //this menu needs to show the mapComponents' contents, so once a building is created we should be able to view
    //it's citizens, income generated, etc. any relevant attributes pertaining to that particular component

    vector<int> buildingIds;
    vector<string> buildingTypes;
    vector<vector<shared_ptr<MapComponent>>> tiles = map.getTiles();
    for (int i = 0; i < tiles.size(); i++)
    {
        for (int j = 0; j < tiles[i].size(); j++)
        {
            if (tiles[i][j] != nullptr)
            {
                buildingIds.push_back(tiles[i][j]->getId());
                buildingTypes.push_back(tiles[i][j]->getType());
            }
        }
    }
    if(buildingIds.size() == 0){
        cout << "No Buildings currently on the map. Redirecting to GameMenu" << endl;
        wait(1);
        GameMenu();
    }
    // display the building ids and types in a table next to each other with the building ids in the first column and the building types in the second column using a number for the index from 1 onwards
    tabulate::Table buildingTable;
    buildingTable.add_row({"Building ID", "Building Type"});
    for (int i = 0; i < buildingIds.size(); i++)
    {
        buildingTable.add_row({to_string(i + 1), buildingTypes[i]});
    }
    buildingTable.format().font_align(tabulate::FontAlign::center);
    std::cout << buildingTable << std::endl;

    std::cout << "Enter the number of the building you want to view" << std::endl;
    int input = getInput(1, buildingIds.size());
    map.view(buildingIds[input - 1]);

    std::cout << "Press any key to go back." << std::endl;
    std::cin.ignore();
    std::cin.get();
    GameMenu();
}

void Display::destroyMenu()
{
    // get all the tiles and dereference the non null tile pointers and add their building ids to a vector
    // display the building ids to the user as well as the building type to which that id belongs
    // ask the user to select a building to destroy
    // get the building id from the user
    // get the building type from the building id
    // remove the building from the map using the destroy(int id) function

    vector<int> buildingIds;
    vector<string> buildingTypes;
    vector<vector<shared_ptr<MapComponent>>> tiles = map.getTiles();
    for (int i = 0; i < tiles.size(); i++)
    {
        for (int j = 0; j < tiles[i].size(); j++)
        {
            if (tiles[i][j] != nullptr)
            {
                buildingIds.push_back(tiles[i][j]->getId());
                buildingTypes.push_back(tiles[i][j]->getType());
            }
        }
    }
    if(buildingIds.size() == 0){
        cout << "No Buildings currently on the map. Redirecting to GameMenu" << endl;
        wait(1);
        GameMenu();
    }
    // display the building ids and types in a table next to each other with the building ids in the first column and the building types in the second column using a number for the index from 1 onwards
    tabulate::Table buildingTable;
    buildingTable.add_row({"Building ID", "Building Type"});
    for (int i = 0; i < buildingIds.size(); i++)
    {
        buildingTable.add_row({to_string(i + 1), buildingTypes[i]});
    }
    buildingTable.format().font_align(tabulate::FontAlign::center);
    
    std::cout << buildingTable << std::endl;

    std::cout << "Enter the number of the building you want to destroy" << std::endl;
    int input = getInput(1, buildingIds.size());
    map.destroy(buildingIds[input - 1]);
    GameMenu();
}

void Display::governmentMenu()
{
    clear();
    logo();

    displayMenu("Government Menu", {"Tax", "Policies", "Services","Back"});
    int input = getInput(1, 4);

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
        GameMenu();
    }
}

void Display::taxMenu()
{
    clear();
    logo();

    //displayTaxStats();
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


void Display::displayPoliceStats()
{
    vector<string> taxStats;
    // taxStats.push_back("Business Tax:");
    // string bTax = std::to_string(stats->getGovernment()->getBusinessTaxRate()) + "%";
    // taxStats.push_back(bTax);
    taxStats.push_back("Current Police state:");
    string policestate = stats->getGovernment()->getPolice()->getState()->getType();
    taxStats.push_back(policestate);
    taxStats.push_back("Current Police running budget: ");
    string budget = to_string(stats->getGovernment()->getPolice()->getState()->getRunningBudget());
    taxStats.push_back(budget);

    vector<string> taxStats2;
    taxStats2.push_back("Current Education state:");
    string educationstate = stats->getGovernment()->getEducation()->getState()->getType();
    taxStats2.push_back(educationstate);
    taxStats2.push_back("Current Education running budget: ");
    string budgetE = to_string(stats->getGovernment()->getEducation()->getState()->getRunningBudget());
    taxStats2.push_back(budgetE);

    vector<string> taxStats3;
    taxStats3.push_back("Current Healthcare state:");
    string HCstate = stats->getGovernment()->getHealthCare()->getState()->getType();
    taxStats3.push_back(HCstate);
    taxStats3.push_back("Current Healthcare running budget: ");
    string budgetHC = to_string(stats->getGovernment()->getHealthCare()->getState()->getRunningBudget());
    taxStats3.push_back(budgetHC);

    displayRow(taxStats);
    displayRow(taxStats2);
    displayRow(taxStats3);
}


void Display::displayTaxStats()
{   
    stats->updateStats();
    vector<string> taxStats;
    // taxStats.push_back("Business Tax:");
    // string bTax = std::to_string(stats->getGovernment()->getBusinessTaxRate()) + "%";
    // taxStats.push_back(bTax);
    taxStats.push_back("Personal Tax:");
    string pTax = std::to_string(stats->getGovernment()->getPersonalTaxRate()) + "%";
    taxStats.push_back(pTax);
    taxStats.push_back("Personal Tax state:");
    string state = stats->getGovernment()->getTax()->getType();
    taxStats.push_back(state);
    displayRow(taxStats);

    // availble for collection
    tabulate::Table taxTable;
    string business = std::to_string(stats->getUncollectedTax("business"));
    string personal = std::to_string(stats->getUncollectedTax("personal"));
    taxTable.add_row({"Personal: ", personal});

    taxTable.format().font_align(tabulate::FontAlign::center);
    taxTable[0][0].format().font_color(tabulate::Color::blue);

    tabulate::Table uncollected;
    uncollected.add_row({"Uncollected Taxes"});
    uncollected.add_row({taxTable});
    uncollected.format().font_align(tabulate::FontAlign::center);
    uncollected[0][0].format().font_color(tabulate::Color::blue);
    std::cout << uncollected << std::endl;
}

void Display::displayTaxStatsBusiness()
{
    vector<string> taxStats;
    taxStats.push_back("Business Tax:");
    string bTax = std::to_string(stats->getGovernment()->getBusinessTaxRate()) + "%";
    taxStats.push_back(bTax);
    // taxStats.push_back("Personal Tax:");
    // string pTax = std::to_string(stats->getGovernment()->getPersonalTaxRate()) + "%";
    // taxStats.push_back(pTax);
    taxStats.push_back("Business Tax state:");
    string state = stats->getGovernment()->getBusinessTax()->getType();
    taxStats.push_back(state);
    displayRow(taxStats);

    // availble for collection
    tabulate::Table taxTable;
    string business = std::to_string(stats->getUncollectedTax("business"));
    string personal = std::to_string(stats->getUncollectedTax("personal"));
    taxTable.add_row({"Business: ", business});

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

    displayTaxStatsBusiness();
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
        stats->updateStats();
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
        stats->updateStats();
        personalTaxMenu();
        break;
    }
    case 3: // Collect tax
        stats->collectPersonalTax();
        stats->updateStats();
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

    if (stats->getImplementedPolicies().size() == 0)
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
        vector<string> policies = stats->getAvailablePolicies();
        policies.push_back("Back");
        displayMenu("Policies Menu", policies);
        int input = getInput(1, policies.size());
        if (input == policies.size())
        {
            governmentMenu();
        }
        else
        {
            string implementedPolicy = stats->implementPolicy(stats->getAvailablePolicies()[input - 1]);
            std::cout << implementedPolicy << " has been implemented." << std::endl;
            policiesMenu();
        }
        
       
    }
}

void Display::servicesMenu()
{
    clear();
    logo();
    displayPoliceStats();
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
                servicesMenu();
                break;
            }
            else if (answer == "remove")
            {
                stats->changeBudget("police", "decrease");
                servicesMenu();
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
                servicesMenu();
                break;
            }
            else if (answer == "remove")
            {
                stats->changeBudget("education", "decrease");
                servicesMenu();
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
                servicesMenu();
                break;
            }
            else if (answer == "remove")
            {
                stats->changeBudget("healthcare", "decrease");
                servicesMenu();
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

void Display::transportMenu() 
{
    clear();
    logo();
    
    int distance;
    int capacity;
    
    // Step 1: Ask the user for distance in kmss
    cout << "Enter the distance you wish to travel (in km): ";
    while (!(cin >> distance) || distance <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer for distance: ";
    }

    // Step 2: Ask the user for num people
    cout << "Enter the number of people traveling (including yourself): ";
    while (!(cin >> capacity) || capacity <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer for capacity: ";
    }

    // Step 3: Options based on what user put in distance capacity
    clear();
    logo();
    
    cout << "Here are the available Transport options for:" << endl;
    cout << "Passengers: " << capacity << "." << endl;
    cout <<  "Distance: " << distance << "km." << endl;
    cout << "Select your transport option:\n";
    int optionCount = 1;

    // Statistics obj to hold chosen strategy
    Statistics stats;

    // Checking more for the trasport optons to display
    if (distance <= 150) {
        // Car
        auto carStrategy = make_shared<RoadStrategy>();
        if (capacity >= carStrategy->getCapacityMin() && capacity <= carStrategy->getCapacityMax()) {
            cout << optionCount << ". Car\n";
            optionCount++;
        }

        // Taxi option
        auto taxiStrategy = make_shared<PublicStrategy>();
        if (capacity >= taxiStrategy->getCapacityMin() && capacity <= taxiStrategy->getCapacityMax()) {
            cout << optionCount << ". Taxi\n";
            optionCount++;
        }

        // Train option
        auto trainStrategy = make_shared<TrainStrategy>();
        if (capacity >= trainStrategy->getCapacityMin() && capacity <= trainStrategy->getCapacityMax()) {
            cout << optionCount << ". Train\n";
            optionCount++;
        }
    }

    // Include Airplane if distance is more than 150 km
    if (distance > 150) {
        auto airplaneStrategy = make_shared<AirStrategy>();
        if (capacity >= airplaneStrategy->getCapacityMin() && capacity <= airplaneStrategy->getCapacityMax()) {
            std::cout << optionCount << ". Airplane\n";
            optionCount++;
        }
    }


    // Step 4: transport choice, getting from user
    int transportChoice;
    cout << "Please enter the NUMBER of your choice: ";
    cin >> transportChoice;
    while (cin.fail() || transportChoice < 1 || transportChoice >= optionCount) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter a valid option: ";
        cin >> transportChoice;
    }

    // Set the chosen strategy based on user input
    switch (transportChoice) {
    case 1:
        stats.setStrategy(make_shared<RoadStrategy>());
        break;
    case 2:
        stats.setStrategy(make_shared<PublicStrategy>());
        break;
    case 3:
        stats.setStrategy(make_shared<TrainStrategy>());
        break;
    case 4:
        stats.setStrategy(make_shared<AirStrategy>());
        break;
    default:
        cerr << "Invalid choice of transportation." << endl;
        break;
}

 // Step 5: Display travel details
    stats.displayOption(distance);      //this will display the est cost, an all from the statistcs
    cout << "Do you want to proceed with this travel? (yes/no): ";
    string confirm;
    cin >> confirm;

    if (confirm == "yes" || confirm == "y" || confirm == "Yes") {
        cout << "Travel confirmed! Your journey has begun.\n";
        wait(2);
        cout << "Arrived at your destination." << endl;
        wait(2);
        MainMenu();
    } else {
        cout << "Travel cancelled.\n";
    }
}

void Display::intro()
{
std::cout << R"(
///\\          \  /::\\ \_\ \\_:/:\:\:/_____ //:\ \                 /\  /\  /\
//:/\\          \//\::\\ \ \ \\/:\:\:/_____ //:::\ \               /  \/  \/+/
/:/:/\\_________/:\/:::\`----' \\:\:/_____ //o:/\:\ \_____________/\  /\  / /
:/:/://________//\::/\::\_______\\:/_____ ///\_\ \:\/____________/  \/  \/+/\
/:/:///_/_/_/_/:\/::\ \:/__  __ /:/_____ ///\//\\/:/ _____  ____/\  /\  / /  \
:/:///_/_/_/_//\::/\:\///_/ /_//:/______/_/ :~\/::/ /____/ /___/  \/  \/+/\  /)";
wait(1);
std::cout << R"(
/:///_/_/_/_/:\/::\ \:/__  __ /:/____/\  / \\:\/:/ _____  ____/\  /\  / /  \/
:///_/_/_/_//\::/\:\///_/ /_//:/____/\:\____\\::/ /____/ /___/  \/  \/+/\  /\
///_/_/_/_/:\/::\ \:/__  __ /:/____/\:\/____/\\/____________/\  /\  / /  \/  \
//_/_/_/_//\::/\:\///_/ /_//::::::/\:\/____/  /----/----/--/  \/  \/+/\  /\  /
/_/_/_/_/:\/::\ \:/__  __ /\:::::/\:\/____/ \/____/____/__/\  /\  / /  \/  \/_
_/_/_/_//\::/\:\///_/ /_//\:\::::\:\/____/ \_____________/  \/  \/+/\  /\  /     )";
wait(1);
std::cout << R"(
/_/_/_/:\/::\ \:/__  __ /\:\:\::::\/____/   \ _ _ _ _ _ /\  /\  / /  \/  \/___
_/_/_//\::/\:\///_/ /_//\:\:\:\              \_________/  \/  \/+/\  /\  /   /
/_/_/:\/::\ \:/__  __ /\:\:\:\:\______________\       /\  /\  / /  \/  \/___/_
_/_//\::/\:\///_/ /_//::\:\:\:\/______________/      /  \/  \/+/\  /\  /   /
/_/:\/::\ \:/__  __ /::::\:\:\/______________/\     /\  /\  / /  \/  \/___/___)";
wait(1);
std::cout << R"(
_//\::/\:\///_/ /_//:\::::\:\/______________/  \   /  \/  \/+/\  /\  /   /   /
/:\/::\ \:/__  __ /:\:\::::\/______________/    \ /\  /\  / /  \/  \/___/___/
/\::/\:\///_/ /_//:\:\:\                         \  \/\\\/+/\  /\  /   /   /+/
\/::\ \:/__  __ /:\:\:\:\_________________________\ ///\\\/  \/  \/___/___/ /_
::/\:\///_/ /_//:\:\:\:\/_________________________////::\\\  /\  /   /   /+/)";
wait(1);
std::cout << R"(
                        Shift Happens Presents
        _________ .__  __           _________                _____  __   
        \_   ___ \|__|/  |_ ___.__. \_   ___ \____________ _/ ____\/  |_ 
        /    \  \/|  \   __<   |  | /    \  \/\_  __ \__  \\   __\\   __\
        \     \___|  ||  |  \___  | \     \____|  | \// __ \|  |   |  |  
         \______  /__||__|  / ____|  \______  /|__|  (____  /__|   |__|  
                \/          \/              \/            \/             )";
wait(1);

std::cout << R"(
/__  __ /\::\:\:\/_________________________/_____::\:::::\/___/__/:/\:\
/_/ /_//::\::\:\/_____________________/\/_/_/_/_/\  \           /::\ \:\
_  __ /:\::\:8\/_____________________/\/\   /\_\\/\  \ 8       /:/\:\ \:\
/ /_//\     \|______________________//\\/\::\/__\\/\  \|______/::\ \:\ \:\
 __ /  \  \                        /:\/:\/\_______\/\        /:/\:\ \:\/::\
/_//    8      -8  --  --  --  -- //\::/\\/_/_/_/_/_/ --  --/::\ \:\ \::/\:\
_ /     |\  \   |________________/:\/::\///__/ /__//_______/:/\:\ \:\/::\ \:\
__________\     \               //\::/\:/___  ___ /       /::\ \:\ \::/\:\ \:\
::::::::::\\  \  \             /:\/::\///__/ /__//       /:/\:\ \:\/::\ \:\ \:)" << std::endl;
wait(2);





clear();
}

void Display::easterMenu()
{
    clear();
    cout<<"You've that you are living in a simulation"<<endl;
    wait(2);
    cout<<"After endless wandering you stumbled into a black hole and escaped the matrix"<<endl;
    wait(2);
    cout<<"You've unlocked the power of the gods!"<<endl;
    wait(3);
    clear();
    displayMenu("Easter Egg Menu", {"Infinite money glitch", "Bob the builder", "Death to All!", "Back"});
    int input = getInput(1, 4);

    if(input == 1){
        stats->setMoney(999999);
        GameMenu();
    }
    else if(input == 2){
        buildAll();
        GameMenu();
    }
    else if (input == 3){
        destroyAll();
        GameMenu();
    }
    
}

void Display::destroyAll()
{
    vector<vector<shared_ptr<MapComponent>>> tiles = map.getTiles();
    for (int i = 0; i < tiles.size(); i++)
    {
        for (int j = 0; j < tiles[i].size(); j++)
        {
            if (tiles[i][j] != nullptr)
            {
                map.destroy(tiles[i][j]->getId());
            }
        }
    }
}
void Display::buildAll()
{
    destroyAll();
    
    // Build all residential buildings
    for (int i = 0; i < 5; i++)
    {
        map.build("Apartment", "Residential", 0, i);
    }
    for (int i = 0; i < 3; i++)
    {
        map.build("TownHouse", "Residential", 1, i);
    }
    for (int i = 0; i < 3; i++)
    {
        map.build("House", "Residential", 2, i);
    }
    map.build("Estate", "Residential", 20, 0);

    // Build all commercial buildings
    for (int i = 0; i < 7; i++)
    {
        map.build("Store", "Commercial", 3, i);
    }
    for (int i = 0; i < 3; i++)
    {
        map.build("Office", "Commercial", 4, i);
    }
    for (int i = 0; i < 2; i++)
    {
        map.build("Mall", "Commercial", 5, i);
    }

    // Build all industrial buildings
    for (int i = 0; i < 4; i++)
    {
        map.build("Factory", "Industrial", 6, i);
    }
    for (int i = 0; i < 4; i++)
    {
        map.build("Warehouse", "Industrial", 7, i);
    }
    for (int i = 0; i < 2; i++)
    {
        map.build("Manufacturer", "Industrial", 8, i);
    }

    // Build all utility buildings
    for (int i = 0; i < 4; i++)
    {
        map.build("PowerPlant", "Utility", 9, i);
    }
    for (int i = 0; i < 4; i++)
    {
        map.build("WaterSupply", "Utility", 10, i);
    }
    for (int i = 0; i < 4; i++)
    {
        map.build("SewagePlant", "Utility", 11, i);
    }
    for (int i = 0; i < 4; i++)
    {
        map.build("Landfill", "Utility", 12, i);
    }

    // Build all landmark buildings
    for (int i = 0; i < 2; i++)
    {
        map.build("Park", "Landmark", 13, i);
    }
    for (int i = 0; i < 2; i++)
    {
        map.build("Monument", "Landmark", 14, i);
    }
    for (int i = 0; i < 2; i++)
    {
        map.build("CulturalCenter", "Landmark", 15, i);
    }

    // Build all infrastructure buildings

    for (int i = 0; i < 25; i++)
    {
        map.build("Road", "Infrastructure", 17, i);
        map.build("Road", "Infrastructure", 24, i);
        
    }
    map.build("Road", "Infrastructure", 19, 23);
        map.build("Road", "Infrastructure", 19, 22);
        map.build("Road", "Infrastructure", 19, 21);
    for (int i = 0; i < 15; i++)
    {
        map.build("Railway", "Infrastructure", 18, i);
    }

}

/*
Building Menu Description
The building menu lets you build structures on the map
You can choose from the following types:
Residential - Apartment, House, TownHouse, Estate
Commercial - Store, Office, Mall
Industrial - Factory, Warehouse, Manufacturer
Utility - Power Plant, Water Supply, Sewage Plant, Landfill
Landmark - Park, Monument, Cultural Center
Infrastructure - Road, Railway

If the user does not have enough money or if the max amount of building of the selected type is reached, 
The user will be notified and redirected to the Game menu

*/