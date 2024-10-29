#ifndef EDUCATION_H
#define EDUCATION_H

#include "Public Services.h"
#include <memory>

class Education : public Public_Services {
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