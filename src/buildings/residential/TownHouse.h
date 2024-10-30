#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "ResidentialBuilding.h"
#include <iostream>

class TownHouse : public ResidentialBuilding{
	private:
		int satisfactionScore;
        int capacity;
	    int incomePerHour;
public:
	TownHouse(int id);
	~TownHouse();
	virtual void print();

};

#endif
