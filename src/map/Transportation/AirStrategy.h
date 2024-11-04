#ifndef AIRSTRATEGY_H
#define AIRSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

/**
 * @class AirStrategy
 * @brief Implements the air transportation strategy for city simulation.
 *
 * Provides methods to calculate transportation cost and duration for air travel, as well as capacity, speed, and cost per kilometer.
 */
class AirStrategy : public TransportationStrategy
{

private:
    int capacityMin = 20;   /**< Minimum capacity for air transportation. */
    int capacityMax = 165;  /**< Maximum capacity for air transportation. */
    double speed = 500;     /**< Speed of the air transportation in km/h. */
    double costPerKm = 250; /**< Cost per kilometer for air transportation. */

public:
    /**
     * @brief Calculates the cost of air transportation based on the distance.
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
    string getType() override { return "Aeroplane"; }

    // Getters

    /**
     * @brief Gets the minimum capacity for air transportation.
     * @return The minimum capacity.
     */
    int getCapacityMin() const;

    /**
     * @brief Gets the maximum capacity for air transportation.
     * @return The maximum capacity.
     */
    int getCapacityMax() const;

    /**
     * @brief Gets the speed of air transportation.
     * @return The speed in km/h.
     */
    double getSpeed() const;

    /**
     * @brief Gets the cost per kilometer for air transportation.
     * @return The cost per kilometer.
     */
    double getCostPerKm() const;
};

#endif // AIRSTRATEGY_H
