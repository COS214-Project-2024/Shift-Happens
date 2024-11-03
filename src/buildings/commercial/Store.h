#ifndef STORE_H
#define STORE_H
#include "CommercialBuilding.h"

/**
 * @class Store
 * @brief Represents a store building, which is a type of CommercialBuilding.
 * 
 * The Store class provides specific implementations for various functions related
 * to resource management, utility usage, and employment statistics for a store building.
 */
class Store : public CommercialBuilding {
public:
    /**
     * @brief Constructs a Store object with the given ID.
     * @param id The unique ID of the store building.
     */
    Store(int id);

    /**
     * @brief Destroys the Store object and releases any allocated resources.
     */
    ~Store();

    /**
     * @brief Prints the details of the store.
     */
    void print() override;

    /**
     * @brief Gets the average satisfaction score for the store.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the store.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage for the store.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the store.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand for the store.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity for the store.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the store.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production for the store.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production for the store.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the store.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // STORE_H
