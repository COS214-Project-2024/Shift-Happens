#ifndef POLICE_H
#define POLICE_H

#include "PublicServices.h"
#include <string>
#include <memory>

class Police : public Public_Services {
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