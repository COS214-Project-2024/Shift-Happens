#ifndef BOYBUILDER_H
#define BOYBUILDER_H\

#include "CitizenBuilder.h"
#include "Boy.h"

namespace Building_State {
	class BoyBuilder : public Building_State::CitizenBuilder {
		private:
		Boy* Boy;
	public:
		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};
}

#endif
