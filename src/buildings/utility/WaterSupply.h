#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "UtilityBuilding.h"

/**
 * @class WaterSupply
 * @brief Represents a water supply building that manages water distribution.
 * 
 * The WaterSupply class inherits from UtilityBuilding and includes attributes and 
 * functions specific to water supply management in the system.
 */
class WaterSupply : public UtilityBuilding {
private:
    int waterSupply; ///< The total amount of water supplied by the building.

public:
    /**
     * @brief Constructs a WaterSupply object with the specified ID.
     * @param id The unique identifier of the water supply building.
     */
    WaterSupply(int id);

    /**
     * @brief Gets the current water supply amount.
     * @return The current water supply.
     */
    double getWaterSupply();

    /**
     * @brief Sets the amount of water the building supplies.
     * @param waterSupply The new water supply amount to be set.
     */
    void setWaterSupply(int waterSupply);

    /**
     * @brief Prints the details of the water supply building.
     */
    virtual void print() override;

    // Overridden functions
    double getAverageSatisfactionScore() override;
    int getTotalWaterSupply() override;
    int getTotalWaterUsage() override;
    int getTotalElectricitySupply() override;
    int getTotalElectricityDemand() override;
    int getTotalSewageCapacity() override;
    int getTotalWasteCapacity() override;
    int getTotalWasteProduction() override;
    int getTotalSewageProduction() override;
    int getTotalNumberOfJobs() override;
};

#endif // WATERSUPPLY_H
