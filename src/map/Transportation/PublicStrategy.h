#ifndef PUBLICSTRATEGY_H
#define PUBLICSTRATEGY_H

#include "TransportationStrategy.h"
#include "Map.h"
#include <memory>
#include <string>

using namespace std;

class PublicStrategy : public TransportationStrategy {
private:
    int capacityMin = 20;
    int capacityMax = 165;
    double speed = 500;
    double costPerKm = 250;

public:
    double calculateCost(int distance) override;
    double calculateDuration(int distance) override;
    string getType() override { return "Taxi"; }

    //getters
    int getCapacityMin() const;
    int getCapacityMax() const;
    double getSpeed() const;
    double getCostPerKm() const;
};
#endif
