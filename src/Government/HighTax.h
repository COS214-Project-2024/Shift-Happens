#ifndef HIGHTAX_H
#define HIGHTAX_H

#include "StandardTax.h"

class HighTax : public Tax {
	private:
		int HighTLowCap = 35;
	public:
		void higher(double increase);
		void lower(double decrease);
		std::string getType();

		void higherBusiness(double increase);
		void lowerBusiness(double decrease);
};

#endif
