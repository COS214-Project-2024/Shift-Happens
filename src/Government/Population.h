#ifndef POPULATION_H
#define POPULATION_H

#include "Economy.h"

class Population {
	protected:
		int PopulationCount;
		Economy* economy;
	
	public:
		virtual void increasePopulation(int increase) = 0;
		virtual void descreasePopulation(int decrease) = 0;
	
};

#endif
