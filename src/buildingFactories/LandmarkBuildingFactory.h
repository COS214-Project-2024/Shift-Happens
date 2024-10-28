#ifndef LANDMARKBUILDINGFACTORY_H
#define LANDMARKBUILDINGFACTORY_H

#include "BuildingFactory.h"

#include "../buildings/landmark/Park.h"
#include "../buildings/landmark/Monument.h"
#include "../buildings/landmark/CulturalCenter.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;
class LandmarkBuildingFactory : public BuildingFactory
{
private:
	vector<shared_ptr<LandMark>> buildings;

public:
	LandmarkBuildingFactory(int id);
	void createBuilding(string variant);
	~LandmarkBuildingFactory();
};

#endif
