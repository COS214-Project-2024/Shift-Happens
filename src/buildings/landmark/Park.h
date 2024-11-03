#ifndef PARK_H
#define PARK_H

#include "LandMark.h"

/**
 * @class Park
 * @brief Represents a park, a specific type of landmark.
 * 
 * The Park class inherits from the LandMark class and provides methods for managing and retrieving
 * various resource metrics specific to parks.
 */
class Park : public LandMark {
public:
    /**
     * @brief Constructs a Park object with the specified ID.
     * @param id The unique ID of the park.
     */
    Park(int id);

    /**
     * @brief Destructor for the Park object.
     */
    ~Park();

    /**
     * @brief Prints the details of the park.
     */
    void print() override;

    // New functions

    /**
     * @brief Gets the average satisfaction score for the park.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the park.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the park.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the park.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the park.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the park.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the park.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the park.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the park.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the park.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // PARK_H
