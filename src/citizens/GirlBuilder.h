#ifndef GIRLBUILDER_H
#define GIRLBUILDER_H


#include "CitizenBuilder.h"
#include "Girl.h"

	class GirlBuilder : public CitizenBuilder {
	private:
		Girl* Girl;
	public:

		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};


#endif
