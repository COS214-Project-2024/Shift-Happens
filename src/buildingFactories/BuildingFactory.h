#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H


#include <iostream>
#include <memory>
#include <string>
#include "../buildings/Building.h"

/**
 * @brief Abstract base class for building factories.
 * 
 * This class provides a common interface for all building factories.
 * 
 * @note This class is abstract and cannot be instantiated directly.
 * 
 * @version 1.0
 * @date 2023-10-01
 * 
 * @section author Author
 * Morne van Heerden (u21482153)
 */

class BuildingFactory
{
protected:
    int id; ///< Factory ID
    int buildingId; ///< ID for the next building to be created

public:
    /**
     * @brief Constructor for BuildingFactory.
     * @param id Factory ID.
     */
    BuildingFactory(int id);

    /**
     * @brief Pure virtual function to create a building.
     * @param variant The type of building to create.
     */
    virtual void createBuilding(std::string variant) = 0;

    /**
     * @brief Pure virtual function to print the buildings.
     */
    virtual void print() = 0;

    /**
     * @brief Destructor for BuildingFactory.
     */
    virtual ~BuildingFactory();
};

#endif
