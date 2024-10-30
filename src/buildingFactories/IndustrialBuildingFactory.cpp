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
//
std::shared_ptr<Building> IndustrialBuildingFactory::createBuilding2(const string& variant){
	if (buildingId >= 100) // 99 max buildings
	{
		cout << "You have reached the maximum number of Industrial buildings" << endl;
		return nullptr;
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	std::shared_ptr<Building> newBuilding;
	if (variant == "Factory")
	{
		newBuilding = std::make_shared<Factory>(idForBuilding);
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
}//
IndustrialBuildingFactory::~IndustrialBuildingFactory()
{
	
}

void IndustrialBuildingFactory::print()
{
	cout << "Printing Industrial Buildings" << endl;
	for (auto building : buildings)
	{
		building->print();
	}
}