#include "Government.h"

void Government::setPersonalTaxLower(double decrease) {
	TaxState->lower(decrease);
	this->PersonalTaxRate = TaxState->getRate();
}

void Government::setPersonalTaxHigher(double increase) {
	TaxState->higher(increase);
	this->PersonalTaxRate = TaxState->getRate();
}

void Government::addPolicy(Policy* newPolicy) {
	PolicyState.push_back(newPolicy);
}

void Government::executePolicy() {
	for(Policy* temp: PolicyState){
		temp->handle();
	}
}

void Government::setTaxState(Tax* tax){
	this->TaxState = tax;
	this->notify();
}

Tax* Government::getTax(){
	return TaxState;
}

std::vector<Policy*> Government::getPolicies(){
	return PolicyState;
}
