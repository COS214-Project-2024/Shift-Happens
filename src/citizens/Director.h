#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "CitizenBuilder.h"

namespace Building_State {
	class Director {

	private:
		Building_State::CitizenBuilder* Builder;

	public:
		void construct();
	};
}

#endif
