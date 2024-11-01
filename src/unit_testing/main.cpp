#include <iostream>
#include <memory>
#include <vector>

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

// Taxes
#include "../Government/Tax.h"
#include "../Government/LowTax.h"
#include "../Government/StandardTax.h"
#include "../Government/HighTax.h"

// Other includes
#include "../Statistics.h"

using namespace std;

int main() {
    cout << "Creating a government..." << endl;
    shared_ptr<Government> government = make_shared<Government>();
    cout << "Government successfully created." << endl;

    cout << "Initializing taxes, public service states, and policies..." << endl;
    
    // Tax options
    shared_ptr<Tax> lowTax = make_shared<LowTax>();
    shared_ptr<Tax> standardTax = make_shared<StandardTax>();
    shared_ptr<Tax> highTax = make_shared<HighTax>();

    // Public service states
    shared_ptr<PublicServiceState> standardState = make_shared<Standard>();
    shared_ptr<PublicServiceState> outdatedState = make_shared<Outdated>();
    shared_ptr<PublicServiceState> modernState = make_shared<Modern>();

    // Policies
    shared_ptr<Policy> boostEducation = make_shared<BoostEducationPolicy>(government->getEducation());
    shared_ptr<Policy> boostHealthCare = make_shared<BoostHealthCarePolicy>(government->getHealthCare());
    shared_ptr<Policy> boostPolice = make_shared<BoostPolicePolicy>(government->getPolice());

    cout << "Taxes, public service states, and policies successfully initialized." << endl;

    // Set tax states
    cout << "Setting taxes..." << endl;
    government->setTaxState(lowTax);  // Set personal tax rate
    government->setBusinessTaxState(standardTax);  // Set business tax rate
    cout << "Taxes successfully set." << endl;

    // Implement initial public service states
    cout << "Setting public service states..." << endl;
    government->getEducation()->setPublicServiceState(standardState);
   government->getHealthCare()->setPublicServiceState(outdatedState);
   government->getPolice()->setPublicServiceState(modernState);

    cout << "Public service states successfully set." << endl;

    // Implement a sample policy (demonstration)
    cout << "\nAttempting to implement a new policy..." << endl;
    government->addExecutePolicy();

    // Display remaining budget after policy implementation
    cout << "Remaining spending budget: $" << government->getAvailableSpendingBudget() << endl;

    // Display all currently implemented policies
    cout << "\nPolicies currently implemented:" << endl;
    for (const auto& policy : government->getCurrentPolicies()) {
        cout << "- " << policy->getPolicyType() << endl;
    }

    cout << "Program completed successfully." << endl;

    return 0;
}
