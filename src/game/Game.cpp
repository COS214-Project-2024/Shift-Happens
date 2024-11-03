#include "Game.h"
#include <iostream>
#include <thread>
#include <algorithm>

Game::Game()
{
    variantop = 0;
    var= "";
}
//for testing bruh

string Game::getVar()
{
    return var;
}
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
    //map = new Map(-1); singleton with Map constructor as private
    cout <<"MAP GOES HERE FOR NOW\n";

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
    //map->render();
    display.wait(5);
    /*//MainMenu();
    int input;
    cin>>input;*/
    buldingmenu();
    
}

void Game::buldingmenu() {
    cout << "Let's get started with the simulation!\n";
    bool valid = false;
    int choice;

    while (!valid) {
        choice = display.GameMenu(); // Update choice before each iteration

        switch (choice) {
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
                createGovernment();
                valid = true;
                break;
            case 5:
                MainMenu();
                valid = true;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    }
}


void Game::createBuidling()
{
    int count =0;
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
            
            createVariant(getvariantop() );
            
            //createUtilityBuilding("Utility");
            //cout <<"NO\n";//
            
    
        //buildings->print(); //htis was making my error all long


            valid = true;
            break;
        case 2:
        
            choice2=display.Industrialmenu();
            
            setvariantop(choice2);
            setvar("Industrial");
            createVariant(getvariantop() );
            //createIndustrialBuilding("Industrial");
            
        //buildings->print();
            valid = true;
            break;
        case 3:
            choice2=display.Residentialmenu();
            
            setvariantop(choice2);
            setvar("Residential");
            createVariant(getvariantop() );
            //createResidentialBuilding("Residential");
            
        //buildings->print();
            
            valid = true;
            break;
        case 4:
        choice2=display.Commercialmenu();
        setvariantop(choice2);
         setvar("Commercial");
       createVariant(getvariantop() );
           // createCommercialBuilding("Commercial");
            
        //buildings->print();
        
       
        valid = true;
       
        break;
        case 5:
        choice2=display.Infrastructuremenu();
        setvariantop(choice2);
         setvar("Infrastructure");
       createVariant(getvariantop() );
           // createInfrastructureBuilding("Infrastructure");
            
       // buildings->print();
        valid = true;
        break;

        default:
        count++;
            std::cout << "Invalid choice. taking you to back." << std::endl;
             if(count>=2){cout <<"You are clearly doing it on purpose.\n";
             std:cin.clear();
             display.wait(1);
            MainMenu();}else{

            std::cin.clear();
            display.wait(1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //choice = display.MainMenu();
            //createBuidling();
           
           choice =  display.buildingtypemenu();
            break;}
        }


    }
   


        }
   
    //
    void Game::createUtilityBuilding(const std::string& variant) {
   /* cout <<"utility starting.\n";// for debugging
    if(!utilityfactory){
        utilityfactory = std::make_shared<UtilityBuildingFactory>(1);// instantiate if not there
    }
cout<<"utility step 2.\n"; // for debuggig
cout <<display.getvariant() <<endl; // for debugging


 std::shared_ptr<Building> building = utilityfactory->createBuilding2(display.getvariant()   );
 cout <<"I returned " << endl;
   if (building)
    {
        cout <<"Building is there\n";
      //buildings.push_back(building);
      cout <<"Created a "<< getVar() <<" building: " << display.getvariant() << endl; // <-- doing this creates memory leaks
      
    }else {
        cout <<"Invalid building variant:  " << display.getvariant();
    }
   

    
    /*buildings.push_back(variant);  // Store building
    std::cout << "Created " <<  getVar() << " building: " << display.getvariant() << std::endl;*/

}
void Game::createResidentialBuilding(const std::string& variant) {
 /*if(!Residentialfactory){
        Residentialfactory = std::make_shared<ResidentialBuildingFactory>(1);// instantiate if not there
    }

    std::shared_ptr<Building> building = Residentialfactory->createBuilding2(display.getvariant()  );
   if (building)
    {
      //buildings.push_back(building);
      cout <<"Created a "<< getVar() <<" building: " << display.getvariant() << endl; 
    }else {
        cout <<"Invalid building variant:  " << display.getvariant();
    }*/

}
void Game::createLandMarkBuilding(const std::string& variant) {
   /* if(!LandMarkfactory){
        LandMarkfactory= std::make_shared<LandmarkBuildingFactory>(1);// instantiate if not there
    }

    std::shared_ptr<Building> building = LandMarkfactory->createBuilding2(display.getvariant()  );
   if (building)
    {
     // buildings.push_back(building); already done on factory side
      cout <<"Created a "<< getVar() <<" building: " << display.getvariant() << endl; 
    }else {
        cout <<"Invalid building variant:  " << display.getvariant();
    }*/
}
void Game::createCommercialBuilding(const std::string& variant) {
   /* if(!Commerecialfactory){
        Commerecialfactory = std::make_shared<CommercialBuildingFactory>(1);// instantiate if not there
    }
    
    std::shared_ptr<Building> building = Commerecialfactory->createBuilding2(display.getvariant() );
   if (building)
    {
      //buildings.push_back(building); already done on factory side
      cout <<"Created a "<< getVar() <<" building: " << display.getvariant() << endl; 
    }else {
        cout <<"Invalid building variant:  " << display.getvariant();
    }*/
}
void Game::createIndustrialBuilding(const std::string& variant) {
 /*   if(!Industsrialfactory){
        Industsrialfactory = std::make_shared<IndustrialBuildingFactory>(1);// instantiate if not there
    }


    std::shared_ptr<Building> building = Industsrialfactory->createBuilding2(display.getvariant() );
   if (building)
    {
//      buildings.push_back(building);
      cout <<"Created a "<< getVar() <<" building: " << display.getvariant() << endl; 
    }else {
        cout <<"Invalid building variant:  " << display.getvariant();
    }*/
}
void Game::createInfrastructureBuilding(const std::string& variant) {
   /* if(!Infrastructurefactory){
       Infrastructurefactory = std::make_shared<InfrastructureFactory>(1);// instantiate if not there
    }
    
    std::shared_ptr<Building> building = Infrastructurefactory->createBuilding2(display.getvariant() );
   if (building)
    {
      //buildings.push_back(building);
      cout <<"Created a "<< getVar() <<" building: " << display.getvariant() << endl; 
    }else {
        cout <<"Invalid building variant:  " << display.getvariant();
    }*/
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
            
            demolishvariant(getvariantop() );

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

static void Taxation(std::shared_ptr<Government> government) {
    bool done = false;
    while(!done) {
        int choice = 0;
        std::cout << "========== Taxation Menu ==============" << std::endl;
        std::cout << "1. Increase Personal Tax" << std::endl;
        std::cout << "2. Decrease Personal Tax" << std::endl;
        std::cout << "3. Increase Business Tax" << std::endl;
        std::cout << "4. Decrease Business Tax" << std::endl;
        std::cout << "5. Collect Personal Tax" << std::endl;
        std::cout << "6. Collect Business Tax" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "=======================================" << std::endl;

        do {
            std::cout << "Enter your choice (1-7): ";
            std::cin >> choice;

            if (std::cin.fail() || choice < 1 || choice > 7) {
                std::cout << "Invalid input. Please enter a number between 1 and 7." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);

        double Increase = 0.0, Decrease = 0.0; 
        double IncomePersonal = 0.0, BIncome = 0.0; 

        switch (choice) {
            case 1:
                std::cout << "What do you want to increase the current tax rate by?" << std::endl;
                while (true) {
                    std::cin >> Increase;
                    if (std::cin.fail() || Increase <= 0) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Please enter a positive value to increase the tax rate." << std::endl;
                    } else {
                        break;
                    }
                }
                government->setPersonalTaxHigher(Increase);
                break;

            case 2:
                std::cout << "What do you want to decrease the current tax rate by?" << std::endl;
                while (true) {
                    std::cin >> Decrease;
                    if (std::cin.fail() || Decrease <= 0) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Please enter a positive value to decrease the tax rate." << std::endl;
                    } else {
                        break;
                    }
                }
                government->setPersonalTaxLower(Decrease);
                break;

            case 3:
                std::cout << "What do you want to increase the current tax rate by?" << std::endl;
                while (true) {
                    std::cin >> Increase;
                    if (std::cin.fail() || Increase <= 0) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Please enter a positive value to increase the tax rate." << std::endl;
                    } else {
                        break;
                    }
                }
                government->setBusinessTaxHigher(Increase);
                break;

            case 4:
                std::cout << "What do you want to decrease the current tax rate by?" << std::endl;
                while (true) {
                    std::cin >> Decrease;
                    if (std::cin.fail() || Decrease <= 0) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Please enter a positive value to decrease the tax rate." << std::endl;
                    } else {
                        break;
                    }
                }
                government->setBusinessTaxLower(Decrease);
                break;

            case 5:
                IncomePersonal = government->CollectPersonalTax();
                government->IncreaseAvialableBudget(IncomePersonal);
                break;

            case 6:
                BIncome = government->CollectBusinessTax();
                government->IncreaseAvialableBudget(BIncome);
                break;

            case 7:
                std::cout << "Exiting menu." << std::endl;
                done = true;
                break;

            default:
                break;
        }
    }
}


static void Policies(shared_ptr<Government> government){
    bool done = false;
    while(done == false ){
        int choice = 0;
        cout << "========== Policy Menu ==============" << endl;
        cout << "1. Implement new policy" << endl;
        cout << "2. View implemented policies" << endl;
        cout << "3. Exit" << endl;
        cout << "=====================================" << endl;

        do {
            cout << "Enter your choice (1-3): ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 3) {
                cout << "Invalid input. Please enter a number between 1 and 3." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } else {
                break;
            }
        } while (true);

        switch (choice) {
            case 1:
                government->addExecutePolicy();
                break;
            case 2:
                std::cout << "\nCurrently implemented policies:\n";
                for (const auto& policy : government->getCurrentPolicies()) {
                    std::cout << policy->getPolicyType() << '\n';
                }
                std::cout << '\n';
                break;
            case 3:
                cout << "Exiting menu." << endl;
                done = true;
                break;
            default:
                break;
        }
    }
}

static void PublicServices(shared_ptr<Government> government){
    bool done = false;
    while(done == false ){
        int choice = 0;
        cout << "========== Public Services Menu =============" << endl;
        cout << "1. Handle Police" << endl;
        cout << "2. Handle Education" << endl;
        cout << "3. Handle Healthcare" << endl;
        cout << "4. Exit" << endl;
        cout << "=============================================" << endl;

        do {
            cout << "Enter your choice (1-4): ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 4) {
                cout << "Invalid input. Please enter a number between 1 and 4." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } else {
                break;
            }
        } while (true);
        
        string answer;
        switch (choice) {
            case 1:
                std::cout << "Would you like to add or remove funds to the Police? (Add/Remove)" << std::endl;
                while (true) {
                    std::cin >> answer;
                    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

                    if (answer == "add") {
                        government->getPolice()->increaseBudget();
                        break;
                    } else if (answer == "remove") {
                        government->getPolice()->decreaseBudget();
                        break;
                    } else {
                        std::cout << "Invalid input. Please enter 'Add' or 'Remove'." << std::endl;
                    }
                }
                break;
            case 2:
                std::cout << "Would you like to add or remove funds to the Education? (Add/Remove)" << std::endl;
                while (true) {
                    std::cin >> answer;
                    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

                    if (answer == "add") {
                        government->getEducation()->increaseBudget();
                        break;
                    } else if (answer == "remove") {
                        government->getEducation()->decreaseBudget();
                        break;
                    } else {
                        std::cout << "Invalid input. Please enter 'Add' or 'Remove'." << std::endl;
                    }
                }
                break;
            case 3:
                std::cout << "Would you like to add or remove funds to the Healthcare? (Add/Remove)" << std::endl;
                while (true) {
                    std::cin >> answer;
                    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

                    if (answer == "add") {
                        government->getHealthCare()->increaseBudget();
                        break;
                    } else if (answer == "remove") {
                        government->getHealthCare()->decreaseBudget();
                        break;
                    } else {
                        std::cout << "Invalid input. Please enter 'Add' or 'Remove'." << std::endl;
                    }
                }
                break;
            case 4:
                cout << "Exiting menu." << endl;
                done = true;
                break;
            default:
                break;
        }
    }
}

static void CityBudget(shared_ptr<Government> government){
    // this is just going to show where the government is currently spending money
}

void Game::createGovernment()
{
    std::shared_ptr<Government> government = make_shared<Government>();
    std::cout << "You have chosen to create a Government.\n";
    std::cout << "What do you wish to implement? ";
    int choice = display.Governmentmenu();
    int choice2;
    bool valid = false;
    while (!valid){
        switch (choice) {
            case 1:
                cout << "Taxation selected." << endl;
                Taxation(government);
                valid = true;
                break;
            case 2:
                cout << "Policies selected." << endl;
                Policies(government);
                valid = true;
                break;
            case 3:
                cout << "Public Services selected." << endl;
                PublicServices(government);
                valid = true;
                break;
            case 4:
                cout << "City Budget selected." << endl;
                CityBudget(government);
                valid = true;
                break;
            case 5:
                // open up stats
                break;
            case 6:
                cout << "Exiting menu." << endl;
                valid = true;
                break;
            default:
                std::cout << "COME BACK WHEN YOU ARE SERIOUS." << std::endl;
                std::cin.clear();
                display.wait(1);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                //choice = display.MainMenu();
                //createBuidling();
            choice =  display.MainMenu();
                break;
        }
    }
        // switch (choice)
        // {
        // case 1:
        //   //  choice2 =display.Utilitymenu(); // tax
        //   choice2 =display.taxMenu();
        //     setvariantop(choice2);
        //    //TO -DO LOGIC FOR TAX
        //    //createTax()
            
    
        // //buildings->print(); //htis was making my error all long


        //     valid = true;
        //     break;
        // case 2:
        
        //     choice2=display.Policymenu();
        //    //TO DO COMMAND LOGIC FOR POLICY
        // //createPolicy("");
        //     //policy
            
        // //buildings->print();
        //     valid = true;
        //     break;
        // case 3:
        //   MainMenu();
        // //buildings->print();
            
        //     valid = true;
        //     break;

        // default:
        //     std::cout << "COME BACK WHEN YOU ARE SERIOUS." << std::endl;
        //     std::cin.clear();
        //     display.wait(1);
        //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //     //choice = display.MainMenu();
        //     //createBuidling();
        //    choice =  display.MainMenu();
        //     break;
        // }


    //}
   //display.Governmentmenu();

}

//placeholder values for now
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