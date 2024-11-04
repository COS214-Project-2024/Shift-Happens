#ifndef MALL_H
#define MALL_H
#include "CommercialBuilding.h"

/**
 * @class Mall
 * @brief Represents a shopping mall, which is a type of CommercialBuilding.
 * 
 * The Mall class provides specific implementations for functions related to
 * water supply, electricity demand, and job provision, among other features.
 */
class Mall : public CommercialBuilding {
public:
    /**
     * @brief Constructs a Mall object with the given ID.
     * @param id The unique ID of the mall.
     */
    Mall(int id);

    /**
     * @brief Destroys the Mall object and releases any allocated resources.
     */
    ~Mall();

    /**
     * @brief Prints the details of the mall.
     */
    void print() override;

    /**
     * @brief Gets the average satisfaction score for the mall.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the mall.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage for the mall.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the mall.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand for the mall.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity for the mall.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the mall.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production for the mall.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production for the mall.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the mall.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // MALL_H
