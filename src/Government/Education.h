#ifndef EDUCATION_H
#define EDUCATION_H

#include <memory>	
#include "PublicServices.h"


class Education : public Public_Services {
	private:
		std::shared_ptr<PublicServiceState> InfraStructureCondition;
	public:
	Education();
    std::string getTypeOfPublicService();
    void increaseBudget();
		void decreaseBudget();
    void setPublicServiceState(std::shared_ptr<PublicServiceState> newState);
		std::shared_ptr<PublicServiceState> getState();
		
};

#endif