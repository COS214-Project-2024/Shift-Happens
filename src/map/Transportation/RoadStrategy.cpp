#include "RoadStrategy.h"

/**
 * @brief Calculates the cost of travel for the car based on distance.
 * 
 * This function multiplies the given distance by the car's cost per kilometer.
 * 
 * @param distance The distance to be traveled, in kilometers.
 * @return The calculated travel cost in currency units.
 */
double RoadStrategy::calculateCost(int distance) {
    return (distance * costPerKm)/2.5;
}

/**
 * @brief Calculates the duration of travel for the car based on distance.
 * 
 * This function divides the given distance by the car's speed to estimate the duration.
 * 
 * @param distance The distance to be traveled, in kilometers.
 * @return The estimated travel time in hours.
 */
double RoadStrategy::calculateDuration(int distance) {
    return (distance / this->speed)*100;
}

/**
 * @brief Gets the minimum passenger capacity for the car.
 * 
 * @return The minimum number of passengers the car can accommodate.
 */
int RoadStrategy::getCapacityMin() const { 
    return capacityMin; 
}

/**
 * @brief Gets the maximum passenger capacity for the car.
 * 
 * @return The maximum number of passengers the car can accommodate.
 */
int RoadStrategy::getCapacityMax() const { 
    return capacityMax; 
}

/**
 * @brief Gets the average speed of the car.
 * 
 * @return The speed of the car in kilometers per hour.
 */
double RoadStrategy::getSpeed() const { 
    return speed; 
}

/**
 * @brief Gets the cost per kilometer for the car.
 * 
 * @return The cost per kilometer for car travel in currency units.
 */
double RoadStrategy::getCostPerKm() const {
    return costPerKm; 
}
