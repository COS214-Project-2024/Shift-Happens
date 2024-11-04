#include "PublicStrategy.h"

double PublicStrategy::calculateCost(int distance) {
    return distance*costPerKm;
}

double PublicStrategy::calculateDuration(int distance) {
    return distance/this->speed;
}
