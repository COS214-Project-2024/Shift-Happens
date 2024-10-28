#ifndef WOMAN_H
#define WOMAN_H

#include "Citizen.h"
#include <iostream>

	class Woman : public Citizen {

	private:
		std::string Type;
		std::string Gender;
		bool Employment;

	public:
		std::string getType();
		std::string getGender();
		bool getStatus();
		void setType(std::string type);
		void setGender(std::string gender);
		void setStatus(bool status);

		void setEmployment(bool status);
	};

#endif
