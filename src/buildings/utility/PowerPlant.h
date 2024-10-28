#ifndef POWERPLANT_H
#define POWERPLANT_H


#include "UtilityBuilding.h"
class PowerPlant : public UtilityBuilding
{
private:
	int electricityProduction;

public:

	void getElectricityProduction();

	void setElectricityProduction(int electricityProduction);
};

#endif
