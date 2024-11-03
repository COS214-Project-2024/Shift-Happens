#ifndef TRANSPORTBUILDING_H
#define TRANSPORTBUILDING_H

#include "../Building.h"
#include <string>

/**
 * @class TransportBuilding
 * @brief Represents a transport building, such as a bus station, train station, or airport.
 * 
 * The TransportBuilding class inherits from the Building class and includes methods 
 * to manage resources, costs, and capacities associated with transport facilities.
 */
class TransportBuilding : public Building
{
private:
    int capacity;            ///< The capacity of the transport building.
    int maintenanceCost;    ///< The maintenance cost of the transport building.
    int constructionCost;   ///< The construction cost of the transport building.

public:
    /**
     * @brief Constructs a TransportBuilding object with specified parameters.
     * @param id The unique ID of the transport building.
     * @param capacity The capacity of the transport building.
     * @param variant The variant of the transport building.
     * @param maintenanceCost The maintenance cost.
     * @param constructionCost The construction cost.
     * @param wasteProduced The amount of waste produced.
     * @param sewageProduced The amount of sewage produced.
     * @param electricityDemand The electricity demand.
     * @param waterDemand The water demand.
     */
    TransportBuilding(int id, int capacity, std::string variant, int maintenanceCost, int constructionCost, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);

    /**
     * @brief Gets the capacity of the transport building.
     * @return The capacity.
     */
    int getCapacity() const;

    /**
     * @brief Sets the capacity of the transport building.
     * @param capacity The new capacity to set.
     */
    void setCapacity(int capacity);

    /**
     * @brief Gets the maintenance cost of the transport building.
     * @return The maintenance cost.
     */
    int getMaintenanceCost() const;

    /**
     * @brief Sets the maintenance cost of the transport building.
     * @param maintenanceCost The new maintenance cost to set.
     */
    void setMaintenanceCost(int maintenanceCost);

    /**
     * @brief Gets the construction cost of the transport building.
     * @return The construction cost.
     */
    int getConstructionCost() const;

    /**
     * @brief Sets the construction cost of the transport building.
     * @param constructionCost The new construction cost to set.
     */
    void setConstructionCost(int constructionCost);

    /**
     * @brief Prints the details of the transport building.
     */
    virtual void print();

    /**
     * @brief Destructor for the TransportBuilding object.
     */
    ~TransportBuilding();

    // New functions

    /**
     * @brief Gets the average satisfaction score for the transport building.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the transport building.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the transport building.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the transport building.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the transport building.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the transport building.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the transport building.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the transport building.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the transport building.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the transport building.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // TRANSPORTBUILDING_H
