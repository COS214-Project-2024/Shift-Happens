#ifndef PUBLICSERVICESTATE_H
#define PUBLICSERVICESTATE_H

#include <string>
#include "PublicServices.h"


class Public_Services; // forward declaration because of circular dependency
class PublicServiceState {
	protected:
		Public_Services* publicServices;
		double RunningBudget;
	public:
		virtual void increaseBudget(double increase) = 0;
		virtual void descreaseBudget(double decrease) = 0;
		virtual std::string getType() = 0;
};


#endif
