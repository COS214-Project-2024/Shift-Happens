#ifndef PUBLICSTRATEGY_H
#define PUBLICSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

class PublicStrategy : public TransportationStrategy {
private:
    int capacityMin = 5;
    int capacityMax = 15;
    double speed = 55;
    double costPerKm = 10;

public:
    double calculateCost(int distance) override;
    double calculateDuration(int distance) override;
    string getType() override { return "Taxi"; }

    //getters
    int getCapacityMin() const { return capacityMin; }
    int getCapacityMax() const { return capacityMax; }
    double getSpeed() const { return speed; }
    double getCostPerKm() const { return costPerKm; }
};
#endif
