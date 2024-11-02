#include "TransportationService.h"
#include <iostream>
#include <algorithm>

using namespace std;

TransportationService::TransportationService(shared_ptr<TransportationStrategy> strat,
                                             int startX, int startY, int endX, int endY)
    : strategy(move(strat)), startX(startX), startY(startY), endX(endX), endY(endY) {}

void TransportationService::setStrategy(shared_ptr<TransportationStrategy> strat) {
    strategy = move(strat);
    notifyObservers("-- Strategy changed to: " + strategy->getDescription() + " --");
}

double TransportationService::getCost() {
    return strategy->calculateCost(currentLocation, startX, startY, endX, endY);
}

double TransportationService::getDuration() {
    return strategy->calculateDuration(currentLocation, startX, startY, endX, endY);
}

void TransportationService::displayOption() {
    cout << "Transport Mode: " << strategy->getDescription() << endl;
    cout << "Estimated Cost: " << getCost() << " ZAR" << endl;
    cout << "Estimated Duration: " << getDuration() << " minutes" << endl;
}

// Observer methods
void TransportationService::addObserver(shared_ptr<TrafficObserver> observer) {
    observers.push_back(observer);
}

void TransportationService::removeObserver(shared_ptr<TrafficObserver> observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void TransportationService::notifyObservers(string message) {
    for (const auto& observer : observers) {
        observer->updateTrafficStatus(message);
    }
}

void TransportationService::trafficAlert() {
    notifyObservers("Traffic conditions have changed. Please consider alternative routes.");
}
