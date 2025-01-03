#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "CitySubject.h"
#include "Policy.h"
#include "BoostEducationPolicy.h"
#include "BoostHealthCarePolicy.h"
#include "BoostPolicePolicy.h"
#include "Education.h"
#include "Economy.h"
#include "Police.h"
#include "HealthCare.h"
#include "../Statistics.h"
// #include "../citizens/Citizen.h"
//#include "../citizens/Director.h"
#include <memory>
#include <vector>

/**
 * @class Government
 * @brief Represents the governing body of a city, managing taxation, budget allocation, policies, and public services.
 *
 * This class implements the observer pattern as a concrete subject observed by citizens. It manages tax collection, 
 * policy implementation, and allocation of the budget across various city services, such as healthcare, education, and law enforcement.
 * Government actions impact citizen satisfaction, economic growth, and overall city development.
 */

//class Statistics;
class Citizen;
class Director;
class Tax;
class Government : public CitySubject,public std::enable_shared_from_this<Government> {
	private:
		int citizenTypeCounter = 0;
		// 
		std::shared_ptr<Director> ManCitizenDirector;
		std::shared_ptr<Director> WomanCitizenDirector;
		std::shared_ptr<Director> GirlCitizenDirector;
		std::shared_ptr<Director> BoyCitizenDirector;
		// Citizen counter
		std::vector<std::shared_ptr<Citizen>> CitizenCollection;
		// shared pointers to the public services
		std::shared_ptr<Education> education;
		std::shared_ptr<Police> police;
		std::shared_ptr<HealthCare> healthcare;
		std::shared_ptr<Economy> economy;
		/**
		 * @brief Current available spending budget for government-funded services and projects.
		 */
		double AvailableSpendingBudget;

		/**
		 * @brief Tax rate applied to citizens.
		 */
		double PersonalTaxRate;

		/**
		 * @brief Tax state for citizens, representing current tax-related policies or adjustments.
		 */
		std::shared_ptr<Tax> PersonalTaxState;

		/**
		 * @brief Tax rate applied to businesses.
		 */
		double BusinessTaxRate;

		/**
		 * @brief Tax state for businesses, representing current tax-related policies or adjustments.
		 */
		std::shared_ptr<Tax> BusinessTaxState;

		/**
		 * @brief A list of currently implemented policies affecting city services and dynamics.
		 */
		std::vector<std::shared_ptr<Policy>> ImplementedPolicies;

		/**
		 * @brief A list of all the possible policies that can be implemented by the government
		*/
		std::vector<std::shared_ptr<Policy>> AvailablePolicies;

		/**
		 * @brief Shared pointer to a Statistics object for tracking and reporting city metrics.
		 */
		
		int PopulationCount;
		double CombinedSatisfaction;
	public:
		double setPersonalTaxRate(double rate);
		double setBusinessTaxRate(double rate);
		double getPersonalTaxRate();
		double getBusinessTaxRate();
		Government();

		void addCitizen(std::shared_ptr<Citizen> newCitizen);
		void addCitizen();
		void removeCitizen();
		
		double CollectPersonalTax();
		double CollectBusinessTax(int numBusinesses);
		double getIncome();

		void IncreaseAvialableBudget(double increase);

		void setPeopleCount(int count, int BusinessSatisfaction);
		int getPeopleCount();
		double getSatisfaction();
		double getUnemployment();
		double getSchoolStats();
		double getCombinedSatisfaction();

		// Tax Management
		/**
		 * @brief Lowers the personal tax rate by a specified amount.
		 * @param decrease The amount to lower the personal tax rate.
		 */
		void setPersonalTaxLower(double decrease);

		/**
		 * @brief Increases the personal tax rate by a specified amount.
		 * @param increase The amount to increase the personal tax rate.
		 */
		void setPersonalTaxHigher(double increase);

		/**
		 * @brief Sets the current state for personal tax.
		 * @param tax Shared pointer to a Tax object representing the new personal tax state.
		 */
		void setTaxState(std::shared_ptr<Tax> tax);

		/**
		 * @brief Retrieves the current state of personal tax.
		 * @return A shared pointer to the current Tax state for personal taxation.
		 */
		std::shared_ptr<Tax> getTax();

		/**
		 * @brief Lowers the business tax rate by a specified amount.
		 * @param decrease The amount to lower the business tax rate.
		 */
		void setBusinessTaxLower(double decrease);

		/**
		 * @brief Increases the business tax rate by a specified amount.
		 * @param increase The amount to increase the business tax rate.
		 */
		void setBusinessTaxHigher(double increase);

		/**
		 * @brief Sets the current state for business tax.
		 * @param tax Shared pointer to a Tax object representing the new business tax state.
		 */
		void setBusinessTaxState(std::shared_ptr<Tax> tax);

		/**
		 * @brief Retrieves the current state of business tax.
		 * @return A shared pointer to the current Tax state for business taxation.
		 */
		std::shared_ptr<Tax> getBusinessTax();

		// Policy Management
		/**
		 * @brief Adds a new policy to the list of implemented policies.
		 * @param newPolicy A shared pointer to the Policy object to be added.
		 */
		void addExecutePolicy(string policyType);

		/**
		 * @brief Converts a string to lowercase.
		 * @param str The string to convert.
		 */
		std::string toLowerCase(const std::string& str);

		/**
		 * @brief Retrieves all currently implemented policies.
		 * @return A vector of shared pointers to Policy objects representing active policies.
		 */
		std::vector<std::shared_ptr<Policy>> getCurrentPolicies();
		std::vector<std::shared_ptr<Policy>> getAvailablePolicies();

		// Budget Management
		/**
		 * @brief Retrieves the current available spending budget.
		 * @return The amount of available budget for city projects and services.
		 */
		double getAvailableSpendingBudget();

	// Accessor methods for services
    std::shared_ptr<Education> getEducation() const;
    std::shared_ptr<HealthCare> getHealthCare() const;
    std::shared_ptr<Police> getPolice() const;
};

#endif // GOVERNMENT_H