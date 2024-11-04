#include "AirStrategy.h"
#include "AirStrategy.h"

double AirStrategy::calculateCost(int distance) {
    return distance*costPerKm;
}

double AirStrategy::calculateDuration(int distance) {
    return distance/this->speed;
}
