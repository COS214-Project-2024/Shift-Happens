#ifndef STANDARDTAX_H
#define STANDARDTAX_H

#include "Tax.h"
#include "HighTax.h"
#include "LowTax.h"

	class StandardTax : public Tax {


	public:
		void higher();

		void lower();
	};

#endif
