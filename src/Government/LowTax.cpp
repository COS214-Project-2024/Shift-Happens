#include "LowTax.h"

#include <iostream>

void LowTax::higher(double increase) {
	this->RunningRate += increase;
	if(this->RunningRate > LowTHighCap){
		Tax* newTax = new StandardTax;
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
