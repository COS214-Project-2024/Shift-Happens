#ifndef POWERPLANT_H
#define POWERPLANT_H


#include "UtilityBuilding.h"
class PowerPlant : public UtilityBuilding
{

public:
	int electricityProduction;

	void getElectricityProduction();

	void setElectricityProduction(int electricityProduction);
};

#endif
