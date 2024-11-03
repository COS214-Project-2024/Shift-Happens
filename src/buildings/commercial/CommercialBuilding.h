#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H
#include "../Building.h"
#include <vector>

using namespace std;

/**
 * @class CommercialBuilding
 * @brief Represents a commercial building that inherits from the Building class.
 * 
 * The CommercialBuilding class includes properties specific to commercial buildings,
 * such as income generation, satisfaction scores, and employment data. It extends
 * functionality from the base Building class and adds new methods to manage
 * building-specific data.
 */

class CommercialBuilding : public Building {
private:
    int incomePerHour; ///< The income generated per hour by the building.
    int satisfactionScore; ///< The satisfaction score associated with the building.
    int numberOfEmployees; ///< The number of employees working in the building.

public:
    /**
     * @brief Constructs a CommercialBuilding object with the given parameters.
     * @param id The unique ID of the building.
     * @param incomePerHour The income generated per hour.
     * @param variant The variant type of the building.
     * @param satisfactionScore The satisfaction score for the building.
     * @param numberOfEmployees The number of employees.
     * @param constructionPrice The cost to construct the building.
     * @param wasteProduced The waste produced by the building.
     * @param sewageProduced The sewage produced by the building.
     * @param electricityDemand The electricity demand of the building.
     * @param waterDemand The water demand of the building.
     */
    CommercialBuilding(int id, int incomePerHour, string variant, int satisfactionScore, int numberOfEmployees, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);

     /**
     * @brief Gets the income generated per hour.
     * @return The income per hour.
     */
    int getIncomePerHour();

     /**
     * @brief Sets the income generated per hour.
     * @param incomePerHour The new income per hour value.
     */
    void setIncomePerHour(int incomePerHour);

     /**
     * @brief Gets the satisfaction score of the building.
     * @return The satisfaction score.
     */
    int getSatisfactionScore();
    
    /**
     * @brief Sets the satisfaction score of the building.
     * @param satisfactionScore The new satisfaction score.
     */
    void setSatisfactionScore(int satisfactionScore);

    /**
     * @brief Gets the number of employees working in the building.
     * @return The number of employees.
     */
    int getNumberOfEmployees();

    /**
     * @brief Sets the number of employees working in the building.
     * @param numberOfEmployees The new number of employees.
     */
    void setNumberOfEmployees(int numberOfEmployees);

    /**
     * @brief Pure virtual function for printing building information.
     */
    virtual void print() = 0;

    // New functions

     /**
     * @brief Gets the average satisfaction score for the building.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the building.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage for the building.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

     /**
     * @brief Gets the total electricity supply for the building.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand for the building.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity for the building.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the building.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production for the building.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production for the building.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the building.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif
