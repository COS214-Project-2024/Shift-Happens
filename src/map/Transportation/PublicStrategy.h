#ifndef PUBLICSTRATEGY_H
#define PUBLICSTRATEGY_H

#include "TransportationStrategy.h"
#include "Map.h"
#include <memory>
#include <string>

using namespace std;

class PublicStrategy : public TransportationStrategy {
private:
    int capacity;
    double baseFare;
    double aveSpeed;
    double costPerKm;

public:
    PublicStrategy();
    double calculateCost(shared_ptr<Map> map, int startX, int startY, int endX, int endY) override;
    double calculateDuration(shared_ptr<Map> map, int startX, int startY, int endX, int endY) override;
    string getDescription() override { return "Taxi"; }
};
#endif
