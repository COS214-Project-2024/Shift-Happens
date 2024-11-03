#include "Government.h"
#include "../citizens/ManBuilder.h"
#include "../citizens/WomanBuilder.h"
#include "../citizens/BoyBuilder.h"
#include "../citizens/GirlBuilder.h"

#include <algorithm>
#include <memory>
#include <iostream>

Government::Government() {
    // Initially set tax states
    this->AvailableSpendingBudget = 150000; // Initial budget

    // Initialize the public services
    // Initially public services states will be at the worst
    education = std::make_shared<Education>();
    education->setPublicServiceState(make_shared<Outdated>());

    healthcare = std::make_shared<HealthCare>();
    healthcare->setPublicServiceState(make_shared<Outdated>());

    police = std::make_shared<Police>();
    police->setPublicServiceState(make_shared<Outdated>());

    // Now that the public services are initialized, create the policies
    AvailablePolicies.push_back(std::make_shared<BoostEducationPolicy>(education));
    AvailablePolicies.push_back(std::make_shared<BoostHealthCarePolicy>(healthcare));
    AvailablePolicies.push_back(std::make_shared<BoostPolicePolicy>(police));

    
    PersonalTaxRate = 0;
    BusinessTaxRate = 0;

}

double Government::getPersonalTaxRate(){
    return this->PersonalTaxRate;
}

double Government::getBusinessTaxRate(){
    return this->BusinessTaxRate;
}

double Government::setPersonalTaxRate(double rate){
    this->PersonalTaxRate = rate;
}

double Government::setBusinessTaxRate(double rate){
    this->BusinessTaxRate = rate;
}

void Government::setPersonalTaxLower(double decrease) {
	PersonalTaxState->lower(decrease);
	this->PersonalTaxRate = PersonalTaxState->getRate();
}

void Government::setPersonalTaxHigher(double increase) {
	PersonalTaxState->higher(increase);
	this->PersonalTaxRate = PersonalTaxState->getRate();
}

// Helper function to convert strings to lowercase
std::string Government::toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void Government::addExecutePolicy() {
    // Display available policies and their costs
    std::cout << "Here are all the available policies and their costs:\n";
    for (const auto& policy : AvailablePolicies) {
        std::cout << policy->getPolicyType() << ", Cost: " << policy->getCostOfPolicy() << '\n';
    }

    // Display already implemented policies
    std::cout << "\nCurrently implemented policies:\n";
    for (const auto& policy : ImplementedPolicies) {
        std::cout << policy->getPolicyType() << '\n';
    }
    std::cout << '\n';

    // Confirm if the user wants to implement a new policy
    std::string answer;
    while (true) {
        std::cout << "Would you like to implement a new Policy? (Yes/No): ";
        std::cin >> answer;
        answer = toLowerCase(answer);
        if (answer == "yes" || answer == "no") break;
        std::cout << "Invalid input. Please enter 'Yes' or 'No'.\n";
    }

    if (answer == "no") return;

    // Gather unimplemented policies that are available for selection
    std::vector<std::shared_ptr<Policy>> policiesToImplement;
    for (const auto& availablePolicy : AvailablePolicies) {
        bool alreadyImplemented = false;
        for (const auto& implementedPolicy : ImplementedPolicies) {
            if (toLowerCase(availablePolicy->getPolicyType()) == toLowerCase(implementedPolicy->getPolicyType())) {
                alreadyImplemented = true;
                break;
            }
        }
        if (!alreadyImplemented) {
            policiesToImplement.push_back(availablePolicy);
            std::cout << availablePolicy->getPolicyType() << ", Cost: " << availablePolicy->getCostOfPolicy() << '\n';
        }
    }

    // No unimplemented policies available
    if (policiesToImplement.empty()) {
        std::cout << "No new policies available for implementation.\n";
        return;
    }

    // Choose a policy to implement
    std::string policyChosen;
    std::shared_ptr<Policy> selectedPolicy = nullptr;

    std::cin.ignore(); // Clear the newline character left by std::cin >> answer
    while (selectedPolicy == nullptr) {
        std::cout << "Enter the name of the policy you would like to implement: ";
        std::getline(std::cin, policyChosen);
        policyChosen = toLowerCase(policyChosen);

        for (const auto& policy : policiesToImplement) {
            if (toLowerCase(policy->getPolicyType()) == policyChosen) {
                selectedPolicy = policy;
                break;
            }
        }

        if (!selectedPolicy) {
            std::cout << "Invalid policy name. Please enter a valid policy from the list above.\n";
        }
    }

    // Check budget and implement policy if possible
    if (selectedPolicy->getCostOfPolicy() > AvailableSpendingBudget) {
        std::cout << "Insufficient funds to implement " << selectedPolicy->getPolicyType() << ".\n";
    } else {
        std::cout << "Implementing " << selectedPolicy->getPolicyType() << ".\n";
        selectedPolicy->executePolicy();
        
        // Deduct the cost and add to implemented policies
        AvailableSpendingBudget -= selectedPolicy->getCostOfPolicy();
        ImplementedPolicies.push_back(selectedPolicy);
        std::cout << "Policy implemented successfully. Remaining budget: " << AvailableSpendingBudget << '\n';
    }
}




void Government::setTaxState(std::shared_ptr<Tax> tax){
	this->PersonalTaxState = tax;
	this->notify();
}

std::shared_ptr<Tax> Government::getTax(){
	return PersonalTaxState;
}

std::vector<std::shared_ptr<Policy>> Government::getCurrentPolicies(){
	return ImplementedPolicies;
}

std::shared_ptr<Tax> Government::getBusinessTax(){
	return BusinessTaxState;
}

void Government::setBusinessTaxState(std::shared_ptr<Tax> tax){
	this->BusinessTaxState = tax;
}

void Government::setBusinessTaxHigher(double increase){
	BusinessTaxState->higherBusiness(increase);
	this->BusinessTaxRate = BusinessTaxState->getBusinessRate();
}

void Government::setBusinessTaxLower(double decrease){
	BusinessTaxState->lowerBusiness(decrease);
	this->BusinessTaxRate = BusinessTaxState->getBusinessRate();
}

double Government::getAvailableSpendingBudget(){
	return AvailableSpendingBudget;
}


std::shared_ptr<Education> Government::getEducation() const{
    return education;
}

std::shared_ptr<HealthCare> Government::getHealthCare() const{
    return healthcare;
}

std::shared_ptr<Police> Government::getPolice() const{
    return police;
}

void Government::removeCitizen(){
    CitizenCollection.pop_back();
}

void Government::addCitizen(){
    std::string Answer;
    std::cout << "Specify the type of citizen you would like to add: Man/Woman/Boy/Girl" << std::endl;

    while (true) {
        std::cin >> Answer;

        if (Answer == "Man" || Answer == "man") {  
            CitizenDirector = std::make_shared<Director>(std::make_shared<ManBuilder>());
            CitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = CitizenDirector->getBuilder()->getCitizen();
            CitizenCollection.push_back(newCitizen);
            break;
        } else if (Answer == "Woman" || Answer == "woman") {
            CitizenDirector = std::make_shared<Director>(std::make_shared<WomanBuilder>());
            CitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = CitizenDirector->getBuilder()->getCitizen();
            CitizenCollection.push_back(newCitizen);
            break;
        } else if (Answer == "Boy" || Answer == "boy") {
            CitizenDirector = std::make_shared<Director>(std::make_shared<BoyBuilder>());
            CitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = CitizenDirector->getBuilder()->getCitizen();
            CitizenCollection.push_back(newCitizen);
            break;
        } else if (Answer == "Girl" || Answer == "girl") {
            CitizenDirector = std::make_shared<Director>(std::make_shared<GirlBuilder>());
            CitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = CitizenDirector->getBuilder()->getCitizen();
            CitizenCollection.push_back(newCitizen);
            break;
        } else {
            std::cout << "Invalid input. Please enter one of the following: Man, Woman, Boy, or Girl." << std::endl;
        }
    }
}


void Government::addCitizen(std::shared_ptr<Citizen> newCitizen){
    CitizenCollection.push_back(newCitizen);
}

double Government::CollectPersonalTax(){
    double incomeTax;
    for(shared_ptr<Citizen> temp: CitizenCollection){
        if(temp->getDescription() != "Man" || temp->getDescription() != "Woman"){
            incomeTax += temp->getIncome() * this->PersonalTaxRate/100;
        }
    }

    return incomeTax;
}

double Government::CollectBusinessTax(){

}

double Government::getIncome(){
    return CollectBusinessTax() + CollectPersonalTax();
}

void Government::IncreaseAvialableBudget(double increase){
    this->AvailableSpendingBudget += increase;
}