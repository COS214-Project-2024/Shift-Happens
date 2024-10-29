#ifndef GIRLBUILDER_H
#define GIRLBUILDER_H


#include "CitizenBuilder.h"
#include "Girl.h"

	class GirlBuilder : public CitizenBuilder {
	private:
		std::shared_ptr<Girl> Girl;
	public:

		void addGender();

		void addType();

		void addStatus();

		std::shared_ptr<Citizen> getCitizen();
	};


#endif
