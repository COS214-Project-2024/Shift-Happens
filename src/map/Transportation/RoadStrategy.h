#ifndef ROADSTRATEGY_H
#define ROADSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

class RoadStrategy : public TransportationStrategy {
private:
    int capacityMin = 15;
    int capacityMax = 300;
    double speed = 110;
    double costPerKm = 15;

public:
    double calculateCost(int distance) override;
    double calculateDuration(int distance) override;
    string getType() override { return "Car"; }

    //getters
    int getCapacityMin() const;
    int getCapacityMax() const;
    double getSpeed() const;
    double getCostPerKm() const;
};

#endif // ROADSTRATEGY_H
