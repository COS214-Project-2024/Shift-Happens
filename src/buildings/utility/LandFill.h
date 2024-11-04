#ifndef LANDFILL_H
#define LANDFILL_H

#include "UtilityBuilding.h"

/**
 * @class LandFill
 * @brief Represents a landfill utility building that manages waste removal.
 * 
 * The LandFill class inherits from the UtilityBuilding class and includes methods 
 * to manage waste removal and resources associated with the landfill.
 */
class LandFill : public UtilityBuilding {
private:
    int wasteRemovalRate; ///< The rate at which waste is removed from the landfill.

public:
    /**
     * @brief Constructs a LandFill object with the specified ID.
     * @param id The unique ID of the landfill.
     */
    LandFill(int id);

    /**
     * @brief Gets the waste removal rate of the landfill.
     * @return The waste removal rate.
     */
    int getWasteRemovalRate();

    /**
     * @brief Sets the waste removal rate of the landfill.
     * @param wasteRemovalRate The new waste removal rate to set.
     */
    void setWasteRemovalRate(int wasteRemovalRate);

    /**
     * @brief Prints the details of the landfill.
     */
    virtual void print() override;

    // New functions

    /**
     * @brief Gets the average satisfaction score for the landfill.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the landfill.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the landfill.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the landfill.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the landfill.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the landfill.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the landfill.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the landfill.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the landfill.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the landfill.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // LANDFILL_H
