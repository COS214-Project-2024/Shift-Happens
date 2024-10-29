#include "Government.h"

#include <algorithm>

void Government::setPersonalTaxLower(double decrease) {
	PersonalTaxState->lower(decrease);
	this->PersonalTaxRate = PersonalTaxState->getRate();
}

void Government::setPersonalTaxHigher(double increase) {
	PersonalTaxState->higher(increase);
	this->PersonalTaxRate = PersonalTaxState->getRate();
}

void Government::addPolicy(std::shared_ptr<Policy> newPolicy) {
	PolicyState.push_back(newPolicy);
}

void Government::executePolicy() {
	for(std::shared_ptr<Policy> temp: PolicyState){
		temp->executePolicy(this->AvailableSpendingBudget);
	}
}

void Government::setTaxState(std::shared_ptr<Tax> tax){
	this->PersonalTaxState = tax;
	this->notify();
}

std::shared_ptr<Tax> Government::getTax(){
	return PersonalTaxState;
}

std::vector<std::shared_ptr<Policy>> Government::getPolicies(){
	return PolicyState;
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

void Government::removePolicy(std::shared_ptr<Policy> removePolicy) {
    auto it = std::remove_if(PolicyState.begin(), PolicyState.end(),
                             [&removePolicy](const std::shared_ptr<Policy>& policy) {
                                 return policy == removePolicy;
                             });
    
    if (it != PolicyState.end()) {
        PolicyState.erase(it, PolicyState.end());
    }
}
