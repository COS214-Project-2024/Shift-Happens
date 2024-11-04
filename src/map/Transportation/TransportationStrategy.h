#ifndef TRANSPORTATIONSTRATEGY_H
#define TRANSPORTATIONSTRATEGY_H

#include <string>
#include <memory>
#include "../Map.h"

using namespace std;

/**
 * @brief Abstract base class for transportation strategies.
 * 
 * Defines the interface for different transportation modes, allowing
 * for calculation of travel cost and duration based on distance, and
 * retrieval of the transport type as a string.
 * 
 * @author Reneiloe Brancn (u22556771)
 * @date 03-11-2024
 */
class TransportationStrategy {
public:
    /**
     * @brief Virtual destructor for the transportation strategy.
     */
    virtual ~TransportationStrategy() = default;

    /**
     * @brief Calculates the cost of travel for the given distance.
     * 
     * @param distance The distance to be traveled, in kilometers.
     * @return The estimated cost of travel.
     */
    virtual double calculateCost(int distance) = 0;

    /**
     * @brief Calculates the duration of travel for the given distance.
     * 
     * @param distance The distance to be traveled, in kilometers.
     * @return The estimated travel time in minutes.
     */
    virtual double calculateDuration(int distance) = 0;

    /**
     * @brief Retrieves the type of transportation strategy.
     * 
     * @return A string representing the type of transportation (e.g., "Car", "Taxi", "Train", "Airplane").
     */
    virtual string getType() = 0;
};

#endif
