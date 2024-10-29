#include "InfrastructureFactory.h"

InfrastructureFactory::InfrastructureFactory(int id)
: BuildingFactory(id)
{

}

void InfrastructureFactory::createBuilding(string variant)
{
	if (buildingId >= 100) // 99 max buildings
	{
		cout << "You have reached the maximum number of Infrastructure buildings" << endl;
		return;
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	if (variant == "Road")
	{
		buildings.push_back(make_shared<Road>(idForBuilding));
	}
	else if (variant == "Railway")
	{
		buildings.push_back(make_shared<Railway>(idForBuilding));
	}
	else
	{
		cout << "Invalid building type" << endl;
		buildingId--;
	}
}

InfrastructureFactory::~InfrastructureFactory()
{
	
}

void InfrastructureFactory::print()
{
	cout << "Printing Infrastructure Buildings" << endl;
	for (auto building : buildings)
	{
		building->print();
	}
}