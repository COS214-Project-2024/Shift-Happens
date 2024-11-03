#include "AirStrategy.h"
#include "Map.h"

double AirStrategy::calculateCost(int distance) {
    return distance*costPerKm;
}

double AirStrategy::calculateDuration(int distance) {
    return distance/this->speed;
}
