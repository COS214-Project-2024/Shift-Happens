#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "CitizenBuilder.h"

	class Director {

	private:
		CitizenBuilder* Builder;

	public:
		void construct();
	};


#endif
