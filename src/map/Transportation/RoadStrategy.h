#ifndef ROADSTRATEGY_H
#define ROADSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

class RoadStrategy : public TransportationStrategy {
private:
    int capacity; // = 5;         
    double baseFare;// = 20.0;       
    double costPerKm; // = 8.0;
    double aveSpeed; // = 60.0; 

public:
    RoadStrategy();
    double calculateCost(shared_ptr<Map> map, int startX, int startY, int endX, int endY) override;
    double calculateDuration(shared_ptr<Map> map, int startX, int startY, int endX, int endY) override;
    string getDescription() override { return "Car"; }
};

#endif // ROADSTRATEGY_H
