#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "../buildings/residential/House.h"
#include "../buildings/residential/TownHouse.h"
#include "../buildings/residential/Estate.h"
#include "../buildings/residential/Apartment.h"

#include <memory>
#include <vector>
#include <string>

using namespace std;
class ResidentialBuildingFactory : public BuildingFactory
{
private:
	vector<shared_ptr<ResidentialBuilding>> buildings;
public:
	ResidentialBuildingFactory(int id);
	void createBuilding(string variant);
	~ResidentialBuildingFactory();

	void print();
};
#endif
