#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuilding.h"
class Factory : public IndustrialBuilding
{

private:
	int partProductionPerHour;
	int productionCostPerHour;
public:
	Factory(int id);
	~Factory();

};

#endif
