#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Tax.h"
#include "CitySubject.h"
#include "Policy.h"
#include "../Statistics.h"
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
class Government : public CitySubject {
	private:
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
		std::vector<std::shared_ptr<Policy>> PolicyState;

		/**
		 * @brief Shared pointer to a Statistics object for tracking and reporting city metrics.
		 */
		std::shared_ptr<Statistics> statistics;

	public:
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
		void addPolicy(std::shared_ptr<Policy> newPolicy);

		/**
		 * @brief Executes all current policies, applying their effects on the city's infrastructure.
		 */
		void executePolicy();

		/**
		 * @brief Removes an existing policy from the list of implemented policies.
		 * @param removePolicy A shared pointer to the Policy object to be removed.
		 */
		void removePolicy(std::shared_ptr<Policy> removePolicy);

		/**
		 * @brief Retrieves all currently implemented policies.
		 * @return A vector of shared pointers to Policy objects representing active policies.
		 */
		std::vector<std::shared_ptr<Policy>> getPolicies();

		// Budget Management
		/**
		 * @brief Retrieves the current available spending budget.
		 * @return The amount of available budget for city projects and services.
		 */
		double getAvailableSpendingBudget();
};

#endif // GOVERNMENT_H
