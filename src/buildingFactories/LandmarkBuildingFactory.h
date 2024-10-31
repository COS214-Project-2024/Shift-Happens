#ifndef LANDMARKBUILDINGFACTORY_H
#define LANDMARKBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "../buildings/landmark/Park.h"
#include "../buildings/landmark/Monument.h"
#include "../buildings/landmark/CulturalCenter.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

/**
 * @brief Factory class for creating landmark buildings.
 * 
 * This class is responsible for creating different types of landmark buildings.
 * 
 * @version 1.0
 * @date 2023-10-01
 * 
 * @section author Author
 * Morne van Heerden (u21482153)
 */
class LandmarkBuildingFactory : public BuildingFactory
{
private:
    vector<shared_ptr<LandMark>> buildings; ///< List of created buildings

public:
    /**
     * @brief Constructor for LandmarkBuildingFactory.
     * @param id Factory ID.
     */
    LandmarkBuildingFactory(int id);

    /**
     * @brief Creates a landmark building.
     * @param variant The type of building to create.
     */
    void createBuilding(string variant) override;

    /**
     * @brief Returns the created building.
     * @return shared_ptr<LandMark> The created building.
     */
    shared_ptr<LandMark> getBuilding();

    /**
     * @brief Prints the created buildings.
     */
    void print() override;

    /**
     * @brief Destructor for LandmarkBuildingFactory.
     */
    ~LandmarkBuildingFactory();
};

#endif
