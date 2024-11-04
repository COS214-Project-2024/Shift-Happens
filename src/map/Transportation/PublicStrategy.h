#ifndef PUBLICSTRATEGY_H
#define PUBLICSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

/**
 * @class PublicStrategy
 * @brief Represents the public transportation strategy (e.g., taxi) within the transportation system.
 * 
 * @author Reneiloe Brancn (u22556771)
 * @date 03-11-2024
 * 
 * This strategy class provides specific values for speed, cost per kilometer, 
 * and capacity limits for a public transport option like a taxi.
 */
class PublicStrategy : public TransportationStrategy {
private:
    int capacityMin = 2;      ///< Minimum passenger capacity for public transport.
    int capacityMax = 15;     ///< Maximum passenger capacity for public transport.
    double speed = 55;        ///< Average speed of public transport in km/h.
    double costPerKm = 10;    ///< Cost per kilometer for public transport.

public:
    /**
     * @brief Calculates the travel cost based on distance for public transport.
     * 
     * @param distance The distance to be traveled, in kilometers.
     * @return The calculated cost in currency units.
     */
    double calculateCost(int distance) override;

    /**
     * @brief Calculates the duration of travel based on distance for public transport.
     * 
     * @param distance The distance to be traveled, in kilometers.
     * @return The estimated travel time in hours.
     */
    double calculateDuration(int distance) override;

    /**
     * @brief Gets the type of transportation strategy.
     * 
     * @return The type of transportation as a string ("Taxi").
     */
    string getType() override { return "Taxi"; }

    /**
     * @brief Gets the minimum passenger capacity for public transport.
     * 
     * @return The minimum number of passengers public transport can accommodate.
     */
    int getCapacityMin() const;

    /**
     * @brief Gets the maximum passenger capacity for public transport.
     * 
     * @return The maximum number of passengers public transport can accommodate.
     */
    int getCapacityMax() const;

    /**
     * @brief Gets the average speed of public transport.
     * 
     * @return The speed of public transport in kilometers per hour.
     */
    double getSpeed() const;

    /**
     * @brief Gets the cost per kilometer for public transport.
     * 
     * @return The cost per kilometer for public transport in currency units.
     */
    double getCostPerKm() const;
};

#endif // PUBLICSTRATEGY_H
