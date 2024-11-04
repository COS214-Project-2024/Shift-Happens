#ifndef RECYCLING_H
#define RECYCLING_H

#include "../Upgrade.h"

/**
 * @class Recycling
 * @brief Represents a recycling upgrade for a building, focusing on waste management and sustainability.
 */
class Recycling : public Upgrade
{
public:
    /**
     * @brief Constructs a Recycling object associated with a building.
     * @param building A shared pointer to the Building that this Recycling upgrade will enhance.
     */
    Recycling(shared_ptr<Building> building);

    /**
     * @brief Gets the amount of waste produced by the recycling system.
     * @return The waste production in units.
     */
    int getWasteProduced() override;

    /**
     * @brief Prints the details of the recycling system.
     */
    virtual void print() override;

    // New functions

    /**
     * @brief Retrieves the average satisfaction score contributed by the recycling system.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply associated with the recycling system.
     * @return The total water supply in units.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the recycling system.
     * @return The total water usage in units.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply required by the recycling system.
     * @return The total electricity supply in units.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the recycling system.
     * @return The total electricity demand in units.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity available for the recycling system.
     * @return The total sewage capacity in units.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the recycling system.
     * @return The total waste capacity in units.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste produced by the recycling system.
     * @return The total waste production in units.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production from the recycling system.
     * @return The total sewage production in units.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the recycling system.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif
