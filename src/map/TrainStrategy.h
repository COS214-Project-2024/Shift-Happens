#ifndef TRAINSTRATEGY_H
#define TRAINSTRATEGY_H

#include "TransportationStrategy.h"
#include "Map.h"
#include <memory>
#include <string>

using namespace std;

class TrainStrategy : TransportationStrategy {

private:
	int capacity;
	double baseFare;
	double costPerKm;
	double aveSpeed;

public:
    double calculateCost(shared_ptr<Map> start, shared_ptr<Map> end) override;
    double calculateDuration(shared_ptr<Map> start, shared_ptr<Map> end) override;
    string getDescription() override;
};

#endif
