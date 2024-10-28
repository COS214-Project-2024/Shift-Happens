#ifndef INFRASTRUCTUREFACTORY_H
#define INFRASTRUCTUREFACTORY_H

#include "BuildingFactory.h"

class InfrastructureFactory : public BuildingFactory
{
private:

public:
	InfrastructureFactory(int id);
	~InfrastructureFactory();
};

#endif
