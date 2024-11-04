#ifndef PUBLICSTRATEGY_H
#define PUBLICSTRATEGY_H

#include "TransportationStrategy.h"
#include "Map.h"
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
    string getDescription() { return "Taxi"; }
};
#endif
