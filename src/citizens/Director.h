#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "CitizenBuilder.h"

#include <memory>

class Director {
	private:
		std::shared_ptr<CitizenBuilder> Builder;

	public:
		void construct();
};


#endif
