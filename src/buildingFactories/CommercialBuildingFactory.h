#ifndef COMMERCIALBUILDINGFACTORY_H
#define COMMERCIALBUILDINGFACTORY_H


#include "BuildingFactory.h"


class CommercialBuildingFactory : public BuildingFactory
{
private:
public:
	CommercialBuildingFactory(int id);

	~CommercialBuildingFactory();
};


#endif
