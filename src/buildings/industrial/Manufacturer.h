#ifndef MANUFACTURER_H
#define MANUFACTURER_H

#include "IndustrialBuilding.h"

class Manufacturer : public IndustrialBuilding
{

private:
	int productsPerHour;
	int partsUsedPerProduct;
	int profitPerProduct;

public:
	Manufacturer(int id);
	~Manufacturer();
};

#endif
