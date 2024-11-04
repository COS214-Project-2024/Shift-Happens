#include "AirStrategy.h"
#include "AirStrategy.h"

double AirStrategy::calculateCost(int distance) {
    return distance*costPerKm;
}

double AirStrategy::calculateDuration(int distance) {
    return distance/this->speed;
}

int AirStrategy::getCapacityMin() const { 
    return capacityMin; 
}
int AirStrategy::getCapacityMax() const { 
    return capacityMax; 
}
double AirStrategy::getSpeed() const { 
    return speed; 
}
double AirStrategy::getCostPerKm() const {
    return costPerKm; 
}
