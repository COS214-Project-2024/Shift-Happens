#include "PublicStrategy.h"
#include "Map.h"

PublicStrategy::PublicStrategy() 
    : capacity(165), 
      baseFare(3125.1), 
      costPerKm(259), 
      aveSpeed(800.0) {}

double PublicStrategy::calculateCost(shared_ptr<Map> map, int startX, int startY, int endX, int endY) {
    double distance = map->airDistanceTo(startX, startY, endX, endY);
	string mssg = "This TAXI trip costs: R";
    return mssg, baseFare + (costPerKm * distance);
}

double PublicStrategy::calculateDuration(shared_ptr<Map> map, int startX, int startY, int endX, int endY) {
    double distance = map->airDistanceTo(startX, startY, endX, endY);
	string mssg = "The TAXI trip will take: (mins)";
    return mssg, (distance / aveSpeed) * 60; 
}
