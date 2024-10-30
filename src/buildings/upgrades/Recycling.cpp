#include "Recycling.h"

Recycling::Recycling(Building* building) : Upgrade(building) {}

int Recycling::getWasteProduced() {
    return 0; // Set waste produced to 0
}