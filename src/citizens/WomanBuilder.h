#ifndef WOMANBUILDER_H
#define WOMANBUILDER_H

#include "CitizenBuilder.h"
#include "Woman.h"

	class WomanBuilder : public CitizenBuilder {
	private:
		Woman* Woman;
	public:

		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};

#endif

