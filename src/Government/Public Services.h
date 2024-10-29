#ifndef PUBLICSERVICES_H
#define PUBLICSERVICES_H

#include "CitySubject.h"
#include "PublicServiceState.h"

#include <iostream>

// Concrete subject in observer pattern
// Context in state pattern

class PublicServiceState; // forward declaration because of circular dependency
class Public_Services : public CitySubject {
	public:
		// template method
		void DelegateFunds();

		virtual void setPublicServiceState(std::shared_ptr<PublicServiceState> newState)=0;
		virtual std::shared_ptr<PublicServiceState> getState()=0;
		virtual std::string getTypeOfPublicService() =0;
		virtual void increaseBudget() =0;
		virtual void decreaseBudget()=0;
};

#endif
