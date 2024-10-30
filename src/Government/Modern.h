#ifndef MODERN_H
#define MODERN_H

#include "PublicServiceState.h"
#include "Standard.h"

/**
 * @class Modern
 * @brief Concrete state class representing the "Modern" quality level for a public service.
 *
 * The `Modern` class defines the highest quality state that a public service can achieve,
 * signifying optimal infrastructure, resources, and citizen satisfaction. When the service's
 * budget exceeds a specified threshold, it enters this "Modern" state. The state is downgraded
 * if the running budget falls below a specified cap.
 */
class Modern : public PublicServiceState {
	private:
		/**
		 * @brief Budget threshold to maintain the "Modern" state.
		 *
		 * `ModernLowerCap` defines the minimum budget required to sustain the "Modern"
		 * quality. If the running budget drops below this cap, the service transitions
		 * to the "Standard" state, representing a lower quality of service.
		 */
		double ModernLowerCap = 1000;

	public:
		/**
		 * @brief Constructor for the Modern state.
		 *
		 * Initializes the Modern state, preparing it to manage budget adjustments and
		 * ensure the highest quality of service as long as the budget remains sufficient.
		 */
		Modern();

		/**
		 * @brief Increases the running budget, maintaining the "Modern" quality state.
		 * @param increase The amount to add to the current budget.
		 *
		 * This method adjusts the current budget upward, potentially reinforcing the
		 * "Modern" state by allowing for additional resources and enhancements to the
		 * public service.
		 */
		void increaseBudget(double increase);

		/**
		 * @brief Decreases the running budget and checks if the state should change.
		 * @param decrease The amount to subtract from the current budget.
		 *
		 * If the budget falls below `ModernLowerCap`, the public service state
		 * transitions to "Standard" to reflect reduced resources and quality.
		 */
		void decreaseBudget(double decrease);

		/**
		 * @brief Returns the type of service quality as a string.
		 * @return A string identifying the service as in the "Modern" state.
		 *
		 * Provides a descriptive string to identify the quality level of the service,
		 * which, in this case, signifies the highest attainable quality.
		 */
		std::string getType();
};

#endif // MODERN_H
