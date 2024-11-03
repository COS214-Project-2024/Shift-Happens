#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuilding.h"

/**
 * @class Office
 * @brief Represents an office building, which is a type of CommercialBuilding.
 * 
 * The Office class provides specific implementations for functions related to
 * utilities, waste production, and job provision, among other aspects of an office building.
 */
class Office : public CommercialBuilding {
public:
    /**
     * @brief Constructs an Office object with the given ID.
     * @param id The unique ID of the office building.
     */
    Office(int id);

    /**
     * @brief Destroys the Office object and releases any allocated resources.
     */
    ~Office();

    /**
     * @brief Prints the details of the office.
     */
    void print() override;

    /**
     * @brief Gets the average satisfaction score for the office.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the office.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage for the office.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the office.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand for the office.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity for the office.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the office.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production for the office.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production for the office.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the office.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // OFFICE_H
