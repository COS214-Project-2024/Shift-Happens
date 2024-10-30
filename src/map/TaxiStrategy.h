#ifndef TAXISTRATEGY_H
#define TAXISTRATEGY_H

namespace Building_State {
	class TaxiStrategy : Building_State::TransporttionStrategy {

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
