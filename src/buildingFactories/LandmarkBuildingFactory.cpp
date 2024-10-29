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

shared_ptr<LandMark> LandmarkBuildingFactory::getBuilding()
{
	//check if the vector is empty
	if (buildings.empty())
	{
		throw "No Landmark buildings created";
	}
	return buildings.back();
}