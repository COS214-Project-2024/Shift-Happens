#ifndef TRAINSTRATEGY_H
#define TRAINSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

/**
 * @class TrainStrategy
 * @brief Implements the train transportation strategy for city simulation.
 *
 * Provides methods to calculate transportation cost and duration for train travel, along with attributes such as capacity, speed, and cost per kilometer.
 */
class TrainStrategy : public TransportationStrategy
{
private:
    int capacityMin = 15;  /**< Minimum capacity for train transportation. */
    int capacityMax = 300; /**< Maximum capacity for train transportation. */
    double speed = 110;    /**< Speed of the train transportation in km/h. */
    double costPerKm = 15; /**< Cost per kilometer for train transportation. */

public:
    /**
     * @brief Calculates the cost of train transportation based on the distance.
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
    string getType() override { return "Train"; }

    // Getters

    /**
     * @brief Gets the minimum capacity for train transportation.
     * @return The minimum capacity.
     */
    int getCapacityMin() const;

    /**
     * @brief Gets the maximum capacity for train transportation.
     * @return The maximum capacity.
     */
    int getCapacityMax() const;

    /**
     * @brief Gets the speed of train transportation.
     * @return The speed in km/h.
     */
    double getSpeed() const;

    /**
     * @brief Gets the cost per kilometer for train transportation.
     * @return The cost per kilometer.
     */
    double getCostPerKm() const;
};

#endif // TRAINSTRATEGY_H
