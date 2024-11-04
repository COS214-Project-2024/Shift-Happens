#ifndef AIRSTRATEGY_H
#define AIRSTRATEGY_H

#include "TransportationStrategy.h"
#include "Map.h"
#include <memory>
#include <string>

using namespace std;

class AirStrategy : public TransportationStrategy {

private:
    int capacityMin = 50;
    int capacityMax = 165;
    double speed = 500;
    double costPerKm = 250;

public:
    double calculateCost(int distance) override;
    double calculateDuration(int distance) override;
    string getDescription() { return "Aeroplane"; }
};
#endif

    
