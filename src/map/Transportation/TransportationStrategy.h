#ifndef TRANSPORTATIONSTRATEGY_H
#define TRANSPORTATIONSTRATEGY_H

#include <string>
#include <memory>
#include "Map.h"

using namespace std;

class TransportationStrategy {
public:
    virtual ~TransportationStrategy() = default;
    virtual double calculateCost(shared_ptr<Map> start, shared_ptr<Map> end) = 0;
    virtual double calculateDuration(shared_ptr<Map> start, shared_ptr<Map> end) = 0;
    virtual string getDescription() = 0;
};

#endif
