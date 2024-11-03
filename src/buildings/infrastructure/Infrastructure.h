#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include "../../map/MapComponent.h"
#include <string>

using namespace std;

/**
 * @class Infrastructure
 * @brief Represents the base class for all types of infrastructure components on the map.
 * 
 * The Infrastructure class provides fundamental properties such as dimensions, position, and construction cost,
 * along with virtual methods for calculating resource metrics and rendering.
 */
class Infrastructure : public MapComponent {
protected:
    string variant;           /**< The variant type of the infrastructure. */
    string type;              /**< The type of the infrastructure (e.g., building, road). */
    int width;                /**< The width of the infrastructure in map units. */
    int length;               /**< The length of the infrastructure in map units. */
    int yPos;                 /**< The y-coordinate position on the map. */
    int xPos;                 /**< The x-coordinate position on the map. */
    int constructionCost;     /**< The cost to construct the infrastructure. */

public:
    /**
     * @brief Constructs an Infrastructure object with a specified variant and ID.
     * @param variant The type of the infrastructure.
     * @param id The unique ID of the infrastructure.
     */
    Infrastructure(string variant, int id);

    /**
     * @brief Destructor for the Infrastructure object.
     */
    virtual ~Infrastructure();

    /**
     * @brief Gets the width of the infrastructure.
     * @return The width as an integer.
     */
    int getWidth();

    /**
     * @brief Sets the width of the infrastructure.
     * @param width The width to set.
     */
    void setWidth(int width);

    /**
     * @brief Gets the length of the infrastructure.
     * @return The length as an integer.
     */
    int getLength();

    /**
     * @brief Sets the length of the infrastructure.
     * @param length The length to set.
     */
    void setLength(int length);

    /**
     * @brief Gets the y-coordinate position of the infrastructure.
     * @return The y-coordinate as an integer.
     */
    int getYPos();

    /**
     * @brief Sets the y-coordinate position of the infrastructure.
     * @param yPos The y-coordinate to set.
     */
    void setYPos(int yPos);

    /**
     * @brief Gets the x-coordinate position of the infrastructure.
     * @return The x-coordinate as an integer.
     */
    int getXPos();

    /**
     * @brief Sets the x-coordinate position of the infrastructure.
     * @param xPos The x-coordinate to set.
     */
    void setXPos(int xPos);

    /**
     * @brief Gets the construction cost of the infrastructure.
     * @return The construction cost as an integer.
     */
    int getConstructionCost();

    /**
     * @brief Sets the construction cost of the infrastructure.
     * @param constructionCost The cost to set.
     */
    void setConstructionCost(int constructionCost);

    /**
     * @brief Renders the infrastructure on the map.
     */
    void render();

    /**
     * @brief Prints the details of the infrastructure.
     */
    virtual void print();

    // New functions

    /**
     * @brief Gets the average satisfaction score of the infrastructure.
     * @return The average satisfaction score as a double.
     */
    double getAverageSatisfactionScore() override;

    /**
     * @brief Gets the total water supply for the infrastructure.
     * @return The total water supply.
     */
    int getTotalWaterSupply() override;

    /**
     * @brief Gets the total water usage of the infrastructure.
     * @return The total water usage.
     */
    int getTotalWaterUsage() override;

    /**
     * @brief Gets the total electricity supply for the infrastructure.
     * @return The total electricity supply.
     */
    int getTotalElectricitySupply() override;

    /**
     * @brief Gets the total electricity demand of the infrastructure.
     * @return The total electricity demand.
     */
    int getTotalElectricityDemand() override;

    /**
     * @brief Gets the total sewage capacity of the infrastructure.
     * @return The total sewage capacity.
     */
    int getTotalSewageCapacity() override;

    /**
     * @brief Gets the total waste capacity of the infrastructure.
     * @return The total waste capacity.
     */
    int getTotalWasteCapacity() override;

    /**
     * @brief Gets the total waste production of the infrastructure.
     * @return The total waste production.
     */
    int getTotalWasteProduction() override;

    /**
     * @brief Gets the total sewage production of the infrastructure.
     * @return The total sewage production.
     */
    int getTotalSewageProduction() override;

    /**
     * @brief Gets the total number of jobs provided by the infrastructure.
     * @return The total number of jobs.
     */
    int getTotalNumberOfJobs() override;
};

#endif // INFRASTRUCTURE_H
