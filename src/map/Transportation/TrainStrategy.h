#ifndef TRAINSTRATEGY_H
#define TRAINSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

class TrainStrategy : public TransportationStrategy {
private:
    int capacityMin = 50;
    int capacityMax = 300;
    double speed = 110;
    double costPerKm = 15;

public:
    double calculateCost(int distance) override;
    double calculateDuration(int distance) override;
    string getDescription() { return "Train"; }
};

#endif
