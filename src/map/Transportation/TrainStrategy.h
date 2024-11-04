#ifndef TRAINSTRATEGY_H
#define TRAINSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

/**
 * @brief Train transportation strategy for calculating travel cost and duration.
 * 
 * Implements the train transportation mode, with properties like minimum and 
 * maximum capacity, speed, and cost per kilometer. Provides methods to calculate 
 * the cost and duration of travel based on the given distance.
 * 
 * @author Reneiloe Brancn (u22556771)
 * @date 03-11-2024
 */
class TrainStrategy : public TransportationStrategy {
private:
    int capacityMin = 10; ///< Minimum capacity for the train
    int capacityMax = 300; ///< Maximum capacity for the train
    double speed = 110; ///< Average speed of the train in km/h
    double costPerKm = 15; ///< Cost per kilometer for train travel

public:
    /**
     * @brief Calculates the cost of travel for the train based on distance.
     * 
     * @param distance The distance to be traveled, in kilometers.
     * @return The calculated travel cost in currency units.
     */
    double calculateCost(int distance) override;

    /**
     * @brief Calculates the duration of travel for the train based on distance.
     * 
     * @param distance The distance to be traveled, in kilometers.
     * @return The estimated travel time in minutes.
     */
    double calculateDuration(int distance) override;

    /**
     * @brief Retrieves the type of transportation.
     * 
     * @return A string representing the type of transportation ("Train").
     */
    string getType() override { return "Train"; }

    // Getters
    /**
     * @brief Gets the minimum capacity for the train.
     * 
     * @return The minimum capacity.
     */
    int getCapacityMin() const;

    /**
     * @brief Gets the maximum capacity for the train.
     * 
     * @return The maximum capacity.
     */
    int getCapacityMax() const;

    /**
     * @brief Gets the average speed of the train.
     * 
     * @return The speed in km/h.
     */
    double getSpeed() const;

    /**
     * @brief Gets the cost per kilometer for the train.
     * 
     * @return The cost per kilometer.
     */
    double getCostPerKm() const;
};

#endif
