#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "UtilityBuilding.h"

/**
 * @class PowerPlant
 * @brief Represents a power plant utility building that produces electricity.
 * 
 * The PowerPlant class inherits from UtilityBuilding and provides functionality to 
 * manage electricity production along with other resource-related methods.
 */
class PowerPlant : public UtilityBuilding
{
private:
    int electricityProduction; ///< The amount of electricity produced by the power plant.

public:
    /**
     * @brief Constructs a PowerPlant object with the specified ID.
     * @param id The unique ID of the power plant.
     */
    PowerPlant(int id);

    /**
     * @brief Gets the electricity production of the power plant.
     * @return The amount of electricity produced as a double.
     */
    double getElectricityProduction();

    /**
     * @brief Sets the electricity production of the power plant.
     * @param electricityProduction The new electricity production value to set.
     */
    void setElectricityProduction(int electricityProduction);

    /**
     * @brief Prints the details of the power plant.
     */
    virtual void print() override;

    // New functions

    /**
     * @brief Gets the average satisfaction score for the power plant.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the power plant.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the power plant.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the power plant.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the power plant.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the power plant.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the power plant.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the power plant.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the power plant.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the power plant.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // POWERPLANT_H
