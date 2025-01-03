#include "ResidentialBuildingFactory.h"

ResidentialBuildingFactory::ResidentialBuildingFactory(int id)
: BuildingFactory(id)
{
	
}

void ResidentialBuildingFactory::createBuilding(string variant){
	if (buildingId >= 100) // 100 max buildings
	{
		throw "Max Residential buildings reached";
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	if (variant == "House")
	{
		buildings.push_back(make_shared<House>(idForBuilding));
	}
	else if (variant == "TownHouse")
	{
		buildings.push_back(make_shared<TownHouse>(idForBuilding));
	}
	else if (variant == "Estate")
	{
		buildings.push_back(make_shared<Estate>(idForBuilding));
	}
	else if (variant == "Apartment")
	{
		buildings.push_back(make_shared<Apartment>(idForBuilding));
	}
	else
	{
		throw "Invalid Residential building type";
	}
}

ResidentialBuildingFactory::~ResidentialBuildingFactory()
{

}

void ResidentialBuildingFactory::print()
{
	cout << "Printing Residential Buildings" << endl;
	for (auto building : buildings)
	{
		building->print();
	}
}

shared_ptr<ResidentialBuilding> ResidentialBuildingFactory::getBuilding()
{
	//check if the vector is empty
	if (buildings.empty())
	{
		throw "No Residential buildings created";
	}
	return buildings.back();
}