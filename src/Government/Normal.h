#ifndef NORMAL_H
#define NORMAL_H

#include "Population.h"
#include "OverPopulated.h"
#include "UnderPopulated.h"

class Normal : public Population {
  private:
		int PopNormalHighCap = 2000;
    int PopNormalLowCap = 400;
	public:
		void increasePopulation(int increase);
		void descreasePopulation(int decrease);
		std::string getType();
};


#endif
