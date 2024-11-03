#ifndef SEWAGEPLANT_H
#define SEWAGEPLANT_H

#include "UtilityBuilding.h"

/**
 * @class SewagePlant
 * @brief Represents a sewage treatment plant that manages sewage removal and treatment.
 * 
 * The SewagePlant class is derived from UtilityBuilding and includes specific functionality
 * related to sewage removal rates and other utility operations.
 */
class SewagePlant : public UtilityBuilding {
private:
    int sewageRemovalRate; ///< The rate at which the sewage plant can remove sewage.

public:
    /**
     * @brief Constructs a SewagePlant object with the specified ID.
     * @param id The unique identifier of the sewage plant.
     */
    SewagePlant(int id);

    /**
     * @brief Gets the sewage removal rate of the plant.
     * @return The sewage removal rate.
     */
    int getSewageRemovalRate();

    /**
     * @brief Sets the sewage removal rate for the plant.
     * @param sewageRemovalRate The new sewage removal rate to set.
     */
    void setSewageRemovalRate(int sewageRemovalRate);

    /**
     * @brief Prints the details of the sewage plant.
     */
    virtual void print() override;

    // New functions

    /**
     * @brief Gets the average satisfaction score for the sewage plant.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the sewage plant.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the sewage plant.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the sewage plant.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the sewage plant.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the sewage plant.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the sewage plant.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the sewage plant.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the sewage plant.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the sewage plant.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // SEWAGEPLANT_H
