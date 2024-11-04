#include "RoadStrategy.h"


double RoadStrategy::calculateCost(int distance) {
    return distance*costPerKm;
}

double RoadStrategy::calculateDuration(int distance) {
    return distance/this->speed;
}
