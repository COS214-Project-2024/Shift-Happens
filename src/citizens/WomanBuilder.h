#ifndef WOMANBUILDER_H
#define WOMANBUILDER_H

#include "CitizenBuilder.h"
#include "Woman.h"

namespace Building_State {
	class WomanBuilder : public Building_State::CitizenBuilder {
	private:
		Woman* Woman;
	public:

		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};
}

#endif

