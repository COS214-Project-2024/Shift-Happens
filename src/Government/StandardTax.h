#ifndef STANDARDTAX_H
#define STANDARDTAX_H

#include "Tax.h"
#include "HighTax.h"
#include "LowTax.h"

class StandardTax : public Tax {
	private:
		int StandardTHighCap = 35;
		int StandardTLowCap = 20;
	public:
		void higher(double increase);
		void lower(double decrease);
		std::string getType();

		void higherBusiness(double increase);
		void lowerBusiness(double decrease);
	};

#endif
