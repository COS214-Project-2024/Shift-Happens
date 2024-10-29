#ifndef POLICE_H
#define POLICE_H

#include "PublicServices.h"

class Police : public Public_Services {
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