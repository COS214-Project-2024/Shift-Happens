#ifndef BUSSTRATEGY_H
#define BUSSTRATEGY_H

namespace Building_State {
	class BusStrategy : Building_State::TransporttionStrategy {

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
