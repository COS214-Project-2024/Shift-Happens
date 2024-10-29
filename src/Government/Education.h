#ifndef EDUCATION_H
#define EDUCATION_H

#include "Public Services.h"

class Education : public Public_Services {
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