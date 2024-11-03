#ifndef ROAD_H
#define ROAD_H

#include "Infrastructure.h"

/**
 * @class Road
 * @brief Represents a road infrastructure component.
 * 
 * The Road class inherits from the Infrastructure class and implements functions to manage and retrieve various
 * resource metrics specific to road infrastructure.
 */
class Road : public Infrastructure {
public:
    /**
     * @brief Constructs a Road object with a specified ID.
     * @param id The unique ID of the road.
     */
    Road(int id);

    /**
     * @brief Destructor for the Road object.
     */
    ~Road();

    /**
     * @brief Prints the details of the road.
     */
    void print() override;

    // New functions

    /**
     * @brief Gets the average satisfaction score for the road.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the road.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the road.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the road.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the road.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the road.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the road.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the road.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the road.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the road.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;

    /**
     * @brief Gets the type of the road.
     * @return The type as a string.
     */
    string getType() override;

    /**
     * @brief Gets the variant of the road.
     * @return The variant as a string.
     */
    string getVariant() override;
};

#endif // ROAD_H
