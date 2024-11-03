#ifndef CULTURALCENTER_H
#define CULTURALCENTER_H

#include "LandMark.h"

/**
 * @class CulturalCenter
 * @brief Represents a cultural center landmark.
 * 
 * The CulturalCenter class inherits from the LandMark class and implements functions to manage and retrieve various
 * resource metrics specific to cultural centers.
 */
class CulturalCenter : public LandMark {
public:
    /**
     * @brief Constructs a CulturalCenter object with a specified ID.
     * @param id The unique ID of the cultural center.
     */
    CulturalCenter(int id);

    /**
     * @brief Destructor for the CulturalCenter object.
     */
    ~CulturalCenter();

    /**
     * @brief Prints the details of the cultural center.
     */
    void print() override;

    // New functions

    /**
     * @brief Gets the average satisfaction score for the cultural center.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the cultural center.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the cultural center.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the cultural center.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the cultural center.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the cultural center.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the cultural center.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the cultural center.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the cultural center.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the cultural center.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // CULTURALCENTER_H
