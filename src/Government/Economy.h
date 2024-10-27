#ifndef ECONOMY_H
#define ECONOMY_H

#include "CitySubject.h"
#include "Population.h"

// Concrete subject in observer pattern
// Context in state pattern

class Economy : public CitySubject {
	private:
		Population* PopulationState;

	public:
		void setPopulationState(Population* newState);
		Population* getState();
};


#endif
