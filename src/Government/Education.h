#ifndef EDUCATION_H
#define EDUCATION_H

<<<<<<< HEAD
#include "PublicServices.h"
=======
#include "Public Services.h"
#include <memory>
>>>>>>> 4febd79fe067c95db36d8c72d93cecbf0cc9ad5a

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