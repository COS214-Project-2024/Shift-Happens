#ifndef MAN_H
#define MAN_H

#include "Citizen.h"
#include <iostream>

	class Man : public Citizen {

	private:
		std::string Type;
		std::string Gender;
		bool Employment;

	public:
		void setType(std::string type);

		void setGender(std::string gender);

		void setEmployment(bool status);
	};

#endif
