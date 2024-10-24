#ifndef BOYBUILDER_H
#define BOYBUILDER_H

namespace Building_State {
	class BoyBuilder : Building_State::CitizenBuilder {

	public:
		Boy* Boy;

		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};
}

#endif
