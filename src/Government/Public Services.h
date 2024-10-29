#ifndef PUBLIC SERVICES_H
#define PUBLIC SERVICES_H

#include "CitySubject.h"
#include "PublicServiceState.h"

#include <iostream>

// Concrete subject in observer pattern
// Context in state pattern

class Public_Services : public CitySubject {
	public:
		// template method
		void DelegateFunds();

		virtual void setPublicServiceState(PublicServiceState* newState)=0;
		virtual PublicServiceState* getState()=0;
		virtual std::string getTypeOfPublicService() =0;
		virtual void increaseBudget() =0;
		virtual void decreaseBudget()=0;
};

#endif
