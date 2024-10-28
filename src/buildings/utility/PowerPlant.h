#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "UtilityBuilding.h"

class PowerPlant : public UtilityBuilding
{
private:
	int electricityProduction;

public:
	PowerPlant(int id);
	void getElectricityProduction();
	void setElectricityProduction(int electricityProduction);
	virtual void print() const override;
};

#endif
