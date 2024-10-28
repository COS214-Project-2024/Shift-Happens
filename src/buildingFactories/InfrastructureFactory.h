#ifndef INFRASTRUCTUREFACTORY_H
#define INFRASTRUCTUREFACTORY_H

#include "BuildingFactory.h"

#include "../buildings/infrastructure/Road.h"
#include "../buildings/infrastructure/Railway.h"

#include <vector>
#include <memory>
#include <string>

using namespace std;
class InfrastructureFactory : public BuildingFactory
{
private:
	vector<shared_ptr<Infrastructure>> buildings;
public:
	InfrastructureFactory(int id);
	void createBuilding(string variant);
	~InfrastructureFactory();

	void print();
};

#endif
