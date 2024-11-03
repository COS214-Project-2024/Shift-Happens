#include "TrainStrategy.h"
#include "Map.h"


double TrainStrategy::calculateCost(int distance) {
    return distance*costPerKm;
}

double TrainStrategy::calculateDuration(int distance) {
    return distance/this->speed;
}
