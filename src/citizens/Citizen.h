#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenObserver.h"
#include "Director.h"

#include <memory>

#include "../Government/Economy.h"
#include "../Government/Government.h"
#include "../Government/Police.h"
#include "../Government/HealthCare.h"
#include "../Government/Education.h"
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
		std::shared_ptr<Director> director;
		// attributes
		double SatisfactionScore; // highest satisfaction score is a 100
		std::string Type;
		std::string Gender;
		bool Status;

		// Observer parts
		// Pointers to concrete subjects
		std::shared_ptr<Economy> economy;
		// have more than one type of public service
		std::shared_ptr<Public_Services> police;
		std::shared_ptr<Public_Services> education;
		std::shared_ptr<Public_Services> healthcare;
		std::shared_ptr<Government> government;
		// States of the concrete subjects
		std::shared_ptr<Population> observerPopulation;
		std::shared_ptr<PublicServiceState> observerPolice;
		std::shared_ptr<PublicServiceState> observerEducation;
		std::shared_ptr<PublicServiceState> observerHealthcare;
		std::shared_ptr<Tax> observerTax;
		
		std::shared_ptr<Statistics> observerStatistics;



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
