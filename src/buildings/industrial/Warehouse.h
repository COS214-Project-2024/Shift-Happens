#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "IndustrialBuilding.h"

/**
 * @class Warehouse
 * @brief Represents a warehouse, a type of industrial building used for storage.
 * 
 * The Warehouse class inherits from IndustrialBuilding and includes specific attributes and
 * methods related to warehouse operations, such as storage capacity and employee details.
 */
class Warehouse : public IndustrialBuilding {
private:
    int satisfactionScore;    /**< The satisfaction score of the employees working at the warehouse. */
    int numberOfEmployees;    /**< The number of employees working at the warehouse. */
    int storageCapacity;      /**< The total storage capacity of the warehouse. */
    int storageUsed;          /**< The amount of storage currently used in the warehouse. */

public:
    /**
     * @brief Constructs a Warehouse object with the given ID.
     * @param id The unique ID of the warehouse.
     */
    Warehouse(int id);

    /**
     * @brief Destructor for the Warehouse object.
     */
    ~Warehouse();

    /**
     * @brief Prints the details of the warehouse.
     */
    virtual void print();

    /**
     * @brief Gets the average satisfaction score for the warehouse.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the warehouse.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage for the warehouse.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the warehouse.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand for the warehouse.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity for the warehouse.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the warehouse.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production for the warehouse.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production for the warehouse.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the warehouse.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // WAREHOUSE_H
