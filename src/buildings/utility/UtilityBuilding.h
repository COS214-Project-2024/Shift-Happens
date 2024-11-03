#ifndef UTILITYBUILDING_H
#define UTILITYBUILDING_H

#include "../Building.h"
#include <string>

/**
 * @class UtilityBuilding
 * @brief Represents a general utility building in the system.
 * 
 * The UtilityBuilding class inherits from Building and includes specific attributes 
 * and methods relevant to buildings that provide essential utilities.
 */
class UtilityBuilding : public Building {
private:
    int runningCostPerHour; ///< The cost incurred to run the building per hour.

public:
    /**
     * @brief Constructs a UtilityBuilding object with the specified attributes.
     * @param id The unique identifier of the utility building.
     * @param variant A string representing the type or variant of the utility building.
     * @param constructionPrice The cost to construct the building.
     * @param wasteProduced The amount of waste the building produces.
     * @param sewageProduced The amount of sewage the building produces.
     * @param electricityDemand The electricity demand of the building.
     * @param waterDemand The water demand of the building.
     */
    UtilityBuilding(int id, std::string variant, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);

    /**
     * @brief Gets the running cost per hour of the utility building.
     * @return The running cost per hour.
     */
    int getRunningCostPerHour();

    /**
     * @brief Sets the running cost per hour for the utility building.
     * @param runningCostPerHour The new running cost per hour to be set.
     */
    void setRunningCostPerHour(int runningCostPerHour);

    /**
     * @brief Prints the details of the utility building.
     */
    virtual void print();
};

#endif // UTILITYBUILDING_H
