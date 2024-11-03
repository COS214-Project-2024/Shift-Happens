#ifndef LANDMARK_H
#define LANDMARK_H

#include "../Building.h"

/**
 * @class LandMark
 * @brief Represents a landmark building.
 * 
 * The LandMark class inherits from the Building class and includes attributes and methods for managing and retrieving
 * various resource metrics specific to landmarks.
 */
class LandMark : public Building {
protected:
    string variant; ///< The variant of the landmark.
    int satisfactionScore; ///< The satisfaction score of the landmark.

public:
    /**
     * @brief Constructs a LandMark object with specified parameters.
     * @param id The unique ID of the landmark.
     * @param variant The variant of the landmark.
     * @param constructionPrice The construction price of the landmark.
     * @param wasteProduced The amount of waste produced by the landmark.
     * @param sewageProduced The amount of sewage produced by the landmark.
     * @param electricityDemand The electricity demand of the landmark.
     * @param waterDemand The water demand of the landmark.
     * @param satisfactionScore The satisfaction score of the landmark.
     */
    LandMark(int id, string variant, int constructionPrice, int wasteProduced, int sewageProduced, 
             int electricityDemand, int waterDemand, int satisfactionScore);

    /**
     * @brief Gets the satisfaction score of the landmark.
     * @return The satisfaction score.
     */
    int getSatisfactionScore();

    /**
     * @brief Sets the satisfaction score of the landmark.
     * @param satisfactionScore The new satisfaction score.
     */
    void setSatisfactionScore(int satisfactionScore);

    /**
     * @brief Renders the landmark.
     */
    void render();

    /**
     * @brief Prints the details of the landmark.
     */
    void print();

    /**
     * @brief Destructor for the LandMark object.
     */
    ~LandMark();

    // New functions

    /**
     * @brief Gets the average satisfaction score for the landmark.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the landmark.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the landmark.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the landmark.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the landmark.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the landmark.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the landmark.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the landmark.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the landmark.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the landmark.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // LANDMARK_H
