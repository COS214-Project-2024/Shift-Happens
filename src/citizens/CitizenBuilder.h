#ifndef CITIZENBUILDER_H
#define CITIZENBUILDER_H

#include "../citizens/Citizen.h"

	class CitizenBuilder {


	public:
		virtual void addGender() = 0;

		virtual void addType() = 0;

		virtual void addStatus() = 0;

		virtual Citizen* getCitizen() = 0;
	};

#endif
