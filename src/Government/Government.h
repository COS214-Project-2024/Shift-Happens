#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Tax.h"
#include "CitySubject.h"
#include "Policy.h"
#include "Statistics.h" // for keeping track of stats via the statistics object and sending the correct data to the statistics object
// Concrete subject in observer pattern
// Context in state pattern

/*
	Spec wants us to :
	- Set and collect taxes from citizens and businesses, Taxation
	- Budget allocation for various city services and projects, Budget
	- Implementing laws and regulations that impact city dynamics, Policies
	- Managing healthcare, education, law enforcement, and more, Public services
	- Government decisions should influence citizen satisfaction, economic growth, and overall
 		city development
*/

/*
	Done:
	 - set taxes
	 - budget allocation for public services
*/

/*
Government has tax rates and policies
Government has a city budget
*/ 

class Government : public CitySubject {
	private:
		// person tax
		double PersonalTaxRate;
		Tax* PersonalTaxState;
		// busines tax
		double BusinessTaxRate;
		Tax* BusinessTaxState;

		std::vector<Policy*> PolicyState;
		Statistics* statistics; // for keeping track of stats via the statistics object and sending the correct data to the statistics object

	public:
		// Taxes
		void setPersonalTaxLower(double decrease);
		void setPersonalTaxHigher(double increase);
		void setTaxState(Tax* tax);
		Tax* getTax();

		void setBusinessTaxLower(double decrease);
		void setBusinessTaxHigher(double increase);
		void setBusinessTaxState(Tax* tax);
		Tax* getBusinessTax();
		// Policies
		void addPolicy(Policy* newPolicy);
		void executePolicy();
		std::vector<Policy*> getPolicies();
};

#endif
