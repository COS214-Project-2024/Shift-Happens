#ifndef HEALTHCARE_H
#define HEALTHCARE_H

#include "PublicServices.h"
#include <memory>

/**
 * @class HealthCare
 * @brief Represents the healthcare services provided to citizens as part of public services.
 *
 * The HealthCare class manages the state and budget of healthcare infrastructure within the public service system.
 */
class HealthCare : public Public_Services {
	private:
		/**
		 * @brief Infrastructure condition is a shared pointer to a PublicServiceState object representing the current state of healthcare infrastructure.
		 */
		std::shared_ptr<PublicServiceState> InfraStructureCondition;

	public:
		/**
		 * @brief Returns the type of public service.
		 * @return A string representing the type of public service, e.g., "HealthCare".
		 */
		std::string getTypeOfPublicService();

		/**
		 * @brief Increases the budget allocated to healthcare services.
		 */
		void increaseBudget();

		/**
		 * @brief Decreases the budget allocated to healthcare services.
		 */
		void decreaseBudget();

		/**
		 * @brief Sets the state of the healthcare infrastructure.
		 * @param newState A shared pointer to the new PublicServiceState, updating the current state.
		 */
		void setPublicServiceState(std::shared_ptr<PublicServiceState> newState);

		/**
		 * @brief Returns the current state of the healthcare infrastructure.
		 * @return A shared pointer to the current PublicServiceState.
		 */
		std::shared_ptr<PublicServiceState> getState();
};

#endif // HEALTHCARE_H
