#ifndef TRANSPORTATIONSTRATEGY_H
#define TRANSPORTATIONSTRATEGY_H

#include <string>
#include <memory>
#include "../Map.h"

using namespace std;

/**
 * @class TransportationStrategy
 * @brief Abstract base class for transportation strategies in the city simulation.
 *
 * Provides a common interface for calculating the cost and duration of travel, as well as retrieving the transportation type.
 */
class TransportationStrategy
{
public:
    /**
     * @brief Virtual destructor for TransportationStrategy.
     */
    virtual ~TransportationStrategy() = default;

    /**
     * @brief Calculates the cost of transportation based on the distance.
     * @param distance The distance to be traveled in kilometers.
     * @return The calculated cost of the trip.
     */
    virtual double calculateCost(int distance) = 0;

    /**
     * @brief Calculates the duration of transportation based on the distance.
     * @param distance The distance to be traveled in kilometers.
     * @return The calculated duration of the trip in hours.
     */
    virtual double calculateDuration(int distance) = 0;

    /**
     * @brief Returns the type of transportation as a string.
     * @return The type of transportation.
     */
    virtual string getType() = 0;
};

#endif // TRANSPORTATIONSTRATEGY_H
