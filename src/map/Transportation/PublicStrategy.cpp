#include "PublicStrategy.h"

/**
 * @brief Calculates the total cost of travel based on the distance for public transport.
 * 
 * This method uses the `costPerKm` rate to determine the travel cost for a given distance.
 * 
 * @param distance The distance to be traveled in kilometers.
 * @return The calculated travel cost in currency units.
 */
double PublicStrategy::calculateCost(int distance) {
    return (distance * costPerKm)/2.5;
}

/**
 * @brief Calculates the duration of the journey based on distance for public transport.
 * 
 * This method computes the travel time by dividing the distance by the average speed.
 * 
 * @param distance The distance to be traveled in kilometers.
 * @return The estimated travel duration in hours.
 */
double PublicStrategy::calculateDuration(int distance) {
    return (distance / this->speed)*100;
}

/**
 * @brief Gets the minimum passenger capacity for public transport.
 * 
 * This method returns the minimum number of passengers that the public transport can accommodate.
 * 
 * @return The minimum capacity as an integer.
 */
int PublicStrategy::getCapacityMin() const { 
    return capacityMin; 
}

/**
 * @brief Gets the maximum passenger capacity for public transport.
 * 
 * This method returns the maximum number of passengers that the public transport can accommodate.
 * 
 * @return The maximum capacity as an integer.
 */
int PublicStrategy::getCapacityMax() const { 
    return capacityMax; 
}

/**
 * @brief Gets the speed of public transport.
 * 
 * This method returns the average speed of the public transport, used to calculate travel time.
 * 
 * @return The speed in kilometers per hour.
 */
double PublicStrategy::getSpeed() const { 
    return speed; 
}

/**
 * @brief Gets the cost per kilometer for public transport.
 * 
 * This method returns the cost per kilometer for public transport, used to calculate travel cost.
 * 
 * @return The cost per kilometer in currency units.
 */
double PublicStrategy::getCostPerKm() const {
    return costPerKm; 
}
