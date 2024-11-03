#include "Display.h"
#include <iostream>
#include <thread>
#include <algorithm>

//#include <curses.h>


///constructor for display purposes
Display::Display() {
    

}
/// 
Display::~Display() {
    
}
string Display::getvariant()
{
    return variant;
}
void Display::settype(const string& variant)
{
    this->variant = variant;
}

void Display::intro() {
    std::cout << "Welcome to CityCraft!" << std::endl;
    std::cout << "Press Enter to start the game." << std::endl;
    std::cin.get();
    clear();
    wait(1);
    logo();
    std::cout << "Press any key to continue..." << std::endl; 
    std::cin.get();
}

void Display::clear() {
    system("clear");
}

void Display::logo() {
std::cout << R"(
        
_________ .__  __           _________                _____  __   
\_   ___ \|__|/  |_ ___.__. \_   ___ \____________ _/ ____\/  |_ 
/    \  \/|  \   __<   |  | /    \  \/\_  __ \__  \\   __\\   __\
\     \___|  ||  |  \___  | \     \____|  | \// __ \|  |   |  |  
 \______  /__||__|  / ____|  \______  /|__|  (____  /__|   |__|  
        \/          \/              \/            \/             

)" << std::endl;
}

void Display::wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int Display::MainMenu() {
    std::vector<std::string> options = {"New Game", "Load Game", "Exit"};
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an option." << std::endl;
        int input;
        if(input > 3){
           displayMenu(options);
        }
        std::cin >> input;
        return input;
    }
    return -1;
}
int Display::buildingtypemenu()
{
    
    std::vector<std::string> options = {"Utility", "Industrial","Residential","Commercial","Infrastructure"};
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an option." << std::endl;
        int input;
        std::cin >> input;
        if(input > 5){
            cout <<"incorrect option chosen bruh." << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;


}

void Display::displayMenu(std::vector<std::string> options) {
    for (std::vector<std::string>::size_type i = 0; i < options.size(); i++) {
        std::cout << i + 1 << ". " << options[i] << std::endl;
    }
}

void Display::loadscreen() {
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
    
}
int Display::Utilitymenu()
{
    cout <<"Please select the utility you wish to build.\n";
    variant = "Utility";
     std::vector<std::string> options = {"PowerPlant", "LandFill", "SewagePlant","WaterSupply"};
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        if(input == 1){
            settype("PowerPlant");
        }else if(input == 2){
            settype("LandFill");

        }else if(input == 3){
            settype("SewagePlant");
        }else if(input == 4){
            settype("WaterSupply");
        }else {
            cout <<"Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;

}
int Display::Infrastructuremenu()
{
    cout <<"Please select the utility you wish to build.\n";
    variant = "Infrastructure";
     std::vector<std::string> options = {"Road", "Railway"};
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        if(input == 1){
            settype("Road");
        }else if(input == 2){
            settype("Railway");

        }else {
            cout <<"Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;

}
int Display::Residentialmenu()
{
      cout <<"Please select the residential property you wish to build.\n";
      variant = "Residential";
     std::vector<std::string> options = {"Apartment", "Estate", "House","TownHouse"};
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        if(input == 1){
            settype("Apartment");
        }else if(input == 2){
            settype("Estate");

        }else if(input == 3){
            settype("House");
        }else if(input == 4){
            settype("TownHouse");
        }else {
            cout <<"Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;

}
int Display::Commercialmenu()
{
      cout <<"Please select the Commercial property you wish to build.\n";
      variant = "Commercial";
     std::vector<std::string> options = {"Store", "Mall", "Office"};
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        
        if(input == 1){
            settype("Store");
        }else if(input == 2){
            settype("Mall");

        }else if(input == 3){
            settype("Office");
        }else {
            cout <<"Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;
}
int Display::Industrialmenu()
{
      cout <<"Please select the industrial property you wish to build.\n";
      variant = "Industrial";
     std::vector<std::string> options = {"Warehouse", "Factory", "Manufacturer"};
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        if(input == 1){
            settype("Warehouse");
        }else if(input == 2){
            settype("Factory");

        }else if(input == 3){
            settype("Manufacturer");
        }else {
            cout <<"Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;
}
int Display::LandMarkmenu()
{
      cout <<"Please select the landmark you wish to build.\n";
     std::vector<std::string> options = {"Monument", "Park","Cultural Center"};
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        if(input == 1){
            settype("Monument");
        }else if(input == 2){
            settype("Park");

        }else if(input == 3){
            settype("Cultural Centre");
        }else {
            cout <<"Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;
}
int Display::GameMenu(){
     std::vector<std::string> options = {"Create a building", "Upgrade a building", "Demolish a building","Government Menu","Return to main menu"};
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        return input;
    }
    return -1;
     
        
     }

int Display::Governmentmenu()
{   
    std::vector<std::string> options = {"Taxation", "Policies", "Public Servicess","City Budget","View Statistics", "Exit"};
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        return input;
    }
    return -1;

    // std::shared_ptr<Government> government = make_shared<Government>();
    // bool Done = false;
    // while (Done == false)
    // {
    //     int choice = 0;
    //     cout << "========== Government Menu ==============" << endl;
    //     cout << "1. Taxation" << endl;
    //     cout << "2. Policies" << endl;
    //     cout << "3. Public Services" << endl;
    //     cout << "4. City Budget" << endl;
    //     cout << "5. View Statistics" << endl;
    //     cout << "6. Exit" << endl;
    //     cout << "=========================================" << endl;

    //     do {
    //         cout << "Enter your choice (1-5): ";
    //         cin >> choice;

    //         if (cin.fail() || choice < 1 || choice > 5) {
    //             cout << "Invalid input. Please enter a number between 1 and 5." << endl;
    //             cin.clear(); 
    //             cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    //         } else {
    //             break;
    //         }
    //     } while (true);

    //     switch (choice) {
    //         case 1:
    //             cout << "Taxation selected." << endl;
    //             Taxation(government);
    //             break;
    //         case 2:
    //             cout << "Policies selected." << endl;
    //             Policies(government);
    //             break;
    //         case 3:
    //             cout << "Public Services selected." << endl;
    //             PublicServices(government);
    //             break;
    //         case 4:
    //             cout << "City Budget selected." << endl;
    //             CityBudget(government);
    //             break;
    //         case 5:
    //             // open up stats
    //             break;
    //         case 6:
    //             cout << "Exiting menu." << endl;
    //             Done = true;
    //             break;
    //         default:
    //             break;
    //     }
    // }
}     
int Display::taxMenu()
{
     cout <<"what would you like to do with tax?.\n";
     std::vector<std::string> options = {"Increase Tax", "Decrease Tax","Collect Tax", "Exit"}; //high tax/standard tax/low tax
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        int choice;
        do {
            cout << "Enter your choice (1-4): ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 7) {
                cout << "Invalid input. Please enter a number between 1 and 7." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } else {
                break;
            }
        } while (true);

        

        return choice;
    }
    return -1;
}
int Display::Policymenu()
{
     cout <<"what Policy do you feel like implementing?.\n";
     std::vector<std::string> options = {"SinTaxPolicy", "Imigration Policy","HealthCarePolicy"}; //high tax/standard tax/low tax
    bool running = true;
    while (running) {
        clear();
        logo();
        displayMenu(options);
        std::cout << "Please select an action." << std::endl;
        int input;
        std::cin >> input;
        if(input == 1){
         cout << "You have chosen to implement SinTax Policy\n" ; 
        }else if(input == 2){
            cout <<"You have chosen to implement Immigration policy\n";

        }else if(input == 3){
            cout << "You have chosen to implement Healthcare\n";
        }else {
            cout <<"Invalid entry" << endl;
            displayMenu(options);
        }
        return input;
    }
    return -1;


}
