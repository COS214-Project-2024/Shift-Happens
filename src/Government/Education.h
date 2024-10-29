#ifndef EDUCATION_H
#define EDUCATION_H

#include "PublicServices.h"

class Education : public Public_Services {
	private:
		PublicServiceState* InfraStructureCondition;
	public:
	Education();
    std::string getTypeOfPublicService();
    void increaseBudget();
		void decreaseBudget();
    void setPublicServiceState(PublicServiceState* newState);
		PublicServiceState* getState();
		
};

#endif