#ifndef PUBLICSERVICESTATE_H
#define PUBLICSERVICESTATE_H

#include "Public Services.h"

class PublicServiceState {
	protected:
		Public_Services* publicServices;
		double RunningBudget;
	public:
		virtual void increaseBudget(double increase) = 0;
		virtual void descreaseBudget(double decrease) = 0;
};


#endif
