#include "Game.h"
#include <iostream>
#include <thread>

Game::Game()
{
    variantop = 0;
    var= "";
}
string Game::getVar(){return var;}
void Game::setvar(const string& var)
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
void Game::setvariantop(const int& op)
{
    this->variantop = op;
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
            //choice = display.MainMenu();
            choice = display.GameMenu();
            break;
        }

    }

}
void Game::createBuidling()
{
    std::cout << "You have chosen to create a building.\n";
            std::cout << "What type variant do you wish to create? ";
            int choice = display.buildingtypemenu();
            int choice2;
            bool valid = false;
            while (!valid){
        switch (choice)
        {
        case 1:
            choice2 =display.Utilitymenu();
            setvariantop(choice2);
            setvar("Utility");
            
            //createVariant(getvariantop() );
            createUtilityBuilding("Utility");
            cout <<"displaying buildings.\n";
        printAllBuildings();

            valid = true;
            break;
        case 2:
        
            choice2=display.Industrialmenu();
            
            setvariantop(choice2);
            setvar("Industrial");
            //createVariant(getvariantop() );
            createUtilityBuilding("Industrial");
            cout <<"displaying buildings.\n";
        printAllBuildings();
            valid = true;
            break;
        case 3:
            choice2=display.Residentialmenu();
            
            setvariantop(choice2);
            setvar("Residential");
            //createVariant(getvariantop() );
            createUtilityBuilding("Residential");
            cout <<"displaying buildings.\n";
        printAllBuildings();
            
            valid = true;
            break;
        case 4:
        choice2=display.Commercialmenu();
        setvariantop(choice2);
         setvar("Commercial");
       //createVariant(getvariantop() );
            createUtilityBuilding("Commercial");
            cout <<"displaying buildings.\n";
        printAllBuildings();
        
       
        valid = true;
       
        break;
        case 5:
        choice2=display.Infrastructuremenu();
        setvariantop(choice2);
         setvar("Infrastructure");
       //createVariant(getvariantop() );
            createInfrastructureBuilding("Infrastructure");
            cout <<"displaying buildings.\n";
        printAllBuildings();
        valid = true;
        break;

        default:
            std::cout << "Invalid choice. taking you to back." << std::endl;
            std::cin.clear();
            display.wait(1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //choice = display.MainMenu();
            //createBuidling();
           choice =  display.buildingtypemenu();
            break;
        }


    }
   


        }
    void Game::createVariant(const int& op)
    {

        bool valid2 = false;
    while(!valid2)
    {
        switch(op){
            case 1:
            cout << "Now building " << getVar() <<" building: " << display.getvariant() <<endl;
            valid2 = true;
            break;
            case 2:
            cout <<"Now building" << getVar() << " buidling: " << display.getvariant() << endl;
            valid2 = true;
            break;
            case 3:
            cout <<"Now building " << getVar() <<"building: " << display.getvariant() << endl;
            valid2 = true;
            break;
            case 4 :
            cout <<"Now building"<<getVar() << " building: " << display.getvariant() << endl;
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
    //
    void Game::createUtilityBuilding(const std::string& variant) {
    buildings.push_back(variant);  // Store building
    std::cout << "Created " <<  getVar() << " building: " << display.getvariant() << std::endl;
}
void Game::createResidentialBuilding(const std::string& variant) {
    buildings.push_back(variant);  // Store building
    std::cout << "Created " <<  getVar() << " building: " << display.getvariant() << std::endl;
}
void Game::createLandMarkBuilding(const std::string& variant) {
    buildings.push_back(variant);  // Store building
    std::cout << "Created " <<  getVar() << " building: " << display.getvariant() << std::endl;
}
void Game::createCommercialBuilding(const std::string& variant) {
    buildings.push_back(variant);  // Store building
    std::cout << "Created " <<  getVar() << " building: " << display.getvariant() << std::endl;
}
void Game::createIndustrialBuilding(const std::string& variant) {
    buildings.push_back(variant);  // Store building
    std::cout << "Created " <<  getVar() << " building: " << display.getvariant() << std::endl;
}
void Game::createInfrastructureBuilding(const std::string& variant) {
    buildings.push_back(variant);  // Store building
    std::cout << "Created " <<  getVar() << " building: " << display.getvariant() << std::endl;
}


void Game::printAllBuildings() const {
    std::cout << "All buildings created so far:" << std::endl;
    for (const auto& building : buildings) {
        //std::cout << "- " << building->getType() <<"- " << building->getVariant()  << std::endl;
        std::cout << "- " << building  << std::endl;
    }
}

    //
    void Game::demolishvariant(const int& op)
    {
         bool valid2 = false;
    while(!valid2)
    {
        switch(op){
            case 1:
            cout << "Now demolishing " << getVar() <<" building: " << display.getvariant() <<endl;
            valid2 = true;
            break;
            case 2:
            cout <<"Now demolishing" << getVar() << " buidling: " << display.getvariant() << endl;
            valid2 = true;
            break;
            case 3:
            cout <<"Now demolishing " << getVar() <<"building: " << display.getvariant() << endl;
            valid2 = true;
            break;
            case 4 :
            cout <<"Now demolishing"<<getVar() << " building: " << display.getvariant() << endl;
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
    void Game::upgradevariant(const int& op)
    {
         bool valid2 = false;
    while(!valid2)
    {
        switch(op){
            case 1:
            cout << "Now upgrading " << getVar() <<" building: " << display.getvariant() <<endl;
            valid2 = true;
            break;
            case 2:
            cout <<"Now uograding" << getVar() << " buidling: " << display.getvariant() << endl;
            valid2 = true;
            break;
            case 3:
            cout <<"Now uograding" << getVar() <<"building: " << display.getvariant() << endl;
            valid2 = true;
            break;
            case 4 :
            cout <<"Now upgrading"<<getVar() << " building: " << display.getvariant() << endl;
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
    std::cout <<"You have chosen to demolish a building.\n";
            std::cout <<"What type variant do you wish to demolish? ";
           int choice = display.buildingtypemenu();
            int choice2;
            bool valid = false;
            while (!valid){
        switch (choice)
        {
        case 1:
            choice2 =display.Utilitymenu();
            setvariantop(choice2);
            setvar("Utility");
            
            createVariant(getvariantop() );

            valid = true;
            break;
        case 2:
        
            choice2=display.Industrialmenu();
            
            setvariantop(choice2);
            setvar("Industrial");
            demolishvariant(getvariantop());
            valid = true;
            break;
        case 3:
            choice2=display.Residentialmenu();
            
            setvariantop(choice2);
            setvar("Residential");
            demolishvariant(getvariantop() );
            
            valid = true;
            break;
        case 4:
        choice2=display.Commercialmenu();
        setvariantop(choice2);
         setvar("Commercial");
        demolishvariant(getvariantop() );
       
        valid = true;
       
        break;
        

        default:
            std::cout << "Invalid choice. taking you to back." << std::endl;
            std::cin.clear();
            display.wait(1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //choice = display.MainMenu();
            //createBuidling();
           choice =  display.buildingtypemenu();
            break;
        }
            }
           
}
void Game::upgradeBuilding()
{
    std::cout <<"You have chosen to upgrade a building.\n";
            std::cout <<"What type variant do you wish to upgrade? ";
            int choice = display.buildingtypemenu();
            int choice2;
            bool valid = false;
            while (!valid){
        switch (choice)
        {
        case 1:
            choice2 =display.Utilitymenu();
            setvariantop(choice2);
            setvar("Utility");
            
            upgradevariant(getvariantop() );

            valid = true;
            break;
        case 2:
        
            choice2=display.Industrialmenu();
            
            setvariantop(choice2);
            setvar("Industrial");
            upgradevariant(getvariantop());
            valid = true;
            break;
        case 3:
            choice2=display.Residentialmenu();
            
            setvariantop(choice2);
            setvar("Residential");
            upgradevariant(getvariantop() );
            
            valid = true;
            break;
        case 4:
        choice2=display.Commercialmenu();
        setvariantop(choice2);
         setvar("Commercial");
        upgradevariant(getvariantop() );
       
        valid = true;
       
        break;
        

        default:
            std::cout << "Invalid choice. taking you to back." << std::endl;
            std::cin.clear();
            display.wait(1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //choice = display.MainMenu();
            //createBuidling();
            display.buildingtypemenu();
            break;
        }
            
}
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