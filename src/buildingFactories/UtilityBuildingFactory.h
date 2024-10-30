#ifndef UTILITYBUILDINGFACTORY_H
#define UTILITYBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "../buildings/utility/PowerPlant.h"
#include "../buildings/utility/WaterSupply.h"
#include "../buildings/utility/LandFill.h"
#include "../buildings/utility/SewagePlant.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

/**
 * @brief Factory class for creating utility buildings.
 * 
 * This class is responsible for creating different types of utility buildings.
 * 
 * @version 1.0
 * @date 2023-10-01
 * 
 * @section author Author
 * Morne van Heerden (u21482153)
 */
class UtilityBuildingFactory : public BuildingFactory
{
private:
    vector<shared_ptr<UtilityBuilding>> buildings; ///< List of created buildings

public:
    /**
     * @brief Constructor for UtilityBuildingFactory.
     * @param id Factory ID.
     */
    UtilityBuildingFactory(int id);

    /**
     * @brief Creates a utility building.
     * @param variant The type of building to create.
     */
    void createBuilding( string variant) override;
    std::shared_ptr<Building> createBuilding2(const string& variant);

    /**
     * @brief Prints the created buildings.
     */
    void print() override;

    /**
     * @brief Destructor for UtilityBuildingFactory.
     */
    ~UtilityBuildingFactory();
};

#endif
