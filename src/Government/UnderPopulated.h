#ifndef UNDERPOPULATED_H
#define UNDERPOPULATED_H

#include "Population.h"
#include "Normal.h"

class UnderPopulated : public Population {
	private:
    int PopUnderHighCap = 400;
	public:
		void increasePopulation(int increase);
		void descreasePopulation(int decrease);
};


#endif
