#include "HighTax.h"

#include <iostream>
void HighTax::higher() {
	std::cout << "Tax is already at its highest" << std::endl;
}

void HighTax::lower() {
	Tax* newTax = new StandardTax;
	government->setTaxState(newTax);
}
