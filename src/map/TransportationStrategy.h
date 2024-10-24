#ifndef TRANSPORTTIONSTRATEGY_H
#define TRANSPORTTIONSTRATEGY_H

#include <string>
#include "Map.h" // Assuming Map.h contains the definition of Building_State::Map


	class TransporttionStrategy {


	public:
		virtual double calculateCost(Building_State::Map start, Building_State::Map end) = 0;

		virtual std::string getDescription() = 0;

		virtual string getDescription() = 0;
	};

#endif
