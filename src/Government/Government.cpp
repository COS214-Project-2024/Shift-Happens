#include "Government.h"

#include <algorithm>
#include <memory>
#include <iostream>

Government::Government() {
    // Initialize the public services
    education = std::make_shared<Education>();
    healthcare = std::make_shared<HealthCare>();
    police = std::make_shared<Police>();

    // Now that the public services are initialized, create the policies
    AvailablePolicies.push_back(std::make_shared<BoostEducationPolicy>(education));
    AvailablePolicies.push_back(std::make_shared<BoostHealthCarePolicy>(healthcare));
    AvailablePolicies.push_back(std::make_shared<BoostPolicePolicy>(police));
}

void Government::setPersonalTaxLower(double decrease) {
	PersonalTaxState->lower(decrease);
	this->PersonalTaxRate = PersonalTaxState->getRate();
}

void Government::setPersonalTaxHigher(double increase) {
	PersonalTaxState->higher(increase);
	this->PersonalTaxRate = PersonalTaxState->getRate();
}

void Government::addExecutePolicy() {
    // Show all the possible policies
    std::cout << "Here are all the available policies and their costs: " << std::endl;
    for (const auto& temp : AvailablePolicies) {
        std::cout << temp->getPolicyType() << ", Cost: " << temp->getCostOfPolicy() << std::endl;
    }
    std::cout << "\nHere are the policies you have currently implemented: " << std::endl;
    for (const auto& temp : ImplementedPolicies) {
        std::cout << temp->getPolicyType() << std::endl;
    }
    std::cout << std::endl;

    // Ask if the user wants to implement a new policy
    std::string answer;
    while (true) {
        std::cout << "Would you like to implement a new Policy? (Yes/No): ";
        std::cin >> answer;
        if (answer == "Yes" || answer == "No") break;
        std::cout << "Invalid input. Please enter 'Yes' or 'No'." << std::endl;
    }

    if (answer == "No") return;

    // Show policies available for implementation
    std::cout << "\nThese are the available policies and their costs: " << std::endl;
    std::shared_ptr<Policy> policiesToImplement[3];
    int count = 0;
    for (const auto& tempAvai : AvailablePolicies) {
        bool alreadyImplemented = false;
        for (const auto& tempImpl : ImplementedPolicies) {
            if (tempAvai->getPolicyType() == tempImpl->getPolicyType()) {
                alreadyImplemented = true;
                break;
            }
        }
        if (!alreadyImplemented) {
            policiesToImplement[count++] = tempAvai;
            std::cout << tempAvai->getPolicyType() << ", Cost: " << tempAvai->getCostOfPolicy() << std::endl;
        }
    }

    // Choose a policy to implement
    std::string policyChosen;
    bool validChoice = false;
    int position = -1;

    while (!validChoice) {
        std::cout << "Enter the name of the policy you would like to implement: ";
        std::cin >> policyChosen;

        for (int i = 0; i < count; ++i) {
            if (policiesToImplement[i]->getPolicyType() == policyChosen) {
                position = i;
                validChoice = true;
                break;
            }
        }

        if (!validChoice) {
            std::cout << "Invalid policy name. Please enter a valid policy from the list above." << std::endl;
        }
    }

    // Verify purchase and implement policy
    if (policiesToImplement[position]->getCostOfPolicy() > AvailableSpendingBudget) {
        std::cout << "You do not have enough funding to implement the policy." << std::endl;
        std::cout << "Ending process" << std::endl;
    } else {
        std::cout << "Implementing the " << policiesToImplement[position]->getPolicyType() << std::endl;
        policiesToImplement[position]->executePolicy();
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
	// notify businesses
	// still needs to be added
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