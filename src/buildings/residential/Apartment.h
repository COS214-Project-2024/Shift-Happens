#ifndef APARTMENT_H
#define APARTMENT_H

#include "ResidentialBuilding.h"
class Apartment : public ResidentialBuilding{
	private:
		int satisfactionScore;
        int capacity;
	    int incomePerHour;
	public:
		Apartment(int id);
		~Apartment();
		//print 
		virtual void print() const override;
};

#endif