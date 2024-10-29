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
#include "../Statistics.h" // for keeping track of stats via the statistics object and sending the correct data to the statistics object

// This is the concrete observe, but because it is an abstract class for 
// Citizens can be influenced by tax changes, population changes, public service

class Citizen : public CitizenObserver {

	protected:
		// director pointer
		Director* director;
		// attributes
		double SatisfactionScore; // highest satisfaction score is a 100
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
		Statistics* observerStatistics;



	public:
		// observer function
		void update();

		// basics
		virtual std::string getType() =0;
		virtual std::string getGender()=0;
		virtual bool getStatus()=0;
		virtual void setType(std::string type)=0;
		virtual void setGender(std::string gender)=0;
		virtual void setStatus(bool status)=0;

		// 
		void CalculateSatisfaction();
		double getSatisfactionScore();
		void increaseSatisfaction(double increase);
		void decreaseSatisfaction(double decrease);
};

#endif
