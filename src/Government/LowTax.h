#ifndef LOWTAX_H
#define LOWTAX_H

#include "StandardTax.h"
class LowTax : public Tax {
	private:
		int LowTHighCap = 20;
		int LowTHighCapBusiness = 7;
	public:
		void higher(double increase);
		void lower(double decrease);
		std::string getType();

		void higherBusiness(double increase);
		void lowerBusiness(double decrease);
	};

#endif
