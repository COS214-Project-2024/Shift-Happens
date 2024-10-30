#include "Map.h"
#include <iostream>

/**
 * @brief Private constructor for Map.
 * @param id Map ID.
 */
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

/**
 * @brief Adds a component to the map.
 * @param component The component to add.
 * @return True if the component was added, false otherwise.
 */
bool Map::add(MapComponent* component) {
    throw "Map::add(MapComponent* component) not implemented";
}

/**
 * @brief Removes a component from the map.
 * @param component The component to remove.
 * @return True if the component was removed, false otherwise.
 */
bool Map::remove(MapComponent* component) {
    throw "Map::remove(MapComponent* component) not implemented";
}

/**
 * @brief Gets a component by ID.
 * @param id The component ID.
 */
void Map::getComponent(int id) {
    // Implementation here
}

/**
 * @brief Renders the map.
 */
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

/**
 * @brief Builds a building on the map.
 * @param variant The type of building to create.
 * @param type The category of the building.
 * @param xPos The x position on the map.
 * @param yPos The y position on the map.
 */
void Map::build(string variant, string type, int xPos, int yPos) {
    // Check if there is a building in the position
    if (tiles[xPos][yPos] != nullptr) {
        throw "There is already a building in this position";
    }
    if (type == "Commercial") {
        commercialBuildingFactory->createBuilding(variant);
        shared_ptr<CommercialBuilding> building = commercialBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
    } else if (type == "Residential") {
        residentialBuildingFactory->createBuilding(variant);
        shared_ptr<ResidentialBuilding> building = residentialBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
    } else if (type == "Industrial") {
        industrialBuildingFactory->createBuilding(variant);
        shared_ptr<IndustrialBuilding> building = industrialBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
    } else if (type == "Utility") {
        utilityBuildingFactory->createBuilding(variant);
        shared_ptr<UtilityBuilding> building = utilityBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
    } else if (type == "Landmark") {
        landmarkBuildingFactory->createBuilding(variant);
        shared_ptr<LandMark> building = landmarkBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
    } else if (type == "Infrastructure") {
        infrastructureFactory->createBuilding(variant);
        shared_ptr<Infrastructure> building = infrastructureFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
    } else if (type == "Transport") {
        transportBuildingFactory->createBuilding(variant);
        shared_ptr<TransportBuilding> building = transportBuildingFactory->getBuilding();
        building->setXPos(xPos);
        building->setYPos(yPos);
        tiles[xPos][yPos] = building;
    }
}

/**
 * @brief Destroys a building on the map by ID.
 * @param id The ID of the building to destroy.
 */
void Map::destroy(int id) {
    // Check if the building exists
    bool found = false;
    for (size_t i = 0; i < 25; i++) {
        for (size_t j = 0; j < 25; j++) {
            if (tiles[i][j] != nullptr && tiles[i][j]->getId() == id) {
                tiles[i][j] = nullptr;
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        throw "Map::destroy(id) -> Building not found";
    }
}

/**
 * @brief Prints the map grid.
 */
void Map::print() {
    // Print the map grid
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

/**
 * @brief Gets the singleton instance of the Map.
 * @return The singleton instance of the Map.
 */
Map& Map::getInstance() {
    static Map instance(0);
    return instance;
}
