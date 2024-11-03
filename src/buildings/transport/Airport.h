#ifndef AIRPORT_H
#define AIRPORT_H

#include "TransportBuilding.h"

/**
 * @class Airport
 * @brief Represents an airport, a specialized type of transport building.
 * 
 * The Airport class inherits from the TransportBuilding class and includes
 * specific implementations for managing resources and calculating satisfaction scores.
 */
class Airport : public TransportBuilding
{
public:
    /**
     * @brief Constructs an Airport object with a specified ID.
     * @param id The unique ID of the airport.
     */
    Airport(int id);

    /**
     * @brief Destructor for the Airport object.
     */
    ~Airport();

    /**
     * @brief Prints the details of the airport.
     */
    void print() override;

    // New functions

    /**
     * @brief Gets the average satisfaction score for the airport.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the airport.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the airport.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the airport.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the airport.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the airport.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the airport.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the airport.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the airport.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the airport.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // AIRPORT_H
