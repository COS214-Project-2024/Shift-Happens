#include "TrainStrategy.h"


double TrainStrategy::calculateCost(int distance) {
    return distance*costPerKm;
}

double TrainStrategy::calculateDuration(int distance) {
    return distance/this->speed;
}

int TrainStrategy::getCapacityMin() const { 
    return capacityMin; 
}
int TrainStrategy::getCapacityMax() const { 
    return capacityMax; 
}
double TrainStrategy::getSpeed() const { 
    return speed; 
}
double TrainStrategy::getCostPerKm() const {
    return costPerKm; 
}

