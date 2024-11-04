#ifndef SOLAR_H
#define SOLAR_H

#include "../Upgrade.h"

/**
 * @class Solar
 * @brief Represents a solar upgrade for a building, focusing on renewable energy production and management.
 */
class Solar : public Upgrade
{
public:
    /**
     * @brief Constructs a Solar object associated with a building.
     * @param building A shared pointer to the Building that this Solar upgrade will enhance.
     */
    Solar(shared_ptr<Building> building);

    /**
     * @brief Gets the electricity demand of the solar system.
     * @return The electricity demand in units.
     */
    int getElectricityDemand() override;

    /**
     * @brief Prints the details of the solar system.
     */
    virtual void print() override;

    // New functions

    /**
     * @brief Retrieves the average satisfaction score contributed by the solar system.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply associated with the solar system.
     * @return The total water supply in units.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the solar system.
     * @return The total water usage in units.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply provided by the solar system.
     * @return The total electricity supply in units.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the solar system.
     * @return The total electricity demand in units.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity available for the solar system.
     * @return The total sewage capacity in units.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the solar system.
     * @return The total waste capacity in units.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste produced by the solar system.
     * @return The total waste production in units.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production from the solar system.
     * @return The total sewage production in units.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the solar system.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif
