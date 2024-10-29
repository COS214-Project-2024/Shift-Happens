#ifndef MANBUILDER_H
#define MANBUILDER_H

#include "Man.h"
#include "CitizenBuilder.h"

	class ManBuilder : public CitizenBuilder {
	private:
		std::shared_ptr<Man> Man;
	public:

		void addGender();

		void addType();

		void addStatus();

		std::shared_ptr<Citizen> getCitizen();
	};

#endif
