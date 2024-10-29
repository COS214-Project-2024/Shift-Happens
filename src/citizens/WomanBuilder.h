#ifndef WOMANBUILDER_H
#define WOMANBUILDER_H

#include "CitizenBuilder.h"
#include "Woman.h"

	class WomanBuilder : public CitizenBuilder {
	private:
		std::shared_ptr<Woman> Woman;
	public:

		void addGender();

		void addType();

		void addStatus();

		std::shared_ptr<Citizen> getCitizen();
	};

#endif

