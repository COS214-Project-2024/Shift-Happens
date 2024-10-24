#ifndef MANBUILDER_H
#define MANBUILDER_H

namespace Building_State {
	class ManBuilder : Building_State::CitizenBuilder {

	public:
		Man* Man;

		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};
}

#endif
