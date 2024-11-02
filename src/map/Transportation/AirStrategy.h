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
	AirStrategy();
    double calculateCost(shared_ptr<Map> map, int startX, int startY, int endX, int endY) override;
    double calculateDuration(shared_ptr<Map> map, int startX, int startY, int endX, int endY) override;
    string getDescription() override { return "Aeroplane"; }
};
#endif

    
