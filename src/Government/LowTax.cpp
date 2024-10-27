#include "LowTax.h"

#include <iostream>

void LowTax::higher() {
	Tax* newTax = new StandardTax;
	// make tax state change
	government->setTaxState(newTax);

}

void LowTax::lower() {
	std::cout << "Tax is already at its lowerst" << std::endl;
}

std::string LowTax::getType(){
	return "Low Tax";
}
