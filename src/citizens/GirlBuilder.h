#ifndef GIRLBUILDER_H
#define GIRLBUILDER_H


#include "CitizenBuilder.h"
#include "Girl.h"

namespace Building_State {
	class GirlBuilder : public Building_State::CitizenBuilder {
	private:
		Girl* Girl;
	public:

		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};
}

#endif
