#include "HighTax.h"

#include <iostream>
void HighTax::higher() {
	std::cout << "Tax is already at its highest" << std::endl;
}

void HighTax::lower() {
	Tax* newTax = new StandardTax;
	// make state change
	government->setTaxState(newTax);
}

std::string HighTax::getType(){
	return "High Tax";
}
