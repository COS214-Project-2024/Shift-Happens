#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "UtilityBuilding.h"

class PowerPlant : public UtilityBuilding
{
private:
	int electricityProduction;

public:
	PowerPlant(int id);
	double getElectricityProduction();
	void setElectricityProduction(int electricityProduction);
	virtual void print();
	~PowerPlant() override = default;
};

#endif