#ifndef ROADSTRATEGY_H
#define ROADSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

/**
 * @class RoadStrategy
 * @brief Implements the road transportation strategy for city simulation.
 *
 * Provides methods to calculate transportation cost and duration for road travel, along with attributes such as capacity, speed, and cost per kilometer.
 */
class RoadStrategy : public TransportationStrategy
{
private:
    int capacityMin = 1;   /**< Minimum capacity for road transportation. */
    int capacityMax = 5;   /**< Maximum capacity for road transportation. */
    double speed = 60;     /**< Speed of the road transportation in km/h. */
    double costPerKm = 20; /**< Cost per kilometer for road transportation. */

public:
    /**
     * @brief Calculates the cost of road transportation based on the distance.
     * @param distance The distance to be traveled in kilometers.
     * @return The cost of the trip.
     */
    double calculateCost(int distance) override;

    /**
     * @brief Calculates the duration of the trip based on the distance.
     * @param distance The distance to be traveled in kilometers.
     * @return The duration of the trip in hours.
     */
    double calculateDuration(int distance) override;

    /**
     * @brief Returns the type of transportation.
     * @return The type of transportation as a string.
     */
    string getType() override { return "Car"; }

    // Getters

    /**
     * @brief Gets the minimum capacity for road transportation.
     * @return The minimum capacity.
     */
    int getCapacityMin() const;

    /**
     * @brief Gets the maximum capacity for road transportation.
     * @return The maximum capacity.
     */
    int getCapacityMax() const;

    /**
     * @brief Gets the speed of road transportation.
     * @return The speed in km/h.
     */
    double getSpeed() const;

    /**
     * @brief Gets the cost per kilometer for road transportation.
     * @return The cost per kilometer.
     */
    double getCostPerKm() const;
};

#endif // ROADSTRATEGY_H
