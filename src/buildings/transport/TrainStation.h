#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "TransportBuilding.h"

/**
 * @class TrainStation
 * @brief Represents a train station, a specialized type of transport building.
 * 
 * The TrainStation class inherits from the TransportBuilding class and includes
 * specific implementations for managing resources and calculating satisfaction scores.
 */
class TrainStation : public TransportBuilding
{
public:
    /**
     * @brief Constructs a TrainStation object with a specified ID.
     * @param id The unique ID of the train station.
     */
    TrainStation(int id);

    /**
     * @brief Destructor for the TrainStation object.
     */
    ~TrainStation();

    /**
     * @brief Prints the details of the train station.
     */
    void print() override;

    // New functions

    /**
     * @brief Gets the average satisfaction score for the train station.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the train station.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the train station.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the train station.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the train station.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the train station.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the train station.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the train station.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the train station.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the train station.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // TRAINSTATION_H
