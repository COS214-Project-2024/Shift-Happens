#include "BusStrategy.h"

BusStrategy::BusStrategy(int cap, double fare, double speed, double baseCost) {
	capacity = cap;
	this->fare = fare;
	this->speed = speed;
	costPerKm = baseCost;
}

double BusStrategy::calculateCost(shared_ptr<Map> start, shared_ptr<Map> end) {
}

double BusStrategy::calculateDuration(shared_ptr<Map> start, shared_ptr<Map> end) {
}

string BusStrategy::getDescription() {
}

