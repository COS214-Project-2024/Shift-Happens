#ifndef COMMERCIALBUILDINGFACTORY_H
#define COMMERCIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "../buildings/commercial/Store.h"
#include "../buildings/commercial/Office.h"
#include "../buildings/commercial/Mall.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

/**
 * @brief Factory class for creating commercial buildings.
 * 
 * This class is responsible for creating different types of commercial buildings.
 * 
 * @version 1.0
 * @date 2023-10-01
 * 
 * @section author Author
 * Morne van Heerden (u21482153)
 */
class CommercialBuildingFactory : public BuildingFactory
{
private:
    vector<shared_ptr<CommercialBuilding>> buildings; ///< List of created buildings

public:
    /**
     * @brief Constructor for CommercialBuildingFactory.
     * @param id Factory ID.
     */
    CommercialBuildingFactory(int id);

    /**
     * @brief Creates a commercial building.
     * @param variant The type of building to create.
     */
    void createBuilding(string variant) override;

    /**
     * @brief Prints the created buildings.
     */
    void print() override;

    /**
     * @brief Destructor for CommercialBuildingFactory.
     */
    ~CommercialBuildingFactory();
};

#endif
