#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <algorithm>

// Policies and Government headers
#include "../Government/PublicServiceState.h"
#include "../Government/Standard.h"
#include "../Government/Outdated.h"
#include "../Government/Modern.h"
#include "../Government/PublicServices.h"
#include "../Government/CitySubject.h"
#include "../citizens/CitizenObserver.h"
#include "../Government/Education.h"
#include "../Government/HealthCare.h"
#include "../Government/Police.h"
#include "../Government/BoostEducationPolicy.h"
#include "../Government/BoostHealthCarePolicy.h"
#include "../Government/BoostPolicePolicy.h"
#include "../Government/Policy.h"
#include "../Government/Government.h"

//citizens
#include "../citizens/Boy.h"
#include "../citizens/BoyBuilder.h"
#include "../citizens/Citizen.h"
#include "../citizens/CitizenBuilder.h"
#include "../citizens/CitizenObserver.h"
#include "../citizens/Director.h"
#include "../citizens/Girl.h"
#include "../citizens/GirlBuilder.h"
#include "../citizens/Man.h"
#include "../citizens/ManBuilder.h"
#include "../citizens/Woman.h"
#include "../citizens/WomanBuilder.h"
#include "../Government/Economy.h"

// Taxes
#include "../Government/Tax.h"
#include "../Government/LowTax.h"
#include "../Government/StandardTax.h"
#include "../Government/HighTax.h"

// Other includes
#include "../Statistics.h"

using namespace std;



void buildAndDisplayCitizen(Director& director) {
    director.construct();
    auto builder = director.getBuilder();  // Retrieve the current builder
    
    if (builder) {
        std::shared_ptr<Citizen> citizen = builder->getCitizen();
        if (citizen) {
            std::cout << "Created Citizen: " << citizen->getDescription() << "\n";
        } else {
            std::cout << "Citizen creation failed.\n";
        }
    } else {
        std::cout << "No builder assigned.\n";
    }
}

void GovernmentCreation(shared_ptr<Government> government){
    cout << "Creating a government..." << endl;
    
    cout << "Government successfully created." << endl;

    cout << "This is the current state of the government: " << endl;
    cout << "=========== Public Services ============" << endl;
    cout << government->getEducation()->getTypeOfPublicService() << " , State: " << government->getEducation()->getState()->getType() << endl;
    cout << government->getHealthCare()->getTypeOfPublicService() << " , State: " << government->getHealthCare()->getState()->getType() << endl;
    cout << government->getPolice()->getTypeOfPublicService() << " , State: " << government->getPolice()->getState()->getType() << endl;
    cout << "========================================" << endl;

    cout << "=========== Taxes ============" << endl;
    cout << "Peronal Tax Rate: " << government->getPersonalTaxRate() << "%" << endl;
    cout << "Business Tax Rate: " << government->getBusinessTaxRate() << "%" << endl;
    cout << "==============================" << endl;

    cout << "========== Implemented Policies ============" << endl;
    cout << "There are currently no implemented policies" << endl;
    cout << "============================================" << endl;




}

void InitialisePersonalTax(shared_ptr<Government> government){
    cout << endl;
    double InputPersonalTax;
    cout << "Please enter the tax rate for personal tax: " << endl;

    // do checks until a valid double rate is entered;
    // Loop until a valid double value is entered
    while (true) {
        std::cin >> InputPersonalTax;

        if (std::cin.fail() || InputPersonalTax < 0.0 || InputPersonalTax > 100.0) {
            std::cout << "Invalid input. Please enter a valid tax rate between 0 and 100: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        } else {
            break;
        }
    }
    
    // set the rate and check in which category of tax state it falls
    
    if(InputPersonalTax <= 20){
        government->setTaxState(make_shared<LowTax>(InputPersonalTax));
    } else if(InputPersonalTax > 20 && InputPersonalTax < 35){
        government->setTaxState(make_shared<StandardTax>(InputPersonalTax));
    } else {
        government->setTaxState(make_shared<HighTax>(InputPersonalTax));
    }
    cout << "Initializing Personal tax..." << endl;

    double InputBusinessTax;
    cout << "Please enter the tax rate for business tax: " << endl;

    // do checks until a valid double rate is entered;
    // Loop until a valid double value is entered
    while (true) {
        std::cin >> InputBusinessTax;

        if (std::cin.fail() || InputBusinessTax < 0.0 || InputBusinessTax > 100.0) {
            std::cout << "Invalid input. Please enter a valid tax rate between 0 and 100: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        } else {
            break;
        }
    }
    
    // set the rate and check in which category of tax state it falls
    
    if(InputBusinessTax <= 20){
        government->setTaxState(make_shared<LowTax>(InputBusinessTax));
    } else if(InputBusinessTax > 20 && InputBusinessTax < 35){
        government->setTaxState(make_shared<StandardTax>(InputBusinessTax));
    } else {
        government->setTaxState(make_shared<HighTax>(InputBusinessTax));
    }
    cout << "Initializing Business tax..." << endl;
    cout << "Tax system implemented" << endl;

}

void Taxation(shared_ptr<Government> government){
    bool done = false;
    while(done == false ){
        int choice = 0;
        cout << "========== Taxation Menu ==============" << endl;
        cout << "1. Increase Personal Tax" << endl;
        cout << "2. Decrease Persoanl Tax" << endl;
        cout << "3. Increase Business Tax" << endl;
        cout << "4. Decrease Business Tax" << endl;
        cout << "5. Collect Personal Tax" << endl;
        cout << "6. Collect Business Tax" << endl;
        cout << "7. Exit" << endl;
        cout << "=======================================" << endl;

        do {
            cout << "Enter your choice (1-7): ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 7) {
                cout << "Invalid input. Please enter a number between 1 and 7." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } else {
                break;
            }
        } while (true);

        switch (choice) {
            case 1:
                double Increase;
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
                double Decrease;
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
                double Increase;
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
                double Decrease;
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
                double Income = government->CollectPersonalTax();
                government->IncreaseAvialableBudget(Income);
                break;
            case 6:
                double BIncome = government->CollectBusinessTax();
                government->IncreaseAvialableBudget(BIncome);
                break;
            case 7:
                cout << "Exiting menu." << endl;
                done = true;
                break;
            default:
                break;
        }
    }
}

void Policies(shared_ptr<Government> government){
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

void PublicServices(shared_ptr<Government> government){
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

void CityBudget(shared_ptr<Government> government){
    // this is just going to show where the government is currently spending money
}

void GovernMentLoop(shared_ptr<Government> government){
    bool Done = false;
    while (Done == false)
    {
        int choice = 0;
        cout << "========== Government Menu ==============" << endl;
        cout << "1. Taxation" << endl;
        cout << "2. Policies" << endl;
        cout << "3. Public Services" << endl;
        cout << "4. City Budget" << endl;
        cout << "5. View Statistics" << endl;
        cout << "6. Exit" << endl;
        cout << "=========================================" << endl;

        do {
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 5) {
                cout << "Invalid input. Please enter a number between 1 and 5." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } else {
                break;
            }
        } while (true);

        switch (choice) {
            case 1:
                cout << "Taxation selected." << endl;
                Taxation(government);
                break;
            case 2:
                cout << "Policies selected." << endl;
                Policies(government);
                break;
            case 3:
                cout << "Public Services selected." << endl;
                PublicServices(government);
                break;
            case 4:
                cout << "City Budget selected." << endl;
                CityBudget(government);
                break;
            case 5:
                // open up stats
                break;
            case 6:
                cout << "Exiting menu." << endl;
                Done = true;
                break;
            default:
                break;
        }
    }
    
}

int main() {
   
    shared_ptr<Government> government = make_shared<Government>();
    GovernmentCreation(government);
    InitialisePersonalTax(government);
    cout << "You are now ready to govern, you will be redirected to the Government Menu" << std::endl;



    
    return 0;
}
