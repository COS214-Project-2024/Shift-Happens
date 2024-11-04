#ifndef PUBLICSTRATEGY_H
#define PUBLICSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

/**
 * @class PublicStrategy
 * @brief Implements the public transportation strategy for city simulation.
 *
 * Provides methods to calculate transportation cost and duration for public transport, along with attributes such as capacity, speed, and cost per kilometer.
 */
class PublicStrategy : public TransportationStrategy
{
private:
    int capacityMin = 5;   /**< Minimum capacity for public transportation. */
    int capacityMax = 15;  /**< Maximum capacity for public transportation. */
    double speed = 55;     /**< Speed of the public transportation in km/h. */
    double costPerKm = 10; /**< Cost per kilometer for public transportation. */

public:
    /**
     * @brief Calculates the cost of public transportation based on the distance.
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
    string getType() override { return "Taxi"; }

    // Getters

    /**
     * @brief Gets the minimum capacity for public transportation.
     * @return The minimum capacity.
     */
    int getCapacityMin() const;

    /**
     * @brief Gets the maximum capacity for public transportation.
     * @return The maximum capacity.
     */
    int getCapacityMax() const;

    /**
     * @brief Gets the speed of public transportation.
     * @return The speed in km/h.
     */
    double getSpeed() const;

    /**
     * @brief Gets the cost per kilometer for public transportation.
     * @return The cost per kilometer.
     */
    double getCostPerKm() const;
};

#endif // PUBLICSTRATEGY_H
