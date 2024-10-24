#ifndef TRAINSTRATEGY_H
#define TRAINSTRATEGY_H

namespace Building_State {
	class TrainStrategy : Building_State::TransporttionStrategy {

	private:
		int capacity;
		double baseFare;
		double costPerKm;
		double aveSpeed;

	public:
		double calculateCost(Building_State::Map start, Building_State::Map end);

		double calcDuration(Building_State::Map start, Building_State::Map end);

		string getDescription();
	};
}

#endif
