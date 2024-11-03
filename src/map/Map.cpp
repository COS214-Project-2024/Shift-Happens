#include "Map.h"
#include <iostream>
#include <cmath>
#include <queue>


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
 * @brief Gets a component by ID.
 * @param id The component ID.
 */
shared_ptr<MapComponent> Map::getComponent(int id) {
    
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component->getId() == id) {
                return component;
            }
        }
    }
    return nullptr;
}

//Monica - test
/**
 * @brief Gets the coordinates of a component by ID.
 * @param id The component ID.
 * @return A pair of integers representing the (x, y) coordinates of the component.
 */
pair<int, int> Map::getComponentCoord(int id) {
    for (int x = 0; x < tiles.size(); ++x) {
        for (int y = 0; y < tiles[x].size(); ++y) {
            if (tiles[x][y] && tiles[x][y]->getId() == id) {
                return {x, y};
            }
        }
    }
    // If the component is not found, return an invalid coordinate (-1, -1)
    return {-1, -1};
}

    /**
     * @brief Gets a list of all buildings with the given ID.
     * @param id The component ID.
     * @return A vector of shared pointers to the buildings with the specified ID.
     */
    vector<shared_ptr<MapComponent>> Map::getListOfBuildings(int id) {
        vector<shared_ptr<MapComponent>> buildings;

        for (const auto& row : tiles) {
            for (const auto& component : row) {
                if (component && component->getId() == id) {
                    buildings.push_back(component);
                }
            }
        }
        
        return buildings;
    }

void Map::displayBuildingList(const vector<std::shared_ptr<MapComponent>>& buildings) {
    if (buildings.empty()) {
        cout << "No buildings found with the specified ID.\n" << endl;;
        return;
    }

    cout << "Buildings Found:\n";
    cout << "-----------------\n";
    cout << "ID\tType\tVariant\n";
    cout << "-----------------\n";

    for (const auto& building : buildings) {
        cout << building->getId() << "\t"
            << building->getType() << "\t"
            << building->getVariant() << "\n";
    }
    cout << "-----------------\n";
}


/**
 * @brief Renders the map.
 */
void Map::render() {
    // Generate a 25x25 map grid
    for (size_t i = 0; i < 25; i++) {
        for (size_t j = 0; j < 25; j++) {
            if (tiles[i][j] == nullptr) {
                cout << "|  ";
            } else {
                cout << "|X ";
            }
        }
        cout << "|" << endl;
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

void Map::upgrade(int id, const string upgradeType) {
    for (auto& row : tiles) {
        for (auto& component : row) {
            if (component->getId() == id) {
                shared_ptr<Building> building = dynamic_pointer_cast<Building>(component);
                if (building) {
                    if (upgradeType == "Solar") {
                        component = make_shared<Solar>(building);
                    } else if (upgradeType == "Garden") {
                        component = make_shared<Garden>(building);
                    } else if (upgradeType == "RainCatcher") {
                        component = make_shared<RainCatcher>(building);
                    } else if (upgradeType == "Recycling") {
                        component = make_shared<Recycling>(building);
                    } else {
                        cout << "Invalid upgrade type" << endl;
                    }
                    return;
                }
            }
        }
    }
    cout << "Building with ID " << id << " not found" << endl;
}

// New functions
double Map::getAverageSatisfactionScore() {
    double totalScore = 0;
    int count = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component) {
                totalScore += component->getAverageSatisfactionScore();
                count++;
            }
        }
    }
    return count > 0 ? totalScore / count : 0;
}

int Map::getTotalWaterSupply() {
    int total = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component) {
                total += component->getTotalWaterSupply();
            }
        }
    }
    return total;
}

int Map::getTotalWaterUsage() {
    int total = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component) {
                total += component->getTotalWaterUsage();
            }
        }
    }
    return total;
}

int Map::getTotalElectricitySupply() {
    int total = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component) {
                total += component->getTotalElectricitySupply();
            }
        }
    }
    return total;
}

int Map::getTotalElectricityDemand() {
    int total = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component) {
                total += component->getTotalElectricityDemand();
            }
        }
    }
    return total;
}

int Map::getTotalSewageCapacity() {
    int total = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component) {
                total += component->getTotalSewageCapacity();
            }
        }
    }
    return total;
}

int Map::getTotalWasteCapacity() {
    int total = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component) {
                total += component->getTotalWasteCapacity();
            }
        }
    }
    return total;
}

int Map::getTotalWasteProduction() {
    int total = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component) {
                total += component->getTotalWasteProduction();
            }
        }
    }
    return total;
}

int Map::getTotalSewageProduction() {
    int total = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component) {
                total += component->getTotalSewageProduction();
            }
        }
    }
    return total;
}

int Map::getTotalNumberOfJobs() {
    int total = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component) {
                total += component->getTotalNumberOfJobs();
            }
        }
    }
    return total;
}


//counting number of buildings
int Map::numBuildings(string var) {
    int count = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component) {
                if (component->getVariant() == var) {
                    count++;
                }
            }
        }
    }
    return count;
}

string Map::getType() {
    return "Map";
}

string Map::getVariant() {
    return "Map";
}

string Map::getSymbol() {
    return "-";
}

int Map::getTotalPopulationCapacity() {
    int total = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component != nullptr) {
                if (component->getType() == "Residential") {
                    shared_ptr<ResidentialBuilding> building = dynamic_pointer_cast<ResidentialBuilding>(component);
                    total += building->getCapacity();
                }
            }
        }
    }
    return total;
}

int Map::getIncome() {
    int total = 0;
    for (const auto& row : tiles) {
        for (const auto& component : row) {
            if (component != nullptr) {
                if (component->getType() == "Commercial") {
                    shared_ptr<CommercialBuilding> building = dynamic_pointer_cast<CommercialBuilding>(component);
                    total += building->getIncomePerHour();
                }
                if (component->getType() == "Residential") {
                    shared_ptr<ResidentialBuilding> building = dynamic_pointer_cast<ResidentialBuilding>(component);
                    total += building->getIncomePerHour();
                }
                
            }
        }
    }
    return total;
}


//Monica - Trasportation functions:
/*
Manhattan distance is particularly suitable for grid-like structures, 
while the Euclidean distance provides a more flexible option if 
diagonal movement is allowed. 
*/
bool Map::isTileTraversable(int x, int y) const {
    // Check if the coordinates are within bounds
    if (x < 0 || x >= 25 || y < 0 || y >= 25) {
        return false; // Out of bounds
    }
    
    // Check if the tile is empty (no building)
    return tiles[x][y] == nullptr; // Assuming nullptr means the tile is free
}

bool Map::isValidPosition(int x, int y) const {
    return (x >= 0 && x < tiles.size() && y >= 0 && y < tiles[x].size());
}


double Map::calculateManhattanDistance(int startX, int startY, int endX, int endY) const {
    return std::abs(startX - endX) + std::abs(startY - endY);
}

double Map::roadDistanceTo(int startX, int startY, int endX, int endY) const {
    double totalDistance = 0.0;

    // Directions for movement (right, down, left, up)
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int x = startX;
    int y = startY;

    // Use a queue to perform a breadth-first search (BFS)
    queue<pair<int, int>> q;
    q.push({x, y});

    // Distance map to store distance to each tile
    vector<vector<int>> distance(25, vector<int>(25, -1));
    distance[x][y] = 0;

    while (!q.empty()) {
        auto [curX, curY] = q.front();
        q.pop();

        // If reached the destination
        if (curX == endX && curY == endY) {
            totalDistance = distance[curX][curY];
            break;
        }

        // Explore neighbors
        for (int i = 0; i < 4; ++i) {
            int newX = curX + dx[i];
            int newY = curY + dy[i];

            // Check boundaries and if it is traversable with a road
            //if (isValidPosition(newX, newY) && (tiles[newX][newY] == "-" || tiles[newX][newY] == "|")) {
            if (isValidPosition(newX, newY) &&
            tiles[newX][newY] != nullptr && 
            (tiles[newX][newY]->getSymbol() == "-" || tiles[newX][newY]->getSymbol() == "|")) {
                // If the tile hasn't been visited yet
                if (distance[newX][newY] == -1) {
                    distance[newX][newY] = distance[curX][curY] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }

    // If the destination is not reachable via roads, return -1 or a similar indicator
    if (totalDistance == 0.0 && (startX != endX || startY != endY)) {
        std::cout << "No valid road path found between points." << std::endl;
        return -1.0;
    }

    return totalDistance; // Return the total road distance if reachable
}


//just the displacement for air travel
double Map::airDistanceTo(int startX, int startY, int endX, int endY) const {
    double deltaX = endX - startX;
    double deltaY = endY - startY;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

double Map::trainDistanceTo(int startX, int startY, int endX, int endY) const {
    // Check if start and end positions are valid
    if (!isValidPosition(startX, startY) || !isValidPosition(endX, endY)) {
        throw invalid_argument("Invalid start or end position.");
    }

    // Calculate Manhattan distance
    double distance = calculateManhattanDistance(startX, startY, endX, endY);
    
    return distance;
}


