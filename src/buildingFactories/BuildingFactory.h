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
	int buildingId;
public:
	BuildingFactory(int id);
	virtual void createBuilding(string variant) = 0;

	virtual void print() = 0;
	~BuildingFactory();

};

#endif
