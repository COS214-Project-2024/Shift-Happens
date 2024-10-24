#ifndef TRANSPORTATIONSERVICE_H
#define TRANSPORTATIONSERVICE_H

namespace Building_State {
	class TransportationService {

	private:
		Building_State::TransporttionStrategy* strategy;
		Building_State::Map currLocation;
		Building_State::Map destination;

	public:
		void setStrategy(strategy TransportationStrategy);

		double getCost();

		double getDuration();

		void displayOption();
	};
}

#endif
