#ifndef UTILITYBUILDINGFACTORY_H
#define UTILITYBUILDINGFACTORY_H

#include "BuildingFactory.h"

#include "../buildings/utility/PowerPlant.h"
#include "../buildings/utility/WaterSupply.h"
#include "../buildings/utility/LandFill.h"
#include "../buildings/utility/SewagePlant.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class UtilityBuildingFactory : public BuildingFactory
{
private:
	vector<shared_ptr<UtilityBuilding>> buildings;
public:
	UtilityBuildingFactory(int id);
	void createBuilding(string variant);
	~UtilityBuildingFactory();
};

#endif
