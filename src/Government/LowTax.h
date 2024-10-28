#ifndef LOWTAX_H
#define LOWTAX_H

#include "StandardTax.h"
	class LowTax : public Tax {


	public:
		void higher();
		void lower();
		std::string getType();
	};

#endif
