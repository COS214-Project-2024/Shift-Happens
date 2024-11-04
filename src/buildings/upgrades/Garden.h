#ifndef GARDEN_H
#define GARDEN_H

#include "../Upgrade.h"

/**
 * @class Garden
 * @brief Represents a garden upgrade for a building, enhancing amenities and utilities.
 */
class Garden : public Upgrade
{
public:
    /**
     * @brief Constructs a Garden object associated with a building.
     * @param building A shared pointer to the Building that this Garden upgrade will enhance.
     */
    Garden(shared_ptr<Building> building);

    /**
     * @brief Gets the amount of sewage produced by the garden.
     * @return The sewage production in units.
     */
    int getSewageProduced() override;

    /**
     * @brief Prints the details of the garden.
     */
    virtual void print() override;

    // New functions

    /**
     * @brief Retrieves the average satisfaction score contributed by the garden.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply associated with the garden.
     * @return The total water supply in units.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the garden.
     * @return The total water usage in units.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply provided to the garden.
     * @return The total electricity supply in units.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the garden.
     * @return The total electricity demand in units.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity available for the garden.
     * @return The total sewage capacity in units.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the garden.
     * @return The total waste capacity in units.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste produced by the garden.
     * @return The total waste production in units.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production from the garden.
     * @return The total sewage production in units.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the garden.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif
