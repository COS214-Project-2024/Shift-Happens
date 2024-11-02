#include "PublicStrategy.h"
#include "Map.h"

PublicStrategy::PublicStrategy() 
    : capacity(15), 
      baseFare(15), 
      costPerKm(10), 
      aveSpeed(55.0) {}

double PublicStrategy::calculateCost(shared_ptr<Map> map, int startX, int startY, int endX, int endY) {
    double distance = map->roadDistanceTo(startX, startY, endX, endY);
	string mssg = "This TAXI trip costs: R";
    return mssg, baseFare + (costPerKm * distance);
}

double PublicStrategy::calculateDuration(shared_ptr<Map> map, int startX, int startY, int endX, int endY) {
    double distance = map->roadDistanceTo(startX, startY, endX, endY);
	string mssg = "The TAXI trip will take: (mins)";
    return mssg, (distance / aveSpeed) * 60; 
}
