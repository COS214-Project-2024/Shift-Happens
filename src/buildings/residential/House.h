#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"
#include <iostream>

class House : public ResidentialBuilding{
	private:
		int satisfactionScore;
        int capacity;
	    int incomePerHour;
	public:
		House(int id);
		~House();
		virtual void print() const override;
};

#endif
