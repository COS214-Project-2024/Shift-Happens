#ifndef STANDARD_H
#define STANDARD_H

#include "PublicServiceState.h"
#include "Modern.h"
#include "Outdated.h"

/**
 * @class Standard
 * @brief Concrete state class representing the "Standard" quality level for a public service.
 *
 * The `Standard` class defines a medium-quality state for a public service, indicating an acceptable
 * level of infrastructure and funding. This state represents a service that sufficiently meets
 * citizen needs, without the additional resources or quality associated with the "Modern" state
 * or the deficiencies of the "Outdated" state. The service can transition to a different state 
 * based on budget changes.
 */

class Modern;
class Outdated;
class Standard : public PublicServiceState {
	private:
		/**
		 * @brief Upper threshold for the "Standard" state.
		 *
		 * `StandardHighCap` defines the maximum budget limit for the "Standard" state.
		 * If the budget surpasses this cap, the public service will transition to the "Modern" state,
		 * reflecting an upgrade in service quality.
		 */
		double StandardHighCap = 1000;

		/**
		 * @brief Lower threshold for the "Standard" state.
		 *
		 * `StandardLowerCap` sets the minimum budget limit for maintaining the "Standard" state.
		 * If the budget falls below this threshold, the public service will transition to the "Outdated" state,
		 * indicating a decline in service quality.
		 */
		double StandardLowerCap = 100;

	public:
		/**
		 * @brief Constructor for the Standard state.
		 *
		 * Initializes the Standard state, setting default conditions for managing budget changes
		 * and maintaining mid-level service quality.
		 */
		Standard();
		Standard(std::shared_ptr<Public_Services> PS);
		Standard(std::shared_ptr<Public_Services> PS, double Budget);

		/**
		 * @brief Increases the running budget and checks if the state should upgrade.
		 * @param increase The amount to add to the current budget.
		 *
		 * This method raises the current budget and evaluates whether the public service
		 * should transition from the "Standard" state to the "Modern" state based on
		 * the updated budget level.
		 */
		void increaseBudget(double increase);

		/**
		 * @brief Decreases the running budget and checks if the state should downgrade.
		 * @param decrease The amount to subtract from the current budget.
		 *
		 * This method reduces the current budget and determines if the public service should
		 * transition to the "Outdated" state based on the new budget level.
		 */
		void decreaseBudget(double decrease);

		/**
		 * @brief Returns the type of service quality as a string.
		 * @return A string identifying the service as in the "Standard" state.
		 *
		 * Provides a descriptive string to identify the quality level of the service,
		 * which, in this case, is the "Standard" quality level.
		 */
		std::string getType();
};

#endif // STANDARD_H
