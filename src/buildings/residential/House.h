#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"
#include <iostream>

/**
 * @class House
 * @brief Represents a house, a specific type of residential building.
 * 
 * The House class inherits from the ResidentialBuilding class and provides methods
 * for managing and retrieving various resource metrics specific to houses.
 */
class House : public ResidentialBuilding {
private:
    int satisfactionScore; ///< The satisfaction score of the house residents.
    int capacity;          ///< The capacity of the house (number of units or residents).
    int incomePerHour;    ///< The income generated by the house per hour.

public:
    /**
     * @brief Constructs a House object with the specified ID.
     * @param id The unique ID of the house.
     */
    House(int id);

    /**
     * @brief Destructor for the House object.
     */
    ~House();

    /**
     * @brief Prints the details of the house.
     */
    virtual void print() override;

    // New functions

    /**
     * @brief Gets the average satisfaction score for the house.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the house.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the house.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the house.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the house.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the house.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the house.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the house.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the house.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the house.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // HOUSE_H
