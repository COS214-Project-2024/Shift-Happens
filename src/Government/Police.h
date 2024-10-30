#ifndef POLICE_H
#define POLICE_H

#include "PublicServices.h"
#include <string>
#include <memory>

/**
 * @class Police
 * @brief Represents the police services provided to citizens as part of public services.
 *
 * The Police class manages the state and budget of police infrastructure within the public service system.
 */
class Police : public Public_Services {
	private:
		/**
		 * @brief Infrastructure condition is a shared pointer to a PublicServiceState object representing the current state of police infrastructure.
		 */
		std::shared_ptr<PublicServiceState> InfraStructureCondition;

	public:
		/**
		 * @brief Returns the type of public service.
		 * @return A string representing the type of public service, e.g., "Police".
		 */
		std::string getTypeOfPublicService();

		/**
		 * @brief Increases the budget allocated to police services.
		 */
		void increaseBudget();

		/**
		 * @brief Decreases the budget allocated to police services.
		 */
		void decreaseBudget();

		/**
		 * @brief Sets the state of the police infrastructure.
		 * @param newState A shared pointer to the new PublicServiceState, updating the current state.
		 */
		void setPublicServiceState(std::shared_ptr<PublicServiceState> newState);

		/**
		 * @brief Returns the current state of the police infrastructure.
		 * @return A shared pointer to the current PublicServiceState.
		 */
		std::shared_ptr<PublicServiceState> getState();
};

#endif // POLICE_H
