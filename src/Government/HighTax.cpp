#include "HighTax.h"

#include <iostream>
void HighTax::higher(double increase) {
	this->RunningRate += increase;
}

void HighTax::lower(double decrease) {
	this->RunningRate -= decrease;
	if(this->RunningRate < HighTLowCap){
		Tax* newTax = new StandardTax;
		// make state change
		government->setTaxState(newTax);
	}
}

std::string HighTax::getType(){
	return "High Tax";
}
