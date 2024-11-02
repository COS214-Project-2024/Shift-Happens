#include "StandardTax.h"

#include <memory>

StandardTax::StandardTax(){
	this->RunningRate = StandardTLowCap;
	this->RunningRateBusiness = StandardTLowCapBusiness;
}

void StandardTax::higher(double increase) {
	this->RunningRate += increase;
	if(this->RunningRate > StandardTHighCap){
		std::shared_ptr<Tax> newTax = std::make_shared<HighTax>();
		// make state change
		government->setTaxState(newTax);
	}
}

void StandardTax::lower(double decrease) {
	this->RunningRate -= decrease;
	if(this->RunningRate < StandardTLowCap){
		std::shared_ptr<Tax> newTax = std::make_shared<LowTax>();
		government->setTaxState(newTax);
	}
}

std::string StandardTax::getType(){
	return "Standard Tax";
}

void StandardTax::lowerBusiness(double decrease){
	this->RunningRateBusiness -= decrease;
	if(this->RunningRateBusiness < StandardTLowCapBusiness){
		std::shared_ptr<Tax> newTax = std::make_shared<LowTax>();
		government->setBusinessTaxState(newTax);
	}
}

void StandardTax::higherBusiness(double increase){
	this->RunningRateBusiness += increase;
	if(this->RunningRateBusiness > StandardTHighCapBusiness){
		std::shared_ptr<Tax> newTax = std::make_shared<HighTax>();
		government->setBusinessTaxState(newTax);
	}
}
