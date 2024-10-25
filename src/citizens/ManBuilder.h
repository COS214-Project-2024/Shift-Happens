#ifndef MANBUILDER_H
#define MANBUILDER_H

#include "Man.h"
#include "CitizenBuilder.h"

	class ManBuilder : public CitizenBuilder {
	private:
		Man* Man;
	public:

		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};

#endif
