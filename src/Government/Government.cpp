#include "Government.h"

void Government::setTaxLower() {
	TaxState->lower();
}

void Government::setTaxHigher() {
	TaxState->higher();
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
}

Tax* Government::getTax(){
	return TaxState;
}
