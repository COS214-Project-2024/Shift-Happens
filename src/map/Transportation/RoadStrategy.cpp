#include "RoadStrategy.h"
#include "Map.h"

RoadStrategy::RoadStrategy() 
    : capacity(5), 
      baseFare(20.0), 
      costPerKm(8.0), 
      aveSpeed(60.0) {}

double RoadStrategy::calculateCost(shared_ptr<Map> map, int startX, int startY, int endX, int endY) {
    double distance = map->roadDistanceTo(startX, startY, endX, endY);
    string mssg = "This CAR trip costs: R";
    return mssg, baseFare + (costPerKm * distance);
}

double RoadStrategy::calculateDuration(shared_ptr<Map> map, int startX, int startY, int endX, int endY) {
    double distance = map->roadDistanceTo(startX, startY, endX, endY);
    string mssg = "The CAR trip will take: (mins)";
    return mssg, (distance / aveSpeed) * 60;
}
