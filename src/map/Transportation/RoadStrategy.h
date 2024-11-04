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
    double calculateCost(int distance) override;
    double calculateDuration(int distance) override;
    string getType() override { return "Car"; }

    //getters
    int getCapacityMin() const { return capacityMin; }
    int getCapacityMax() const { return capacityMax; }
    double getSpeed() const { return speed; }
    double getCostPerKm() const { return costPerKm; }
};

#endif // ROADSTRATEGY_H
