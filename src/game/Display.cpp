#include "Display.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include "../../libs/tabulate/include/tabulate/table.hpp"
#include <stdlib.h>
#include <fstream>  //for save and load
#include <sstream> //for save and load

/// constructor for display purposes
Display::Display() : map(Map::getInstance()){
    stats = make_shared<Statistics>();
}

Display::~Display(){
}

void Display::clear(){
    system("clear");
}

void Display::logo(){
    std::cout << R"(
            _________ .__  __           _________                _____  __   
            \_   ___ \|__|/  |_ ___.__. \_   ___ \____________ _/ ____\/  |_ 
            /    \  \/|  \   __<   |  | /    \  \/\_  __ \__  \\   __\\   __\
            \     \___|  ||  |  \___  | \     \____|  | \// __ \|  |   |  |  
             \______  /__||__|  / ____|  \______  /|__|  (____  /__|   |__|  
                    \/          \/              \/            \/             
)" << std::endl;
}

void Display::wait(int seconds){
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int Display::MainMenu(){
    clear();
    logo();

    tabulate::Table options;
    options.add_row({"1. New Game", "2. Load Game", "3. Save", "4. Exit"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    options.format().hide_border_bottom();
    options.format().hide_border_top();

    options[0][0].format().hide_border_left();
    options[0][3].format().hide_border_right();

    tabulate::Table menu;
    menu.add_row({"Main Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while (!valid)
    {
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
        else if (input > 4 || input < 1)
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

    return input;
}

void Display::loadscreen(){
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
    options.add_row({"6. Citizens","7. Transport", "8. Detailed Stats","9. Save", "10. Exit"});
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
        else if (input > 10 || input < 1)
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
                //viewMenu();
            }
            else if (input == 4)
            {
                //destroyMenu();
            }
            else if (input == 5)
            {
                governmentMenu();
            }
            else if (input == 6)
            {
                //citizensMenu();
            }
            else if (input == 7)
            {
                //transportMenu();
            }
            else if (input == 8)
            {
                //detailedStatsMenu();
            }
            else if (input == 9)
            {
                SaveMenu();
            }
            else if (input == 10)
            {
                //exitMenu();
            }
            else
            {
                std::cout << "Invalid option. Please try again." << std::endl;
            }
            
            return input;
        }
    }
}

//Save and Load menus
int Display::SaveMenu(){
    clear();
    logo();

    tabulate::Table options;
    options.add_row({"1. Continue", "2. Cancel"});
    options.format().width(40);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});


    tabulate::Table menu;
    menu.add_row({"Save Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
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
        else if (input > 2 || input < 1)
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
            if (input == 1)
            {   //continue and save option
                saveToFile();
            }
            else if (input == 2)
            {   //cancel option
                cin.clear();
                cout << "Going back..." << endl;
                wait(1);
                MainMenu();
            }
            else
            {
                std::cout << "Invalid option. Please try again." << std::endl;
            }
            
            return input;
        }
    }
}

//Save to file handler
void Display::saveToFile() {
    clear();
    logo();

    string filename = "game_stats.csv"; // will store the data here
    displayStats();
    
    // Update stats before saving
    stats->updateStats();

    std::vector<std::string> headers = {"Money", "Income", "Population", "Satisfaction", "Water", "Electricity", "Waste", "Sewage"};
    std::vector<std::vector<std::string>> data = {
        {
            std::to_string(stats->getMoney()),
            std::to_string(stats->getIncome()),
            std::to_string(stats->getPopulation()),
            std::to_string(stats->getSatisfaction()),
            std::to_string(stats->getWaterConsumption()),
            std::to_string(stats->getPowerConsumption()),
            std::to_string(stats->getWasteProduction()),
            std::to_string(stats->getSewageProduction())
        }
    };

    saveToFile(filename, headers, data);

    std::cout << "Successfully saved..." << std::endl;
    wait(1);
}

//Save stats to File
void Display::saveToFile(const std::string& filename, const std::vector<std::string>& headers, const std::vector<std::vector<std::string>>& data) {
    //display the logo and stats
    clear();
    logo();

    displayStats();

    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for saving: " << filename << std::endl;
        return;
    }

    // Write headers
    for (size_t i = 0; i < headers.size(); ++i) {
        outFile << headers[i];
        if (i < headers.size() - 1) outFile << ","; // Add comma except after the last header
    }
    outFile << std::endl;

    // Write data
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            outFile << row[i];
            if (i < row.size() - 1) outFile << ","; // Add comma except after the last column
        }
        outFile << std::endl;
    }

    outFile.close();
    
    cout << "Saving current game state.";
    wait(1);
    cout << ".";
    wait(1);
    cout << "." <<endl;
    wait(1);

    std::cout << "Statistics saved successfully to " << filename << std::endl;
    wait(1);
}

//Load
int Display::LoadMenu(){
    clear();
    logo();
    displayStats();
    
    tabulate::Table options;
    options.add_row({"1. Continue", "2. Cancel"});
    options.format().width(40);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});


    tabulate::Table menu;
    menu.add_row({"Load Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
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
        else if (input > 2 || input < 1)
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
            if (input == 1)
            {   //continue and load option
                loadFromFile();
            }
            else if (input == 2)
            {   //cancel option
                cin.clear();
                cout << "Going back..." << endl;
                wait(1);
                MainMenu();
            }
            else
            {
                std::cout << "Invalid option. Please try again." << std::endl;
            }
            
            return input;
        }
    }
}

void Display::loadFromFile() {
    clear();
    logo();

    string filename = "game_stats.csv"; //will store the data here

    // Check if file exists
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: File not found: " << filename << std::endl;
        wait(2);
        return; // Return early if the file doesn't exist
    }

    // Load stats
    std::vector<std::string> headers;
    std::vector<std::vector<std::string>> data;
    loadStatsFromFile(filename, headers, data);

    // Check if data is valid
    if (data.empty() || data[0].size() < 8) {
        std::cerr << "Error: Invalid data format in file: " << filename << std::endl;
        return; // Return early if the data format is incorrect
    }

    // Populate the stats
    try {
        stats->setMoney(std::stoi(data[0][0]));
        stats->setIncome(std::stoi(data[0][1]));
        stats->setPopulation(std::stoi(data[0][2]));
        stats->setSatisfaction(std::stoi(data[0][3]));
        stats->setWaterConsumption(std::stoi(data[0][4]));
        stats->setPowerConsumption(std::stoi(data[0][5]));
        stats->setWasteProduction(std::stoi(data[0][6]));
        stats->setSewageProduction(std::stoi(data[0][7]));
    } catch (const std::exception& e) {
        std::cerr << "Error: Failed to convert data: " << e.what() << std::endl;
        return; // Return early on conversion error
    }

    stats->updateStats();

    std::cout << "Successfully loaded stats..." << std::endl;
    wait(1);

    displayStats();
}

//Load stats from file
void Display::loadStatsFromFile(const std::string& filename, std::vector<std::string>& headers, std::vector<std::vector<std::string>>& data) {
    
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for loading: " << filename << std::endl;
        return;
    }

    std::string line;

    // Read headers
    if (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string header;
        while (std::getline(ss, header, ',')) {
            headers.push_back(header);
        }
    }

    // Read data
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string value;
        std::vector<std::string> row;
        while (std::getline(ss, value, ',')) {
            row.push_back(value);
        }
        data.push_back(row);
    }
    
    inFile.close();
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

    stats.format().width(15);
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

    gridmap.format().width(10);
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
    tabulate::Table options;
    options.add_row({"1. Residential", "2. Commercial", "3. Industrial", "4. Utility", "5. Landmark", "6. Infrastructure"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    options.format().hide_border_bottom();
    options.format().hide_border_top();

    options[0][0].format().hide_border_left();
    options[0][5].format().hide_border_right();

    tabulate::Table menu;
    menu.add_row({"Build Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while (!valid)
    {
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
        else if (input > 6 || input < 1)
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

            valid = true;
        }
    }
}

void Display::residentialMenu()
{
    clear();
    logo();
    tabulate::Table options;
    options.add_row({"1. Apartment", "2. Town House", "3. House", "4. Estate"});
    options.add_row({"$100", "$200", "$400", "$800"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    options.format().hide_border_bottom();
    options.format().hide_border_top();

    options[0][0].format().hide_border_left();
    options[0][2].format().hide_border_right();

    tabulate::Table menu;
    menu.add_row({"Residential Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while (!valid)
    {
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
        else if (input > 5 || input < 1)
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
    }
}

void Display::commercialMenu()
{
    clear();
    logo();
    tabulate::Table options;
    options.add_row({"1. Store", "2. Office", "3. Mall"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    options.format().hide_border_bottom();
    options.format().hide_border_top();

    options[0][0].format().hide_border_left();
    options[0][2].format().hide_border_right();

    tabulate::Table menu;
    menu.add_row({"Commercial Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while (!valid)
    {
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
        else if (input > 3 || input < 1)
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
            valid = true;
        }
    }
}

void Display::industrialMenu()
{
    clear();
    logo();
    tabulate::Table options;
    options.add_row({"1. Factory", "2. Warehouse", "3. Manufacturer"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    options.format().hide_border_bottom();
    options.format().hide_border_top();

    options[0][0].format().hide_border_left();
    options[0][2].format().hide_border_right();

    tabulate::Table menu;
    menu.add_row({"Industrial Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while (!valid)
    {
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
        else if (input > 3 || input < 1)
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
            valid = true;
        }
    }
}

void Display::utilityMenu()
{
    clear();
    logo();
    tabulate::Table options;
    options.add_row({"1. Power Plant", "2. Water Supply", "3. Sewage Plant", "4. Landfill"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    options.format().hide_border_bottom();
    options.format().hide_border_top();

    options[0][0].format().hide_border_left();
    options[0][3].format().hide_border_right();

    tabulate::Table menu;
    menu.add_row({"Utility Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while (!valid)
    {
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
        else if (input > 4 || input < 1)
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

            valid = true;
        }
    }
}

void Display::landmarkMenu()
{
    clear();
    logo();
    tabulate::Table options;
    options.add_row({"1. Park", "2. Monument", "3. Cultural Center"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    options.format().hide_border_bottom();
    options.format().hide_border_top();

    options[0][0].format().hide_border_left();
    options[0][2].format().hide_border_right();

    tabulate::Table menu;
    menu.add_row({"Landmark Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while (!valid)
    {
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
        else if (input > 3 || input < 1)
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
            valid = true;
        }
    }
}

void Display::infrastructureMenu()
{
    clear();
    logo();
    tabulate::Table options;
    options.add_row({"1. Road", "2. Railway"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    options.format().hide_border_bottom();
    options.format().hide_border_top();

    options[0][0].format().hide_border_left();
    options[0][1].format().hide_border_right();

    tabulate::Table menu;
    menu.add_row({"Infrastructure Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while (!valid)
    {
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
        else if (input > 2 || input < 1)
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
            valid = true;
        }
    }
}

string Display::check(string var, int num){
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


void Display::upgradeMenu(){
    clear();
    logo();

    vector<string> apartmentUpgrades = getUpgrades("Apartment", 1);

}

vector<string> Display::getUpgrades(string var, int num){
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

void Display::governmentMenu(){
    clear();
    logo();
    tabulate::Table options;
    options.add_row({"1. Tax", "2. Policies", "3. Services", "4. Budget", "5. Statistics", "6. Back"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    options.format().hide_border_bottom();
    options.format().hide_border_top();

    options[0][0].format().hide_border_left();
    options[0][4].format().hide_border_right();

    tabulate::Table menu;
    menu.add_row({"Government Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while(!valid){
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
        else if (input > 6 || input < 1)
        {
            if (errorCount == 7)
            {
                errorCount = 0;
            }
            std::cout << errorMsg[errorCount] << std::endl;
            errorCount++;
        }
        else{
            valid = true;
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
    }
}

void Display::taxMenu(){
    clear();
    logo();
    tabulate::Table options;
    options.add_row({"1. Business", "2. Personal", "3. Back"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    tabulate::Table menu;
    menu.add_row({"Tax Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while(!valid){
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
        else if (input > 3 || input < 1)
        {
            if (errorCount == 7)
            {
                errorCount = 0;
            }
            std::cout << errorMsg[errorCount] << std::endl;
            errorCount++;
        }
        else{
            valid = true;
            if (input == 1)
            {
                businessTaxMenu();
            }
            else if (input == 2)
            {
                personalTaxMenu();
            }
            else if (input == 3)
            {
                governmentMenu();
            }
        }
    }
}

void Display::businessTaxMenu(){
    clear();
    logo();
    tabulate::Table options;
    options.add_row({"1. Increase", "2. Decrease", "3. Collect", "4. Back"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    options.format().hide_border_bottom();
    options.format().hide_border_top();

    options[0][0].format().hide_border_left();
    options[0][3].format().hide_border_right();

    tabulate::Table menu;
    menu.add_row({"Business Tax Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while(!valid){
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
        else if (input > 4 || input < 1)
        {
            if (errorCount == 7)
            {
                errorCount = 0;
            }
            std::cout << errorMsg[errorCount] << std::endl;
            errorCount++;
        }
        else{
            if (input == 1)
            {
                stats->increaseBusinessTax();
                businessTaxMenu();
            }
            else if (input == 2)
            {
                stats->decreaseBusinessTax();
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
            valid = true;
        }
    }

}

void Display::personalTaxMenu(){
    clear();
    logo();
    tabulate::Table options;
    options.add_row({"1. Increase", "2. Decrease", "3. Collect", "4. Back"});
    options.format().width(20);
    options.format().font_align(tabulate::FontAlign::center);
    options.format().font_style({tabulate::FontStyle::bold});
    options.format().hide_border_bottom();
    options.format().hide_border_top();

    options[0][0].format().hide_border_left();
    options[0][3].format().hide_border_right();

    tabulate::Table menu;
    menu.add_row({"Personal Tax Menu"});
    menu.add_row({options});

    menu.format().font_align(tabulate::FontAlign::center);
    menu[0][0].format().font_color(tabulate::Color::blue);
    std::cout << menu << std::endl;
    std::cout << "Please select an option." << std::endl;
    int input;

    bool valid = false;
    vector<string> errorMsg = {"Invalid option. Please try again.", "Enter an integer.", "What are you doing?", "Can you even read?", "You are clearly doing it on purpose.", "You are testing my patience.", "I am not a happy computer.", "Stop that!!"};
    int errorCount = 0;
    while(!valid){
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
        else if (input > 4 || input < 1)
        {
            if (errorCount == 7)
            {
                errorCount = 0;
            }
            std::cout << errorMsg[errorCount] << std::endl;
            errorCount++;
        }
        else{
            if (input == 1)
            {
                stats->increasePersonalTax();
                personalTaxMenu();
            }
            else if (input == 2)
            {
                stats->decreasePersonalTax();
                personalTaxMenu();
            }
            else if (input == 3)
            {
                stats->collectPersonalTax();
                personalTaxMenu();
            }
            else if (input == 4)
            {
                taxMenu();
            }
            valid = true;
        }
    }
}

void Display::policiesMenu(){
    
}

void Display::servicesMenu(){

}

void Display::budgetMenu(){

}

void Display::statisticsMenu(){

}


