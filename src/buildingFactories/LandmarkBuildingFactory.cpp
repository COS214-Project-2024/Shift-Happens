#include "LandmarkBuildingFactory.h"

LandmarkBuildingFactory::LandmarkBuildingFactory(int id)
: BuildingFactory(id)
{
	
}	

void LandmarkBuildingFactory::createBuilding(string variant)
{
	if (buildingId >= 100) // 99 max buildings
	{
		cout << "You have reached the maximum number of Landmark buildings" << endl;
		return;
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	if (variant == "Park")
	{
		buildings.push_back(make_shared<Park>(idForBuilding));
	}
	else if (variant == "Monument")
	{
		buildings.push_back(make_shared<Monument>(idForBuilding));
	}
	else if (variant == "CulturalCenter")
	{
		buildings.push_back(make_shared<CulturalCenter>(idForBuilding));
	}
	else
	{
		cout << "Invalid building type" << endl;
		buildingId--;
	}
}
//
std::shared_ptr<Building> LandmarkBuildingFactory::createBuilding2(const string& variant)
{
	if (buildingId >= 100) // 99 max buildings
	{
		cout << "You have reached the maximum number of Landmark buildings" << endl;
		return nullptr;
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	std::shared_ptr<Building> newBuilding;
	if (variant == "Park")
	{
		newBuilding = std::make_shared<Park>(idForBuilding);
		buildings.push_back(make_shared<Park>(idForBuilding));
	}
	else if (variant == "Monument")
	{
		newBuilding = std::make_shared<Monument>(idForBuilding);
		buildings.push_back(make_shared<Monument>(idForBuilding));
	}
	else if (variant == "CulturalCenter")
	{
		newBuilding = std::make_shared<CulturalCenter>(idForBuilding);
		buildings.push_back(make_shared<CulturalCenter>(idForBuilding));
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


LandmarkBuildingFactory::~LandmarkBuildingFactory()
{
	
}

void LandmarkBuildingFactory::print()
{
	cout << "Printing Landmark Buildings" << endl;
	for (auto building : buildings)
	{
		building->print();
	}
}