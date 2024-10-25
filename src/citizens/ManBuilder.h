#ifndef MANBUILDER_H
#define MANBUILDER_H

#include "Man.h"
#include "CitizenBuilder.h"

namespace Building_State {
	class ManBuilder : public Building_State::CitizenBuilder {
	private:
		Man* Man;
	public:

		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};
}

#endif
