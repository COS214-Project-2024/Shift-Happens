#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenObserver.h"
#include "Director.h"

class Citizen : public CitizenObserver {

	private:
		// director pointer
		Director* director;
		// attributes
		std::string Type;
		std::string Gender;
		bool Status;
		//
		Economy* economy;
		Infrastructural* infrastructure;
		Government* government;

	public:
		Citizen(){
			director = new Director;
			director->construct();

			Citizen* temp = ((CitizenBuilder*) director)->getCitizen();

		}

		std::string getType();
		std::string getGender();
		bool getStatus();
};

#endif
