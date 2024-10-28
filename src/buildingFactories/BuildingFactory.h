#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include <iostream>
#include <memory>
#include <string>
#include "../buildings/Building.h"
class BuildingFactory
{
protected:
	int id;
public:
	BuildingFactory(int id);

	~BuildingFactory();

};

#endif
