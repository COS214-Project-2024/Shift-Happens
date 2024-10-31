#ifndef TRANSPORTBUILDINGFACTORY_H
#define TRANSPORTBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "../buildings/transport/Airport.h"
#include "../buildings/transport/BusStation.h"
#include "../buildings/transport/TrainStation.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

/**
 * @brief Factory class for creating transport buildings.
 * 
 * This class is responsible for creating different types of transport buildings.
 * 
 * @version 1.0
 * @date 2023-10-01
 * 
 * @section author Author
 * Morne van Heerden (u21482153)
 */
class TransportBuildingFactory : public BuildingFactory
{
private:
    vector<shared_ptr<TransportBuilding>> buildings; ///< List of created buildings

public:
    /**
     * @brief Constructor for TransportBuildingFactory.
     * @param id Factory ID.
     */
    TransportBuildingFactory(int id);

    /**
     * @brief Creates a transport building.
     * @param variant The type of building to create.
     */
    void createBuilding(string variant) override;

    /**
     * @brief Returns the created building.
     * @return shared_ptr<TransportBuilding> The created building.
     */
    shared_ptr<TransportBuilding> getBuilding();

    /**
     * @brief Prints the created buildings.
     */
    void print() override;

    /**
     * @brief Destructor for TransportBuildingFactory.
     */
    ~TransportBuildingFactory();
};

#endif // TRANSPORTBUILDINGFACTORY_H