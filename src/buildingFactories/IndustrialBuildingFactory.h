#ifndef INDUSTRIALBUILDINGFACTORY_H
#define INDUSTRIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "../buildings/industrial/Factory.h"
#include "../buildings/industrial/Warehouse.h"
#include "../buildings/industrial/Manufacturer.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class IndustrialBuildingFactory : public BuildingFactory
{
private:
	vector<shared_ptr<Building>> buildings;
public:
	IndustrialBuildingFactory(int id);
	void createBuilding(string variant);
	~IndustrialBuildingFactory();
};



#endif
