#include "RainCatcher.h"

RainCatcher::RainCatcher(Building* building) : Upgrade(building) {}

int RainCatcher::getWaterDemand() {
    return 0; // Set water demand to 0
}