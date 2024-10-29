#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"
#include <iostream>

class Estate : public ResidentialBuilding{
	private:
		int satisfactionScore;
        int capacity;
	    int incomePerHour;
	public:
		Estate(int id);
		~Estate();
		virtual void print() const override;
};

#endif