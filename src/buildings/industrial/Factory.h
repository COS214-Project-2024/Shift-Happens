#ifndef FACTORY_H
#define FACTORY_H
#include "IndustrialBuilding.h"

/**
 * @class Factory
 * @brief Represents a factory, which is a type of IndustrialBuilding.
 * 
 * The Factory class includes attributes and methods related to the management
 * of a factory's operations, such as resource usage, production rates, and employee satisfaction.
 */
class Factory : public IndustrialBuilding {
private:
    int satisfactionScore;          /**< The satisfaction score of the factory employees. */
    int numberOfEmployees;          /**< The number of employees working at the factory. */
    int partProductionPerHour;      /**< The number of parts produced by the factory per hour. */
    int productionCostPerHour;      /**< The cost of production per hour. */

public:
    /**
     * @brief Constructs a Factory object with the given ID.
     * @param id The unique ID of the factory.
     */
    Factory(int id);

    /**
     * @brief Destroys the Factory object and releases any allocated resources.
     */
    ~Factory();

    /**
     * @brief Prints the details of the factory.
     */
    virtual void print();

    /**
     * @brief Gets the average satisfaction score for the factory employees.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the factory.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage for the factory.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the factory.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand for the factory.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity for the factory.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the factory.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production for the factory.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production for the factory.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the factory.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // FACTORY_H
