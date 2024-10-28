#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

#include "BuildingFactory.h"

class ResidentialBuildingFactory : public BuildingFactory
{
private:
	int id;
public:
	ResidentialBuildingFactory(int id);
	~ResidentialBuildingFactory();
};
#endif
