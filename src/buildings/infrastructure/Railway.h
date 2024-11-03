#ifndef RAILWAY_H
#define RAILWAY_H

#include "Infrastructure.h"

/**
 * @class Railway
 * @brief Represents a railway infrastructure component.
 * 
 * The Railway class inherits from the Infrastructure class and implements functions to manage and retrieve various
 * resource metrics specific to railway infrastructure.
 */
class Railway : public Infrastructure {
public:
    /**
     * @brief Constructs a Railway object with a specified ID.
     * @param id The unique ID of the railway.
     */
    Railway(int id);

    /**
     * @brief Destructor for the Railway object.
     */
    ~Railway();

    /**
     * @brief Prints the details of the railway.
     */
    void print() override;

    // New functions

    /**
     * @brief Gets the average satisfaction score for the railway.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the railway.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the railway.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the railway.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the railway.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the railway.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the railway.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the railway.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the railway.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the railway.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;

    /**
     * @brief Gets the type of the railway.
     * @return The type as a string.
     */
    string getType() override;

    /**
     * @brief Gets the variant of the railway.
     * @return The variant as a string.
     */
    string getVariant() override;
};

#endif // RAILWAY_H
