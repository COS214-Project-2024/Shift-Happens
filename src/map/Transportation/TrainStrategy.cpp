#include "TrainStrategy.h"
#include "Map.h"

TrainStrategy::TrainStrategy() 
    : capacity(300), 
      baseFare(30.0), 
      costPerKm(1.2), 
      aveSpeed(110.0) {}

double TrainStrategy::calculateCost(shared_ptr<Map> map, int startX, int startY, int endX, int endY) {
    // Use the map instance to calculate the distance
    double distance = map->trainDistanceTo(startX, startY, endX, endY);
	string mssg = "This TRAIN trip costs: R";
    return mssg, baseFare + (costPerKm * distance);
}

double TrainStrategy::calculateDuration(shared_ptr<Map> map, int startX, int startY, int endX, int endY) {
    // Use the map instance to calculate the distance
    double distance = map->trainDistanceTo(startX, startY, endX, endY);
	string mssg = "The TRAIN trip will take: (mins)";
    return mssg, (distance / aveSpeed) * 60; // Convert hours to minutes
}
