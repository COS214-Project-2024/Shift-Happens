#ifndef COMMERCIALBUILDINGFACTORY_H
#define COMMERCIALBUILDINGFACTORY_H


#include "BuildingFactory.h"
#include "../buildings/commercial/Store.h"
#include "../buildings/commercial/Office.h"
#include "../buildings/commercial/Mall.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class CommercialBuildingFactory : public BuildingFactory
{
private:
	vector<shared_ptr<CommercialBuilding>> buildings;
public:
	CommercialBuildingFactory(int id);
	void createBuilding(string variant);
	~CommercialBuildingFactory();
};


#endif
