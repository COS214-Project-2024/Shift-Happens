#include "StandardTax.h"

void StandardTax::higher() {
	Tax* newTax = new HighTax;
	// make state change
	government->setTaxState(newTax);
}

void StandardTax::lower() {
	Tax* newTax = new LowTax;
	government->setTaxState(newTax);
}

std::string StandardTax::getType(){
	return "Standard Tax";
}
