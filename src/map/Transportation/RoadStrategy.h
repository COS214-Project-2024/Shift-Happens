#ifndef ROADSTRATEGY_H
#define ROADSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

class RoadStrategy : public TransportationStrategy {
private:
    int capacityMin = 1;
    int capacityMax = 5;
    double speed = 60;
    double costPerKm = 20;

public:
    RoadStrategy();
    double calculateCost(int distance) override;
    double calculateDuration(int distance) override;
    string getDescription() override { return "Car"; }
};

#endif // ROADSTRATEGY_H
