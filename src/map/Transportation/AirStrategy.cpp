#include "AirStrategy.h"

/**
 * @brief Calculates the cost of travel by airplane based on the given distance.
 * 
 * @param distance The distance to be traveled in kilometers.
 * @return The calculated travel cost in currency units.
 */
double AirStrategy::calculateCost(int distance) {
    return ((distance * costPerKm)/2.5)/10;
}

/**
 * @brief Calculates the duration of the journey by airplane based on the given distance.
 * 
 * @param distance The distance to be traveled in kilometers.
 * @return The estimated travel duration in hours.
 */
double AirStrategy::calculateDuration(int distance) {
    return ((distance / this->speed)*100)/2;
}

/**
 * @brief Gets the minimum passenger capacity for the airplane.
 * 
 * @return The minimum capacity as an integer.
 */
int AirStrategy::getCapacityMin() const { 
    return capacityMin; 
}

/**
 * @brief Gets the maximum passenger capacity for the airplane.
 * 
 * @return The maximum capacity as an integer.
 */
int AirStrategy::getCapacityMax() const { 
    return capacityMax; 
}

/**
 * @brief Gets the speed of the airplane in kilometers per hour.
 * 
 * @return The speed in kilometers per hour.
 */
double AirStrategy::getSpeed() const { 
    return speed; 
}

/**
 * @brief Gets the cost per kilometer for airplane travel.
 * 
 * @return The cost per kilometer in currency units.
 */
double AirStrategy::getCostPerKm() const {
    return costPerKm; 
}
