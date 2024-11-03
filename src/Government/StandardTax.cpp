#include "StandardTax.h"

#include <memory>
#include <iostream>

StandardTax::StandardTax(std::shared_ptr<Government> government) : Tax(government) {
	this->RunningRate = StandardTLowCap;
	this->RunningRateBusiness = StandardTLowCapBusiness;
}

void StandardTax::higher(double increase) {
	//std::cout << "Entered standard tax higher" <<std::endl;
	this->RunningRate += increase;
	if(this->RunningRate > StandardTHighCap){
		std::shared_ptr<Tax> newTax = std::make_shared<HighTax>(this->government);
		newTax->setBusinessRate(this->getBusinessRate());
		newTax->setPersonalRate(this->getRate());
		government->setTaxState(newTax);
	}
	//std::cout << "Passed standard" << std::endl;
}

void StandardTax::lower(double decrease) {
	this->RunningRate -= decrease;
	if(this->RunningRate < StandardTLowCap){
		std::shared_ptr<Tax> newTax = std::make_shared<LowTax>(this->government);
		newTax->setBusinessRate(this->getBusinessRate());
		newTax->setPersonalRate(this->getRate());
		government->setTaxState(newTax);
	}
}

std::string StandardTax::getType(){
	return "Standard Tax";
}

void StandardTax::lowerBusiness(double decrease){
	this->RunningRateBusiness -= decrease;
	if(this->RunningRateBusiness < StandardTLowCapBusiness){
		std::shared_ptr<Tax> newTax = std::make_shared<LowTax>(this->government);
		newTax->setBusinessRate(this->getBusinessRate());
		newTax->setPersonalRate(this->getRate());
		government->setBusinessTaxState(newTax);
	}
}

void StandardTax::higherBusiness(double increase){
	this->RunningRateBusiness += increase;
	if(this->RunningRateBusiness > StandardTHighCapBusiness){
		std::shared_ptr<Tax> newTax = std::make_shared<HighTax>(this->government);
		newTax->setBusinessRate(this->getBusinessRate());
		newTax->setPersonalRate(this->getRate());
		government->setBusinessTaxState(newTax);
	}
}
