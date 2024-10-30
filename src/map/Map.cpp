#include "Map.h"
#include <iostream>

Map::Map(int id) : MapComponent(id) {
    // Initialize a 25x25 grid with nullptr
    tiles = vector<vector<shared_ptr<MapComponent>>>(25, vector<shared_ptr<MapComponent>>(25, nullptr));

	// Initialize factories
	commercialBuildingFactory = make_shared<CommercialBuildingFactory>(1);
	residentialBuildingFactory = make_shared<ResidentialBuildingFactory>(2);
	industrialBuildingFactory = make_shared<IndustrialBuildingFactory>(3);
	utilityBuildingFactory = make_shared<UtilityBuildingFactory>(4);
	landmarkBuildingFactory = make_shared<LandmarkBuildingFactory>(5);
	infrastructureFactory = make_shared<InfrastructureFactory>(6);
	transportBuildingFactory = make_shared<TransportBuildingFactory>(7);
}

bool Map::add(MapComponent* component) {
    throw "Map::add(MapComponent* component) not implemented";
}

bool Map::remove(MapComponent* component) {
    throw "Map::remove(MapComponent* component) not implemented";
}

void Map::getComponent(int id) {
   
}

void Map::render() {
    // Generate a 25x25 map grid
    for (size_t i = 0; i < 25; i++) {
        for (size_t j = 0; j < 25; j++) {
            if (tiles[i][j] == nullptr) {
                std::cout << "|  ";
            } else {
                std::cout << "|X ";
            }
        }
        std::cout << "|" << std::endl;
    }
}

void Map::build(string variant, string type, int xPos, int yPos){
	//check if there is a building in the position
	if(tiles[xPos][yPos] != nullptr){
		throw "There is already a building in this position";
	}
	if(type == "Commercial"){
		commercialBuildingFactory->createBuilding(variant);
        shared_ptr<CommercialBuilding> building = commercialBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
	}
	else if(type == "Residential"){
		residentialBuildingFactory->createBuilding(variant);
        shared_ptr<ResidentialBuilding> building = residentialBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
	}
	else if(type == "Industrial"){
		industrialBuildingFactory->createBuilding(variant);
        shared_ptr<IndustrialBuilding> building = industrialBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
	}
	else if(type == "Utility"){
		utilityBuildingFactory->createBuilding(variant);
        shared_ptr<UtilityBuilding> building = utilityBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
	}
	else if(type == "Landmark"){
		landmarkBuildingFactory->createBuilding(variant);
        shared_ptr<LandMark> building = landmarkBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
	}
	else if(type == "Infrastructure"){
		infrastructureFactory->createBuilding(variant);
        shared_ptr<Infrastructure> building = infrastructureFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
	}
	else if(type == "Transport"){
		transportBuildingFactory->createBuilding(variant);
        shared_ptr<TransportBuilding> building = transportBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
	}
}