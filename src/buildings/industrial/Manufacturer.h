#ifndef MANUFACTURER_H
#define MANUFACTURER_H
#include "IndustrialBuilding.h"
#include "Materials.h"

class Manufacturer : public IndustrialBuilding{

private:
	int satisfactionScore;
    int numberOfEmployees;
	int productsPerHour;
	int partsUsedPerProduct;
	int profitPerProduct;
	Materials *materials;

public:
	Manufacturer(int id);
	~Manufacturer();
	virtual void print() const override;
};

#endif
