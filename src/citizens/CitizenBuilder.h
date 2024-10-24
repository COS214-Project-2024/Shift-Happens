#ifndef CITIZENBUILDER_H
#define CITIZENBUILDER_H

namespace Building_State {
	class CitizenBuilder {


	public:
		virtual void addGender() = 0;

		virtual void addType() = 0;

		virtual void addStatus() = 0;

		virtual Building_State::Citizen getCitizen() = 0;
	};
}

#endif
