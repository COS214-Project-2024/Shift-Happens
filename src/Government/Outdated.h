#ifndef OUTDATED_H
#define OUTDATED_H

#include "PublicServiceState.h"
#include "Standard.h"

/**
 * @class Outdated
 * @brief Concrete state class representing the "Outdated" quality level for a public service.
 *
 * The `Outdated` class defines a low-quality state for a public service, indicating
 * inadequate resources, infrastructure, or funding. This state represents a public service
 * that operates at a minimum level, often struggling to meet citizen needs effectively.
 * The service can transition to a higher quality state, such as "Standard," if the budget increases.
 */
class Outdated : public PublicServiceState {
	private:
		/**
		 * @brief Budget threshold to transition out of the "Outdated" state.
		 *
		 * `OutdatedHighCap` defines the maximum budget limit for this state. If the running budget
		 * exceeds this cap, the public service will transition to the "Standard" state,
		 * signifying an improvement in service quality.
		 */
		double OutdatedHighCap = 100;

	public:
		/**
		 * @brief Constructor for the Outdated state.
		 *
		 * Initializes the Outdated state, preparing it to manage budget changes and
		 * reflect a minimal quality of service.
		 */
		Outdated();

		/**
		 * @brief Increases the running budget and checks if the state should upgrade.
		 * @param increase The amount to add to the current budget.
		 *
		 * This method adjusts the current budget upward and evaluates whether the public
		 * service should transition from the "Outdated" state to the "Standard" state
		 * based on the new budget level.
		 */
		void increaseBudget(double increase);

		/**
		 * @brief Decreases the running budget, maintaining the "Outdated" state.
		 * @param decrease The amount to subtract from the current budget.
		 *
		 * Allows reduction in the budget while retaining the "Outdated" state, as further
		 * decreases in budget typically do not affect the state's quality level.
		 */
		void decreaseBudget(double decrease);

		/**
		 * @brief Returns the type of service quality as a string.
		 * @return A string identifying the service as in the "Outdated" state.
		 *
		 * Provides a descriptive string to identify the quality level of the service,
		 * which, in this case, indicates minimal service quality.
		 */
		std::string getType();
};

#endif // OUTDATED_H
