#ifndef AIRSTRATEGY_H
#define AIRSTRATEGY_H

#include <string>
#include "TransportationStrategy.h"
#include "Map.h"

using namespace std;
namespace Building_State {
	class AirStrategy : public Building_State::TransporttionStrategy {

	private:
		int capacity;
		double baseFare;
		double aveSpeed;
		double costPerKm;

	public:
		double calculateCost(Building_State::Map start, Building_State::Map end);

		double calcDuration(Building_State::Map start, Building_State::Map end);

		string getDescription();
	};
}

#endif
