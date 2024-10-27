#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenObserver.h"
#include "Director.h"

#include "../Government/Economy.h"
#include "../Government/Government.h"
#include "../Government/Public Services.h"
#include "../Government/Population.h"
#include "../Government/PublicServiceState.h"
#include "../Government/Tax.h"
#include "../Government/Policy.h"

// This is the concrete observe, but because it is an abstract class for 
// Citizens can be influenced by tax changes, population changes, public service

class Citizen : public CitizenObserver {

	protected:
		// director pointer
		Director* director;
		// attributes
		std::string Type;
		std::string Gender;
		bool Status;

		// Observer parts
		// Pointers to concrete subjects
		Economy* economy;
		Public_Services* infrastructure;
		Government* government;
		// States of the concrete subjects
		Population* observerPopulation;
		PublicServiceState* observerPublicServiceState;
		Tax* observerTax;
		std::vector<Policy*> observerPolicy;


	public:
		void update();

		std::string getType();
		std::string getGender();
		bool getStatus();
};

#endif
