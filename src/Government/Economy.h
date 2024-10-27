#ifndef ECONOMY_H
#define ECONOMY_H

#include "CitySubject.h"
#include "Population.h"

class Economy : public CitySubject {
	private:
		Population* PopulationState;

	public:
		void setPopulationState(Population* newState);
};


#endif
