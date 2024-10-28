#include "IndustrialBuildingFactory.h"

IndustrialBuildingFactory::IndustrialBuildingFactory(int id)
: BuildingFactory(id)
{
	
}
void IndustrialBuildingFactory::createBuilding(string variant){
	if (buildingId >= 100) // 99 max buildings
	{
		cout << "You have reached the maximum number of Industrial buildings" << endl;
		return;
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	if (variant == "Factory")
	{
		buildings.push_back(make_shared<Factory>(idForBuilding));
	}
	else if (variant == "Warehouse")
	{
		buildings.push_back(make_shared<Warehouse>(idForBuilding));
	}
	else if (variant == "Manufacturer")
	{
		buildings.push_back(make_shared<Manufacturer>(idForBuilding));
	}
	else
	{
		cout << "Invalid building type" << endl;
		buildingId--;
	}
}
IndustrialBuildingFactory::~IndustrialBuildingFactory()
{
	
}
