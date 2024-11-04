#ifndef RAINCATCHER_H
#define RAINCATCHER_H

#include "../Upgrade.h"

/**
 * @class RainCatcher
 * @brief Represents a rain catcher upgrade for a building, focusing on water collection and management.
 */
class RainCatcher : public Upgrade
{
public:
    /**
     * @brief Constructs a RainCatcher object associated with a building.
     * @param building A shared pointer to the Building that this RainCatcher upgrade will enhance.
     */
    RainCatcher(shared_ptr<Building> building);

    /**
     * @brief Gets the water demand of the rain catcher.
     * @return The water demand in units.
     */
    int getWaterDemand() override;

    /**
     * @brief Prints the details of the rain catcher.
     */
    virtual void print() override;

    // New functions

    /**
     * @brief Retrieves the average satisfaction score contributed by the rain catcher.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply collected by the rain catcher.
     * @return The total water supply in units.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the rain catcher.
     * @return The total water usage in units.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply required by the rain catcher.
     * @return The total electricity supply in units.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the rain catcher.
     * @return The total electricity demand in units.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity available for the rain catcher.
     * @return The total sewage capacity in units.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the rain catcher.
     * @return The total waste capacity in units.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste produced by the rain catcher.
     * @return The total waste production in units.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production from the rain catcher.
     * @return The total sewage production in units.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the rain catcher.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif
