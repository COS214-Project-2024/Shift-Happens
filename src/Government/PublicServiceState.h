#ifndef PUBLICSERVICESTATE_H
#define PUBLICSERVICESTATE_H

#include <string>
#include "PublicServices.h"

/**
 * @class PublicServiceState
 * @brief Abstract base class representing the quality state of a public service.
 *
 * The `PublicServiceState` class defines the interface for different quality states
 * that a public service, such as education, healthcare, or law enforcement, can have. 
 * Each state manages the current budget spent on the service, allowing derived classes
 * to implement specific behaviors based on the budget and the quality of service provided.
 */
//class Public_Services; // Forward declaration to resolve circular dependency

class PublicServiceState {
	protected:
		/**
		 * @brief Pointer to the associated public service instance.
		 *
		 * This pointer allows the `PublicServiceState` to manage or change the state
		 * of the associated `Public_Services` object as necessary, depending on budget
		 * adjustments or quality requirements.
		 */
		std::shared_ptr<Public_Services> publicServices;

		/**
		 * @brief Tracks the total budget allocated to the public service.
		 *
		 * The `RunningBudget` reflects the current expenditure for the associated
		 * public service, enabling state classes to manage and track budget changes.
		 */
		double RunningBudget;

	public:
		PublicServiceState();
		PublicServiceState(std::shared_ptr<Public_Services> PS);
		/**
		 * @brief Increases the current running budget for the public service.
		 * @param increase The amount to add to the current budget.
		 *
		 * This method updates the budget for the service to support quality improvements
		 * or expansions, as required by the service's current state.
		 */
		virtual void increaseBudget(double increase) = 0;

		/**
		 * @brief Decreases the current running budget for the public service.
		 * @param decrease The amount to subtract from the current budget.
		 *
		 * This method reduces the budget allocation for the service, which may impact
		 * the quality or availability of the service, depending on the state's rules.
		 */
		virtual void decreaseBudget(double decrease) = 0;

		/**
		 * @brief Returns a string representing the type of service quality state.
		 * @return A string describing the state type, such as "Modern Service" or "Basic Service."
		 *
		 * This method allows clients to query the current state of the public service
		 * in a descriptive format, providing insights into service quality.
		 */
		virtual std::string getType() = 0;
		double getRunningBudget();
		void setPublicService(std::shared_ptr<Public_Services> publicService);
};

#endif // PUBLICSERVICESTATE_H