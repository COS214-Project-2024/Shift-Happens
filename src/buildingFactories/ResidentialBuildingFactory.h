#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "../buildings/residential/House.h"
#include "../buildings/residential/TownHouse.h"
#include "../buildings/residential/Estate.h"
#include "../buildings/residential/Apartment.h"

#include <memory>
#include <string>

class ResidentialBuildingFactory : public BuildingFactory
{
private:
public:
	ResidentialBuildingFactory(int id);
	~ResidentialBuildingFactory();
};
#endif
