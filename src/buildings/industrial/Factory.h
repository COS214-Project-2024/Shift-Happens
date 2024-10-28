#ifndef FACTORY_H
#define FACTORY_H
#include "IndustrialBuilding.h"
#include "Materials.h"

	class Factory : IndustrialBuilding {

private:
	int partProductionPerHour;
	int productionCostPerHour;
	Materials *materials;
public:
	Factory(int id);
	~Factory();

};

#endif
