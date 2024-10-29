#include "Government.h"

void Government::setPersonalTaxLower(double decrease) {
	PersonalTaxState->lower(decrease);
	this->PersonalTaxRate = PersonalTaxState->getRate();
}

void Government::setPersonalTaxHigher(double increase) {
	PersonalTaxState->higher(increase);
	this->PersonalTaxRate = PersonalTaxState->getRate();
}

void Government::addPolicy(Policy* newPolicy) {
	PolicyState.push_back(newPolicy);
}

void Government::executePolicy() {
	for(Policy* temp: PolicyState){
		temp->executePolicy();
	}
}

void Government::setTaxState(Tax* tax){
	this->PersonalTaxState = tax;
	this->notify();
}

Tax* Government::getTax(){
	return PersonalTaxState;
}

std::vector<Policy*> Government::getPolicies(){
	return PolicyState;
}

Tax* Government::getBusinessTax(){
	return BusinessTaxState;
}

void Government::setBusinessTaxState(Tax* tax){
	this->BusinessTaxState = tax;
	// notify businesses
}
