#ifndef INFRASTRUCTUREFACTORY_H
#define INFRASTRUCTUREFACTORY_H

#include "BuildingFactory.h"
#include "../buildings/infrastructure/Road.h"
#include "../buildings/infrastructure/Railway.h"
#include <vector>
#include <memory>
#include <string>

using namespace std;

/**
 * @brief Factory class for creating infrastructure buildings.
 * 
 * This class is responsible for creating different types of infrastructure buildings.
 * 
 * @version 1.0
 * @date 2023-10-01
 * 
 * @section author Author
 * Morne van Heerden (u21482153)
 */
class InfrastructureFactory : public BuildingFactory
{
private:
    vector<shared_ptr<Infrastructure>> buildings; ///< List of created buildings

public:
    /**
     * @brief Constructor for InfrastructureFactory.
     * @param id Factory ID.
     */
    InfrastructureFactory(int id);

    /**
     * @brief Creates an infrastructure building.
     * @param variant The type of building to create.
     */
    void createBuilding(string variant) override;

    /**
     * @brief Prints the created buildings.
     */
    void print() override;

    /**
     * @brief Destructor for InfrastructureFactory.
     */
    ~InfrastructureFactory();
};

#endif
