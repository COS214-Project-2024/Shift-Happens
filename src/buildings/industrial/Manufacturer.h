#ifndef MANUFACTURER_H
#define MANUFACTURER_H
#include "IndustrialBuilding.h"

/**
 * @class Manufacturer
 * @brief Represents a manufacturer, a type of industrial building that produces products.
 * 
 * The Manufacturer class extends IndustrialBuilding and includes specific attributes and
 * methods related to manufacturing operations, such as employee details and production rates.
 */
class Manufacturer : public IndustrialBuilding {
private:
    int satisfactionScore;     /**< The satisfaction score of the employees at the manufacturer. */
    int numberOfEmployees;     /**< The number of employees working at the manufacturer. */
    int productsPerHour;       /**< The number of products produced per hour. */
    int partsUsedPerProduct;   /**< The number of parts used to create each product. */
    int profitPerProduct;      /**< The profit generated per product produced. */

public:
    /**
     * @brief Constructs a Manufacturer object with the given parameters.
     * @param id The unique ID of the manufacturer.
     */
    Manufacturer(int id);

    /**
     * @brief Destructor for the Manufacturer object.
     */
    ~Manufacturer();

    /**
     * @brief Prints the details of the manufacturer.
     */
    virtual void print();

    /**
     * @brief Gets the average satisfaction score for the manufacturer.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the manufacturer.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage for the manufacturer.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the manufacturer.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand for the manufacturer.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity for the manufacturer.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the manufacturer.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production for the manufacturer.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production for the manufacturer.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the manufacturer.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // MANUFACTURER_H
