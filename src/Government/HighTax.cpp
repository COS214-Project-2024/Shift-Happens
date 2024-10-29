#include "HighTax.h"

#include <iostream>
#include <memory>

void HighTax::higher(double increase) {
	this->RunningRate += increase;
	if(RunningRateBusiness > 100){
		RunningRateBusiness = 100;
	}
}

void HighTax::lower(double decrease) {
	this->RunningRate -= decrease;
	if(this->RunningRate < HighTLowCap){
		std::shared_ptr<Tax> newTax = std::make_shared<StandardTax>();
		// make state change
		government->setTaxState(newTax);
	}
}

std::string HighTax::getType(){
	return "High Tax";
}

void HighTax::higherBusiness(double increase){
	this->RunningRateBusiness += increase;
	if(RunningRateBusiness > 100){
		RunningRateBusiness = 100;
	}
}

void HighTax::lowerBusiness(double decrease){
	this->RunningRateBusiness -= decrease;
	if(this->RunningRateBusiness < HighTLowCap){
		std::shared_ptr<Tax> newTax = std::make_shared<StandardTax>();
		government->setBusinessTaxState(newTax);
	}
}