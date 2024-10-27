#ifndef PUBLIC SERVICES_H
#define PUBLIC SERVICES_H

#include "CitySubject.h"
#include "PublicServiceState.h"

#include <iostream>

// Concrete subject in observer pattern
// Context in state pattern

class Public_Services : public CitySubject {
	private:
		PublicServiceState* InfraStructureCondition;
	public:
		void DelegateFunds();
		void setPublicServiceState(PublicServiceState* newState);
		PublicServiceState* getState();

};

#endif
