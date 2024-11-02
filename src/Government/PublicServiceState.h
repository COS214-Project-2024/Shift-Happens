#ifndef PUBLICSERVICESTATE_H
#define PUBLICSERVICESTATE_H

#include "Public Services.h"

class PublicServiceState {
	protected:
		Public_Services* publicServices;
		double RunningBudget;

	public:
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
