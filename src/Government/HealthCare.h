#ifndef HEALTHCARE_H
#define HEALTHCARE_H

#include "Public Services.h"

class HealthCare : public Public_Services {
	private:
		std::shared_ptr<PublicServiceState> InfraStructureCondition;
	public:
		std::string getTypeOfPublicService();
    void increaseBudget();
		void decreaseBudget();
    void setPublicServiceState(std::shared_ptr<PublicServiceState> newState);
		std::shared_ptr<PublicServiceState> getState();
};

#endif