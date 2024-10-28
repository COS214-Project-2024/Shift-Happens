#ifndef LOWTAX_H
#define LOWTAX_H

#include "StandardTax.h"
class LowTax : public Tax {
	private:
		int LowTHighCap = 20;
	public:
		void higher(double increase);
		void lower(double decrease);
		std::string getType();
	};

#endif
