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
//
std::shared_ptr<Building> InfrastructureFactory::createBuilding2(const string& variant)
{
	if (buildingId >= 100) // 99 max buildings
	{
		cout << "You have reached the maximum number of Infrastructure buildings" << endl;
		return nullptr;
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	std::shared_ptr<Building> newBuilding;
	if (variant == "Road")
	{
		//newBuilding = std::make_shared<Road>(idForBuilding);//error
		buildings.push_back(make_shared<Road>(idForBuilding));
	}
	else if (variant == "Railway")
	{
		//newBuilding = std::make_shared<Railway>(idForBuilding); //error
		buildings.push_back(make_shared<Railway>(idForBuilding));
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