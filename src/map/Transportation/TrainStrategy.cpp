#include "TrainStrategy.h"


double TrainStrategy::calculateCost(int distance) {
    return distance*costPerKm;
}

double TrainStrategy::calculateDuration(int distance) {
    return distance/this->speed;
}
