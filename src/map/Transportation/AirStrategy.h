#ifndef AIRSTRATEGY_H
#define AIRSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

/**
 * @class AirStrategy
 * @brief Concrete strategy class for air transportation.
 * 
 * Implements the `TransportationStrategy` interface for travel by airplane.
 * Calculates travel cost and duration based on distance and provides capacity limits and speed.
 * 
 * @author Reneiloe Brancn (u22556771)
 * @date 03-11-2024
 */
class AirStrategy : public TransportationStrategy {

private:
    int capacityMin = 20;  ///< Minimum passenger capacity for airplane.
    int capacityMax = 165; ///< Maximum passenger capacity for airplane.
    double speed = 500;    ///< Average speed of airplane in km/h.
    double costPerKm = 250; ///< Cost per kilometer for airplane travel.

public:
    /**
     * @brief Calculates the cost of travel by airplane based on distance.
     * 
     * @param distance The distance to be traveled in kilometers.
     * @return The calculated travel cost in currency units.
     */
    double calculateCost(int distance) override;

    /**
     * @brief Calculates the duration of the journey by airplane based on distance.
     * 
     * @param distance The distance to be traveled in kilometers.
     * @return The estimated travel duration in hours.
     */
    double calculateDuration(int distance) override;

    /**
     * @brief Gets the type of transportation.
     * 
     * @return A string representing the type of transportation, i.e., "Aeroplane".
     */
    string getType() override { return "Aeroplane"; }

    /**
     * @brief Gets the minimum passenger capacity for the airplane.
     * 
     * @return The minimum capacity as an integer.
     */
    int getCapacityMin() const;

    /**
     * @brief Gets the maximum passenger capacity for the airplane.
     * 
     * @return The maximum capacity as an integer.
     */
    int getCapacityMax() const;

    /**
     * @brief Gets the speed of the airplane.
     * 
     * @return The speed in kilometers per hour.
     */
    double getSpeed() const;

    /**
     * @brief Gets the cost per kilometer for airplane travel.
     * 
     * @return The cost per kilometer in currency units.
     */
    double getCostPerKm() const;
};

#endif // AIRSTRATEGY_H
