#include "ResidentialBuildingFactory.h"

ResidentialBuildingFactory::ResidentialBuildingFactory(int id)
: BuildingFactory(id)
{
	buildingId = 0;
}
ResidentialBuildingFactory::~ResidentialBuildingFactory()
{

}

shared_ptr<ResidentialBuilding> ResidentialBuildingFactory::createBuilding(string variant)
{
	if (buildingId >= 100)
	{
		cout << "You have reached the maximum number of residential buildings" << endl;
		return nullptr;
	}
	
	int bId = id * 100 + buildingId;

	if(variant == "House")
	{
		shared_ptr<House> house = make_shared<House>(this->id);
		buildingId++;
		return house;
	}
	else if(variant == "Apartment")
	{
		shared_ptr<ResidentialBuilding> apartment = make_shared<Apartment>(this->id);
		buildingId++;
		return apartment;
	}
	else if(variant == "Estate")
	{
		shared_ptr<ResidentialBuilding> estate = make_shared<Estate>(this->id);
		buildingId++;
		return estate;
	}
	else if(variant == "TownHouse")
	{
		shared_ptr<ResidentialBuilding> townHouse = make_shared<TownHouse>(this->id);
		buildingId++;
		return townHouse;
	}
	else
	{
		cout << "Invalid residential building type" << endl;
		return nullptr;
	}
}
