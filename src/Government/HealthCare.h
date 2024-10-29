#ifndef HEALTHCARE_H
#define HEALTHCARE_H

#include "PublicServices.h"

class HealthCare : public Public_Services {
	private:
		PublicServiceState* InfraStructureCondition;
	public:
		std::string getTypeOfPublicService();
    void increaseBudget();
		void decreaseBudget();
    void setPublicServiceState(PublicServiceState* newState);
		PublicServiceState* getState();
};

#endif