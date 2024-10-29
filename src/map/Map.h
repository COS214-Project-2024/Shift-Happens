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

class Map : public MapComponent
{
	
private:
	//vector<vector<MapComponent*>> tiles;
	vector<vector<shared_ptr<MapComponent>>> tiles;

	//Factories
	shared_ptr<BuildingFactory> commercialBuildingFactory;
	shared_ptr<BuildingFactory> residentialBuildingFactory;
	shared_ptr<BuildingFactory> industrialBuildingFactory;
	shared_ptr<BuildingFactory> utilityBuildingFactory;
	shared_ptr<BuildingFactory> landmarkBuildingFactory;
	shared_ptr<BuildingFactory> infrastructureFactory;
	shared_ptr<BuildingFactory> transportBuildingFactory;
	

public:
	Map(int id);

	std::vector<std::shared_ptr<MapComponent>> components;
	
	void build(string variant, string type, int xPos, int yPos);

	bool add(MapComponent *component);

	bool remove(MapComponent *component);

	void getComponent(int id);

	void render();
};

#endif
