#include "TrainStrategy.h"

/**
 * @brief Calculates the cost of travel for the train based on distance.
 * 
 * Multiplies the distance by the cost per kilometer.
 * 
 * @param distance The distance to be traveled, in kilometers.
 * @return The calculated travel cost in currency units.
 */
double TrainStrategy::calculateCost(int distance) {
    return (distance * costPerKm)/2.5;
}

/**
 * @brief Calculates the duration of travel for the train based on distance.
 * 
 * Divides the distance by the train's speed to estimate the duration.
 * 
 * @param distance The distance to be traveled, in kilometers.
 * @return The estimated travel time in hours.
 */
double TrainStrategy::calculateDuration(int distance) {
    return (distance / this->speed)*100;
}

/**
 * @brief Gets the minimum capacity for the train.
 * 
 * @return The minimum number of passengers that the train can accommodate.
 */
int TrainStrategy::getCapacityMin() const { 
    return capacityMin; 
}

/**
 * @brief Gets the maximum capacity for the train.
 * 
 * @return The maximum number of passengers that the train can accommodate.
 */
int TrainStrategy::getCapacityMax() const { 
    return capacityMax; 
}

/**
 * @brief Gets the average speed of the train.
 * 
 * @return The speed of the train in kilometers per hour.
 */
double TrainStrategy::getSpeed() const { 
    return speed; 
}

/**
 * @brief Gets the cost per kilometer for the train.
 * 
 * @return The cost per kilometer for train travel in currency units.
 */
double TrainStrategy::getCostPerKm() const {
    return costPerKm; 
}
