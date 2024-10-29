#ifndef PUBLICSERVICESTATE_H
#define PUBLICSERVICESTATE_H

#include "Public Services.h"


class Public_Services; // forward declaration because of circular dependency
class PublicServiceState {
	protected:
		std::shared_ptr<Public_Services> publicServices;
		double RunningBudget;
	public:
		virtual void increaseBudget(double increase) = 0;
		virtual void descreaseBudget(double decrease) = 0;
		virtual std::string getType() = 0;
};


#endif
