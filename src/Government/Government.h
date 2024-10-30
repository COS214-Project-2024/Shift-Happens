#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Tax.h"
#include "CitySubject.h"
#include "Policy.h"
#include "../Statistics.h" // for keeping track of stats via the statistics object and sending the correct data to the statistics object
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
	 - set taxes for citizens and businesses
	 - 
*/

/*
Government has tax rates and policies
Government has a city budget: can be used for public services, boosting ecocmic growth
*/ 

/**
 * @class Government
 * @brief This is the government class, it is also a concrete subject being observerd by the citizens. This class manages taxes, it changes tax rates for businesses and citizens and collects it from them. The government also implements different polcies. It can add and remove policies. It manages public services like police, education and healthcare
*/

class Government : public CitySubject {
	private:
		// Budget	
		/**
		 * @brief Keep track of the current Budget of the government
		*/
		double AvailableSpendingBudget;
		// person tax
		/**
		 * Keeps track of the tax rate for people
		*/
		double PersonalTaxRate;
		/**
		 * Keeps a shared pointer to a tax state for people
		*/
		std::shared_ptr<Tax> PersonalTaxState;
		// busines tax
		/**
		 * Keeps the current rate of the Busniess tax
		*/
		double BusinessTaxRate;
		/**
		 * Keeps a shared pointer to a tax state for business
		*/
		std::shared_ptr<Tax> BusinessTaxState;
		// Policies
		/**
		 * vector of shared pointers to Policy objects. This vector stores the current implemented policies
		*/
		std::vector<std::shared_ptr<Policy>> PolicyState;
		// Stats
		std::shared_ptr<Statistics> statistics; // for keeping track of stats via the statistics object and sending the correct data to the statistics object

	public:
		// Taxes
		/**
		 * @brief for method to decrease the personal tax
		*/
		void setPersonalTaxLower(double decrease);
		/**
		 * @brief for method to increase the personal Tax
		*/
		void setPersonalTaxHigher(double increase);
		/**
		 * Method to set the tax state of the personal tax
		*/
		void setTaxState(std::shared_ptr<Tax> tax);
		/**
		 * Returns the current state of the personal tax
		*/
		std::shared_ptr<Tax> getTax();

		/**
		 * method to decrease the business tax as the government sees fit
		*/
		void setBusinessTaxLower(double decrease);
		/**
		 * method to increase the business tax as
		*/
		void setBusinessTaxHigher(double increase);
		/**
		 * method to set the state of the business tax
		*/
		void setBusinessTaxState(std::shared_ptr<Tax> tax);
		/**
		 * method that returns the state of the business tax (High, standard , low)
		*/
		std::shared_ptr<Tax> getBusinessTax();

		// Policies
		void addPolicy(std::shared_ptr<Policy> newPolicy);
		void executePolicy();
		void removePolicy(std::shared_ptr<Policy> removePolicy);
		std::vector<std::shared_ptr<Policy>> getPolicies();

		// basics
		double getAvailableSpendingBudget();
};

#endif
