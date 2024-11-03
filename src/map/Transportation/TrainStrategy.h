#ifndef TRAINSTRATEGY_H
#define TRAINSTRATEGY_H

#include "TransportationStrategy.h"
#include <memory>
#include <string>

using namespace std;

class TrainStrategy : public TransportationStrategy {
private:
    int capacity; // 300
    double baseFare; //30.0
    double costPerKm;  //1.2
    double aveSpeed; //110.0 km/h

public:
	TrainStrategy();
    double calculateCost(shared_ptr<Map> map, int startX, int startY, int endX, int endY) override;
    double calculateDuration(shared_ptr<Map> map, int startX, int startY, int endX, int endY) override;
    string getDescription() override { return "Train"; }
};

#endif
