#include "Solar.h"

Solar::Solar(Building* building) : Upgrade(building) {}

int Solar::getElectricityDemand() {
    return 0; // Set electricity demand to 0
}