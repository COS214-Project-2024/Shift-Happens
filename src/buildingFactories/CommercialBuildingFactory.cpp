#include "CommercialBuildingFactory.h"

CommercialBuildingFactory::CommercialBuildingFactory(int id)
: BuildingFactory(id)
{
}

void CommercialBuildingFactory::createBuilding(string variant)
{
	if (buildingId >= 100) // 99 max buildings
	{
		cout << "You have reached the maximum number of Commercial buildings" << endl;
		return;
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	if (variant == "Store")
	{
		buildings.push_back(make_shared<Store>(idForBuilding));
	}
	else if (variant == "Office")
	{
		buildings.push_back(make_shared<Office>(idForBuilding));
	}
	else if (variant == "Mall")
	{
		buildings.push_back(make_shared<Mall>(idForBuilding));
	}
	else
	{
		cout << "Invalid building type" << endl;
		buildingId--;
	}
}

CommercialBuildingFactory::~CommercialBuildingFactory()
{
	
}

void CommercialBuildingFactory::print()
{
	cout << "Printing Commercial Buildings" << endl;
	for (auto building : buildings)
	{
		building->print();
	}
}

shared_ptr<CommercialBuilding> CommercialBuildingFactory::getBuilding()
{
	//check if the vector is empty
	if (buildings.empty())
	{
		throw "No Commercial buildings created";
	}
	return buildings.back();
}
