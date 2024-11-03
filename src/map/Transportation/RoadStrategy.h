#ifndef ROADSTRATEGY_H
#define ROADSTRATEGY_H

#include "TransportationStrategy.h"
#include "Map.h"
#include <memory>
#include <string>

using namespace std;

class RoadStrategy : public TransportationStrategy {

private:
    int capacity;
    double fare;
    double speed;
    double costPerKm;

public:
	RoadStrategy(int cap, double fare, double speed, double baseCost);
    double calculateCost(shared_ptr<Map> start, shared_ptr<Map> end) override;
    double calculateDuration(shared_ptr<Map> start, shared_ptr<Map> end) override;
    string getDescription() override;
};

#endif
