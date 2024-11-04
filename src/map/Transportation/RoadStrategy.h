#ifndef ROADSTRATEGY_H
#define ROADSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

/**
 * @brief A concrete strategy class for car-based transportation.
 * 
 * This class implements the TransportationStrategy interface for cars,
 * providing specific calculations for cost and duration based on distance,
 * as well as capacity and speed information.
 * 
 * @author Reneiloe Brancn (u22556771)
 * @date 03-11-2024
 */
class RoadStrategy : public TransportationStrategy {
private:
    int capacityMin = 1;       /**< Minimum passenger capacity for the car. */
    int capacityMax = 5;       /**< Maximum passenger capacity for the car. */
    double speed = 60;         /**< Average speed of the car in km/h. */
    double costPerKm = 20;     /**< Cost per kilometer for car travel. */

public:
    /**
     * @brief Calculates the cost of travel for the car based on distance.
     * 
     * Multiplies the distance by the cost per kilometer.
     * 
     * @param distance The distance to be traveled, in kilometers.
     * @return The calculated travel cost in currency units.
     */
    double calculateCost(int distance) override;

    /**
     * @brief Calculates the duration of travel for the car based on distance.
     * 
     * Divides the distance by the car's speed to estimate the duration.
     * 
     * @param distance The distance to be traveled, in kilometers.
     * @return The estimated travel time in hours.
     */
    double calculateDuration(int distance) override;

    /**
     * @brief Returns the type of transportation.
     * 
     * @return A string representing the transportation type ("Car").
     */
    string getType() override { return "Car"; }

    // Getters

    /**
     * @brief Gets the minimum passenger capacity for the car.
     * 
     * @return The minimum number of passengers the car can accommodate.
     */
    int getCapacityMin() const;

    /**
     * @brief Gets the maximum passenger capacity for the car.
     * 
     * @return The maximum number of passengers the car can accommodate.
     */
    int getCapacityMax() const;

    /**
     * @brief Gets the average speed of the car.
     * 
     * @return The speed of the car in kilometers per hour.
     */
    double getSpeed() const;

    /**
     * @brief Gets the cost per kilometer for the car.
     * 
     * @return The cost per kilometer for car travel in currency units.
     */
    double getCostPerKm() const;
};

#endif // ROADSTRATEGY_H
