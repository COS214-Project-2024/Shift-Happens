#include "StandardTax.h"

void StandardTax::higher() {
	Tax* newTax = new HighTax;
	government->setTaxState(newTax);
}

void StandardTax::lower() {
	Tax* newTax = new LowTax;
	government->setTaxState(newTax);
}
