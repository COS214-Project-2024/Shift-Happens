#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Tax.h"
#include "CitySubject.h"
#include "Policy.h"

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
		double PersonalTaxRate;
		Tax* TaxState;
		std::vector<Policy*> PolicyState;

	public:
		void setPersonalTaxLower(double decrease);
		void setPersonalTaxHigher(double increase);
		void addPolicy(Policy* newPolicy);
		void executePolicy();
		void setTaxState(Tax* tax);
		Tax* getTax();
		std::vector<Policy*> getPolicies();
};

#endif
