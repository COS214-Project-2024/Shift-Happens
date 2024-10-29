#include "LowTax.h"

#include <iostream>

void LowTax::higher(double increase) {
	this->RunningRate += increase;
	if(this->RunningRate > LowTHighCap){
		std::shared_ptr<Tax> newTax = make_shared<StandardTax>();
		// make tax state change
		government->setTaxState(newTax);
	}

}

void LowTax::lower(double decrease) {
	this->RunningRate -= decrease;
	if(this->RunningRate < 0)
	{
		this->RunningRate = 0;
	}
}

std::string LowTax::getType(){
	return "Low Tax";
}

void LowTax::lowerBusiness(double decrease){
	this->RunningRateBusiness -= decrease;
	if(this->RunningRate < 0)
	{
		this->RunningRate = 0;
	}
}

void LowTax::higherBusiness(double increase){
	this->RunningRateBusiness += increase;
	if(this->RunningRateBusiness > LowTHighCap){
		std::shared_ptr<Tax> newTax = make_shared<StandardTax>();
		government->setBusinessTaxState(newTax);
	}
}
