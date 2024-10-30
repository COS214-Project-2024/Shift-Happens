#ifndef EDUCATION_H
#define EDUCATION_H

#include <memory>	
#include "PublicServices.h"

/**
 * @class Education
 * @brief This class implements the PublicServices class and represents the education services provided to citizens.
 *
 * The Education class manages the state and budget of the educational infrastructure within the public service system.
 */
class Education : public Public_Services {
	private:
		/**
		 * @brief Infrastructure condition is a shared pointer to a PublicServiceState object representing the current state of Education infrastructure.
		 */
		std::shared_ptr<PublicServiceState> InfraStructureCondition;

	public:
		/**
		 * @brief Constructor for the Education class.
		 */
		Education();

		/**
		 * @brief Returns the type of public service.
		 * @return A string representing the public service type, e.g., "Education".
		 */
		std::string getTypeOfPublicService();

		/**
		 * @brief Increases the budget allocated to education services.
		 */
		void increaseBudget();

		/**
		 * @brief Decreases the budget allocated to education services.
		 */
		void decreaseBudget();

		/**
		 * @brief Sets the state of the public service infrastructure.
		 * @param newState A shared pointer to the new PublicServiceState, updating the current state.
		 */
		void setPublicServiceState(std::shared_ptr<PublicServiceState> newState);

		/**
		 * @brief Returns the current state of the education infrastructure.
		 * @return A shared pointer to the current PublicServiceState.
		 */
		std::shared_ptr<PublicServiceState> getState();
};

#endif // EDUCATION_H
