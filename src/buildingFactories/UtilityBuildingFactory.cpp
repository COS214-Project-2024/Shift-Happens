#include "UtilityBuildingFactory.h"

UtilityBuildingFactory::UtilityBuildingFactory(int id)
: BuildingFactory(id)
{
}

void UtilityBuildingFactory::createBuilding(string variant)
{
	if (buildingId >= 100) // 99 max buildings
	{
		cout << "You have reached the maximum number of Utility buildings" << endl;
		return;
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	if (variant == "PowerPlant")
	{
		buildings.push_back(make_shared<PowerPlant>(idForBuilding));
	}
	else if (variant == "WaterSupply")
	{
		buildings.push_back(make_shared<WaterSupply>(idForBuilding));
	}
	else if (variant == "Landfill")
	{
		buildings.push_back(make_shared<LandFill>(idForBuilding));
	}
	else if (variant == "SewagePlant")
	{
		buildings.push_back(make_shared<SewagePlant>(idForBuilding));
	}
	else
	{
		cout << "Invalid building type" << endl;
		buildingId--;
	}
}

UtilityBuildingFactory::~UtilityBuildingFactory()
{
	
}

void UtilityBuildingFactory::print()
{
	cout << "Printing Utility Buildings" << endl;
	for (auto building : buildings)
	{
		building->print();
	}
}

shared_ptr<UtilityBuilding> UtilityBuildingFactory::getBuilding()
{
	//check if the vector is empty
	if (buildings.empty())
	{
		throw "No Utility buildings created";
	}

	//return the last building created
	return buildings.back();
}