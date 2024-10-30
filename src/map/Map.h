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

#include "../buildings/upgrades/Garden.h"
#include "../buildings/upgrades/RainCatcher.h"
#include "../buildings/upgrades/Recycling.h"
#include "../buildings/upgrades/Solar.h"

using namespace std;

/**
 * @brief Singleton class representing the map.
 * 
 * This class provides methods to manage and render the map.
 * 
 * @version 1.0
 * @date 2023-10-01
 * 
 * @section author Author
 * Morne van Heerden (u21482153)
 */
class Map : public MapComponent
{
private:
    vector<vector<shared_ptr<MapComponent>>> tiles; ///< Vector to hold the map components

    // Factories
    shared_ptr<CommercialBuildingFactory> commercialBuildingFactory;
    shared_ptr<ResidentialBuildingFactory> residentialBuildingFactory;
    shared_ptr<IndustrialBuildingFactory> industrialBuildingFactory;
    shared_ptr<UtilityBuildingFactory> utilityBuildingFactory;
    shared_ptr<LandmarkBuildingFactory> landmarkBuildingFactory;
    shared_ptr<InfrastructureFactory> infrastructureFactory;
    shared_ptr<TransportBuildingFactory> transportBuildingFactory;

    /**
     * @brief Private constructor to prevent instantiation.
     * @param id Map ID.
     */
    Map(int id);

public:
    // Deleted copy constructor and assignment operator to prevent copying
    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;

    /**
     * @brief Builds a building on the map.
     * @param variant The type of building to create.
     * @param type The category of the building.
     * @param xPos The x position on the map.
     * @param yPos The y position on the map.
     */
    void build(string variant, string type, int xPos, int yPos);

    /**
     * @brief Destroys a building on the map by ID.
     * @param id The ID of the building to destroy.
     */
    void destroy(int id);

    /**
     * @brief Adds a component to the map.
     * @param component The component to add.
     * @return True if the component was added, false otherwise.
     */
    bool add(MapComponent *component) override;

    /**
     * @brief Removes a component from the map.
     * @param component The component to remove.
     * @return True if the component was removed, false otherwise.
     */
    bool remove(MapComponent *component) override;

    /**
     * @brief Gets a component by ID.
     * @param id The component ID.
     */
    void getComponent(int id) override;

    /**
     * @brief Renders the map.
     */
    void render() override;

    /**
     * @brief Prints the map grid.
     */
    void print();

    /**
     * @brief Gets the singleton instance of the Map.
     * @return The singleton instance of the Map.
     */
    static Map& getInstance();

    void upgrade(int id, const string upgradeType); // Add this line
};

#endif
