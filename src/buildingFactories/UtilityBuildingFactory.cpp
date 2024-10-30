#include "UtilityBuildingFactory.h"

UtilityBuildingFactory::UtilityBuildingFactory(int id)
: BuildingFactory(id)
{
}

void UtilityBuildingFactory::createBuilding(string variant)
{
	if (buildingId >= 100) // 99 max buildings
	{
		cout << "You have reached the maximum number of Utility buildings" << endl;
		return;
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	if (variant == "PowerPlant")
	{
		buildings.push_back(make_shared<PowerPlant>(idForBuilding));
	}
	else if (variant == "WaterSupply")
	{
		buildings.push_back(make_shared<WaterSupply>(idForBuilding));
	}
	else if (variant == "LandFill")
	{
		buildings.push_back(make_shared<LandFill>(idForBuilding));
	}
	else if (variant == "SewagePlant")
	{
		buildings.push_back(make_shared<SewagePlant>(idForBuilding));
	}
	else
	{
		cout << "Invalid building type" << endl;
		buildingId--;
	}
}
//
std::shared_ptr<Building> UtilityBuildingFactory::createBuilding2(const string& variant)
{
	if (buildingId >= 100) // 99 max buildings
	{
		cout << "You have reached the maximum number of Utility buildings" << endl;
		return nullptr;
	}
	
	int idForBuilding = buildingId + 100 * id;
	buildingId++;
	std::shared_ptr<Building> newBuilding;
	cout <<"Create  building p1\n" ; //for debugging
	if (variant == "PowerPlant")
	{
		
		cout <<"Variant matched\n"; //debuggig
		newBuilding = std::make_shared<PowerPlant>(idForBuilding);
		buildings.push_back(make_shared<PowerPlant>(idForBuilding));
	
		cout << "just about to retrun asf" << endl;
		
		
		cout <<"IS it empty? b4 return\n";
		cout << newBuilding->getVariant() << endl;
		newBuilding->print(); 
		//Need a way to display ALL CREATED BUILDINGS without seg faults
		
		
	}
	else if (variant == "WaterSupply")
	{
		newBuilding = std::make_shared<WaterSupply>(idForBuilding);
		buildings.push_back(make_shared<WaterSupply>(idForBuilding));
		newBuilding->print(); 
		
	}
	else if (variant == "LandFill")
	{
		newBuilding = std::make_shared<WaterSupply>(idForBuilding);
		buildings.push_back(make_shared<LandFill>(idForBuilding));
		newBuilding->print();
	}
	else if (variant == "SewagePlant")
	{
		newBuilding = std::make_shared<WaterSupply>(idForBuilding);
		buildings.push_back(make_shared<SewagePlant>(idForBuilding));
		newBuilding->print();
	}
	else
	{
		cout << "Invalid building type" << endl;
		buildingId--;
		return nullptr;
	}
	cout<<"Just about to return" << endl; // debugging
	return newBuilding;
}



/// 
UtilityBuildingFactory::~UtilityBuildingFactory()
{
	
}

void UtilityBuildingFactory::print()
{
	cout << "Printing Utility Buildings" << endl;
	for (auto building : buildings)
	{
		building->print();
	}
}