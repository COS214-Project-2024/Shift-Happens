#include "PublicStrategy.h"

double PublicStrategy::calculateCost(int distance) {
    return distance*costPerKm;
}

double PublicStrategy::calculateDuration(int distance) {
    return distance/this->speed;
}

int PublicStrategy::getCapacityMin() const { 
    return capacityMin; 
}
int PublicStrategy::getCapacityMax() const { 
    return capacityMax; 
}
double PublicStrategy::getSpeed() const { 
    return speed; 
}
double PublicStrategy::getCostPerKm() const {
    return costPerKm; 
}
