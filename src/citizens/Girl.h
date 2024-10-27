#ifndef GIRL_H
#define GIRL_H

#include "Citizen.h"

	class Girl : public Citizen {

	private:
		std::string Type;
		std::string Gender;
		bool School;

	public:
		std::string getType();
		std::string getGender();
		bool getStatus();
		void setType(std::string type);
		void setGender(std::string gender);
		void setStatus(bool status);

		void setSchool(bool status);
	};

#endif
