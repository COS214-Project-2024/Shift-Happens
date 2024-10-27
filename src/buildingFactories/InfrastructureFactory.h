#ifndef INFRASTRUCTUREFACTORY_H
#define INFRASTRUCTUREFACTORY_H
#include "BuildingFactory.h"
#include "Infrastructure.h"
	class InfrastructureFactory : public BuildingFactory {


	public:
		Infrastructure* build(string variant);
	};

#endif
