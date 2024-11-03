#ifndef MONUMENT_H
#define MONUMENT_H

#include "LandMark.h"

/**
 * @class Monument
 * @brief Represents a monument, a specific type of landmark.
 * 
 * The Monument class inherits from the LandMark class and provides methods for managing and retrieving
 * various resource metrics specific to monuments.
 */
class Monument : public LandMark {
public:
    /**
     * @brief Constructs a Monument object with the specified ID.
     * @param id The unique ID of the monument.
     */
    Monument(int id);

    /**
     * @brief Destructor for the Monument object.
     */
    ~Monument();

    /**
     * @brief Prints the details of the monument.
     */
    void print() override;

    // New functions

    /**
     * @brief Gets the average satisfaction score for the monument.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the monument.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the monument.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the monument.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the monument.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the monument.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the monument.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the monument.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the monument.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the monument.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // MONUMENT_H
