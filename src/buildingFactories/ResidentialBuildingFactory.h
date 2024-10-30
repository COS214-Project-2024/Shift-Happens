#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "../buildings/residential/House.h"
#include "../buildings/residential/TownHouse.h"
#include "../buildings/residential/Estate.h"
#include "../buildings/residential/Apartment.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

/**
 * @brief Factory class for creating residential buildings.
 * 
 * This class is responsible for creating different types of residential buildings.
 * 
 * @version 1.0
 * @date 2023-10-01
 * 
 * @section author Author
 * Morne van Heerden (u21482153)
 */
class ResidentialBuildingFactory : public BuildingFactory
{
private:
    vector<shared_ptr<ResidentialBuilding>> buildings; ///< List of created buildings

public:
    /**
     * @brief Constructor for ResidentialBuildingFactory.
     * @param id Factory ID.
     */
    ResidentialBuildingFactory(int id);

    /**
     * @brief Creates a residential building.
     * @param variant The type of building to create.
     */
    void createBuilding(string variant) override;
    std::shared_ptr<Building> createBuilding2(const string& variant);

    /**
     * @brief Prints the created buildings.
     */
    void print() override;

    /**
     * @brief Destructor for ResidentialBuildingFactory.
     */
    ~ResidentialBuildingFactory();
};

#endif