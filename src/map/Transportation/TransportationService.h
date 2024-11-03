#ifndef TRANSPORTATIONSERVICE_H
#define TRANSPORTATIONSERVICE_H

#include <memory>
#include "TransportationStrategy.h"
#include "Map.h"

using namespace std;

class TransportationService {

private:
    shared_ptr<TransportationStrategy> strategy;
    shared_ptr<Map> currentLocation;
    shared_ptr<Map> destination;

public:
	TransportationService(shared_ptr<TransportationStrategy> strat, 
                          shared_ptr<Map> start, shared_ptr<Map> end);

    void setStrategy(shared_ptr<TransportationStrategy> strat);
    double getCost();
    double getDuration();
    void displayOption();
};

#endif
