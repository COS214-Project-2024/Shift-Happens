#ifndef OVERPOPULATED_H
#define OVERPOPULATED_H

#include "Population.h"
#include "Normal.h"

class OverPopulated : public Population {
	private:
		int PopOverLowCap = 2000;
	public:
		void increasePopulation(int increase);
		void descreasePopulation(int decrease);
		std::string getType();
};


#endif
