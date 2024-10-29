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
    // Find an empty spot in the grid and add the component
    for (size_t i = 0; i < 25; i++) {
        for (size_t j = 0; j < 25; j++) {
            if (tiles[i][j] == nullptr) {
                tiles[i][j] = shared_ptr<MapComponent>(component);
                return true;
            }
        }
    }
    return false; // No empty spot found
}

bool Map::remove(MapComponent* component) {
    // Find the component in the grid and remove it
    for (size_t i = 0; i < 25; i++) {
        for (size_t j = 0; j < 25; j++) {
            if (tiles[i][j].get() == component) {
                tiles[i][j] = nullptr;
                return true;
            }
        }
    }
    return false; // Component not found
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
	}
	else if(type == "Residential"){
		residentialBuildingFactory->createBuilding(variant);
	}
	else if(type == "Industrial"){
		industrialBuildingFactory->createBuilding(variant);
	}
	else if(type == "Utility"){
		utilityBuildingFactory->createBuilding(variant);
	}
	else if(type == "Landmark"){
		landmarkBuildingFactory->createBuilding(variant);
	}
	else if(type == "Infrastructure"){
		infrastructureFactory->createBuilding(variant);
	}
	else if(type == "Transport"){
		transportBuildingFactory->createBuilding(variant);
	}
}