#include "ResidentialBuildingFactory.h"

ResidentialBuildingFactory::ResidentialBuildingFactory(int id)
: BuildingFactory(id)
{
	
}

void ResidentialBuildingFactory::createBuilding(string variant){
	if (buildingId >= 100) // 100 max buildings
	{
		cout << "You have reached the maximum number of Residential buildings" << endl;
		return;
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
		cout << "Invalid building type" << endl;
		buildingId--;
	}
}
//
std::shared_ptr<Building> ResidentialBuildingFactory::createBuilding2(const string& variant){
	if (buildingId >= 100) // 100 max buildings
	{
		cout << "You have reached the maximum number of Residential buildings" << endl;
		return nullptr;
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	std::shared_ptr<Building> newBuilding;

	if (variant == "House")
	{
		newBuilding = std::make_shared<House>(idForBuilding);
		buildings.push_back(make_shared<House>(idForBuilding));
	}
	else if (variant == "TownHouse")
	{
		newBuilding = std::make_shared<TownHouse>(idForBuilding);
		buildings.push_back(make_shared<TownHouse>(idForBuilding));
	}
	else if (variant == "Estate")
	{
		newBuilding = std::make_shared<Estate>(idForBuilding);
		buildings.push_back(make_shared<Estate>(idForBuilding));
	}
	else if (variant == "Apartment")
	{
		newBuilding = std::make_shared<Apartment>(idForBuilding);
		buildings.push_back(make_shared<Apartment>(idForBuilding));
	}
	else
	{
		cout << "Invalid building type" << endl;
		buildingId--;
	}
	newBuilding->print();
	return newBuilding;
}



//
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