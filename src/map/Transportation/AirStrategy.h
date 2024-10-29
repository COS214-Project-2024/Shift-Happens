#ifndef AIRSTRATEGY_H
#define AIRSTRATEGY_H

#include "TransportationStrategy.h"
#include "Map.h"
#include <memory>
#include <string>

using namespace std;

class AirStrategy : public TransportationStrategy {

private:
    int capacity;
    double fare;
    double speed;
    double costPerKm;

public:
	AirStrategy(int cap, double fare, double speed, double baseCost);
    double calculateCost(shared_ptr<Map> start, shared_ptr<Map> end) override;
    double calculateDuration(shared_ptr<Map> start, shared_ptr<Map> end) override;
    string getDescription() override;
};
#endif

    
