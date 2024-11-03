#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H
#include "../Building.h"
#include <vector>
#include <iostream>

/**
 * @class IndustrialBuilding
 * @brief Represents an industrial building, which is a type of Building.
 * 
 * The IndustrialBuilding class includes attributes and methods related to managing
 * the operations and resources of an industrial building, including employee data and satisfaction.
 */
class IndustrialBuilding : public Building {

private:
    int numberOfEmployees;      /**< The number of employees working at the industrial building. */
    int satisfactionScore;      /**< The satisfaction score of the employees at the building. */

public:
    /**
     * @brief Constructs an IndustrialBuilding object with the given parameters.
     * @param id The unique ID of the building.
     * @param numberOfEmployees The number of employees working at the building.
     * @param variant The variant type of the building.
     * @param satisfactionScore The initial satisfaction score of the employees.
     * @param constructionPrice The cost of constructing the building.
     * @param wasteProduced The amount of waste produced by the building.
     * @param sewageProduced The amount of sewage produced by the building.
     * @param electricityDemand The electricity demand of the building.
     * @param waterDemand The water demand of the building.
     */
    IndustrialBuilding(int id, int numberOfEmployees, std::string variant, int satisfactionScore, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);

    /**
     * @brief Gets the number of employees working at the industrial building.
     * @return The number of employees.
     */
    int getNumberOfEmployees();

    /**
     * @brief Sets the number of employees working at the industrial building.
     * @param numberOfEmployees The new number of employees.
     */
    void setNumberOfEmployees(int numberOfEmployees);

    /**
     * @brief Gets the satisfaction score of the employees.
     * @return The satisfaction score.
     */
    int getSatisfactionScore();

    /**
     * @brief Sets the satisfaction score of the employees.
     * @param satisfactionScore The new satisfaction score.
     */
    void setSatisfactionScore(int satisfactionScore);

    /**
     * @brief Prints the details of the industrial building.
     */
    virtual void print();

    /**
     * @brief Gets the average satisfaction score for the industrial building.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the industrial building.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage for the industrial building.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the industrial building.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand for the industrial building.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity for the industrial building.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity for the industrial building.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production for the industrial building.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production for the industrial building.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the industrial building.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // INDUSTRIALBUILDING_H
