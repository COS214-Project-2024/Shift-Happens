#include "RoadStrategy.h"


double RoadStrategy::calculateCost(int distance) {
    return distance*costPerKm;
}

double RoadStrategy::calculateDuration(int distance) {
    return distance/this->speed;
}

int RoadStrategy::getCapacityMin() const { 
    return capacityMin; 
}
int RoadStrategy::getCapacityMax() const { 
    return capacityMax; 
}
double RoadStrategy::getSpeed() const { 
    return speed; 
}
double RoadStrategy::getCostPerKm() const {
    return costPerKm; 
}
