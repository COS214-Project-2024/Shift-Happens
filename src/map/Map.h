#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include "MapComponent.h"

#include "../buildingFactories/CommercialBuildingFactory.h"
#include "../buildingFactories/ResidentialBuildingFactory.h"
#include "../buildingFactories/IndustrialBuildingFactory.h"
#include "../buildingFactories/UtilityBuildingFactory.h"
#include "../buildingFactories/LandmarkBuildingFactory.h"
#include "../buildingFactories/InfrastructureFactory.h"
#include "../buildingFactories/TransportBuildingFactory.h"


using namespace std;

class Map : public MapComponent{
	
private:
	//vector<vector<MapComponent*>> tiles;
	vector<vector<shared_ptr<MapComponent>>> tiles;

	//Factories
	shared_ptr<CommercialBuildingFactory> commercialBuildingFactory;
	shared_ptr<ResidentialBuildingFactory> residentialBuildingFactory;
	shared_ptr<IndustrialBuildingFactory> industrialBuildingFactory;
	shared_ptr<UtilityBuildingFactory> utilityBuildingFactory;
	shared_ptr<LandmarkBuildingFactory> landmarkBuildingFactory;
	shared_ptr<InfrastructureFactory> infrastructureFactory;
	shared_ptr<TransportBuildingFactory> transportBuildingFactory;

public:
	Map(int id);

	vector<shared_ptr<MapComponent>> components;
	
	void build(string variant, string type, int xPos, int yPos);

	bool add(MapComponent *component);

	bool remove(MapComponent *component);

	void getComponent(int id);

	void render();
};

#endif
