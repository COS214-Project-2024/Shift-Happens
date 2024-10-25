#ifndef WOMAN_H
#define WOMAN_H

#include "Citizen.h"
#include <iostream>

namespace Building_State {
	class Woman : public Building_State::Citizen {

	private:
		std::string Type;
		std::string Gender;
		bool Employment;

	public:
		void setType(std::string type);

		void setGender(std::string gender);

		void setEmployment(bool status);
	};
}

#endif
