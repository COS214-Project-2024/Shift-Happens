#ifndef INDUSTRIALBUILDINGFACTORY_H
#define INDUSTRIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "../buildings/industrial/Factory.h"
#include "../buildings/industrial/Warehouse.h"
#include "../buildings/industrial/Manufacturer.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

/**
 * @brief Factory class for creating industrial buildings.
 * 
 * This class is responsible for creating different types of industrial buildings.
 * 
 * @version 1.0
 * @date 2023-10-01
 * 
 * @section author Author
 * Morne van Heerden (u21482153)
 */
class IndustrialBuildingFactory : public BuildingFactory
{
private:
    vector<shared_ptr<Building>> buildings; ///< List of created buildings

public:
    /**
     * @brief Constructor for IndustrialBuildingFactory.
     * @param id Factory ID.
     */
    IndustrialBuildingFactory(int id);

    /**
     * @brief Creates an industrial building.
     * @param variant The type of building to create.
     */
    void createBuilding(string variant) override;

    /**
     * @brief Prints the created buildings.
     */
    void print() override;

    /**
     * @brief Destructor for IndustrialBuildingFactory.
     */
    ~IndustrialBuildingFactory();
};

#endif
