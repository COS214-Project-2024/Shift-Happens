#ifndef GIRLBUILDER_H
#define GIRLBUILDER_H

namespace Building_State {
	class GirlBuilder : Building_State::CitizenBuilder {

	public:
		Girl* Girl;

		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};
}

#endif
