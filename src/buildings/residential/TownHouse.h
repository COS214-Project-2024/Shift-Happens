#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "ResidentialBuilding.h"
class TownHouse : public ResidentialBuilding{
	private:
		int satisfactionScore;
        int capacity;
	    int incomePerHour;
public:
	TownHouse(int id);
	~TownHouse();

};

#endif
