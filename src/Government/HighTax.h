#ifndef HIGHTAX_H
#define HIGHTAX_H

#include "StandardTax.h"

	class HighTax : public Tax {

	public:
		void higher();
		void lower();
		std::string getType();
	};

#endif
