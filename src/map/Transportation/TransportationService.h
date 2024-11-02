#ifndef TRANSPORTATIONSERVICE_H
#define TRANSPORTATIONSERVICE_H

#include <memory>
#include <vector>
#include <string>
#include "TransportationStrategy.h"
#include "Map.h"

using namespace std;

// Observer interface for traffic updates
class TrafficObserver {
public:
    virtual void updateTrafficStatus(const string& message) = 0;
};

class TransportationService {
private:
    shared_ptr<TransportationStrategy> strategy;
    shared_ptr<Map> currentLocation;
    int startX;
    int startY;
    int endX;
    int endY;
    vector<shared_ptr<TrafficObserver>> observers;

public:
    TransportationService(shared_ptr<TransportationStrategy> strat,
                          int startX, int startY, int endX, int endY);

    void setStrategy(shared_ptr<TransportationStrategy> strat);
    double getCost();
    double getDuration();
    void displayOption();
    
    // Observer methods
    void addObserver(shared_ptr<TrafficObserver> observer);
    void removeObserver(shared_ptr<TrafficObserver> observer);
    void notifyObservers(string message);//previously void notifyObservers(const string& message);
    void trafficAlert(); // Trigger a traffic alert
};

#endif
