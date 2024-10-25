#include "LowTax.h"

#include <iostream>

void LowTax::higher() {
	Tax* newTax = new StandardTax;
	government->setTaxState(newTax);
}

void LowTax::lower() {
	std::cout << "Tax is already at its lowerst" << std::endl;
}
