#include "StandardTax.h"

void StandardTax::higher(double increase) {
	this->RunningRate += increase;
	if(this->RunningRate > StandardTHighCap){
		Tax* newTax = new HighTax;
		// make state change
		government->setTaxState(newTax);
	}
}

void StandardTax::lower(double decrease) {
	this->RunningRate -= decrease;
	if(this->RunningRate < StandardTLowCap){
		Tax* newTax = new LowTax;
		government->setTaxState(newTax);
	}
}

std::string StandardTax::getType(){
	return "Standard Tax";
}
