#ifndef PUBLIC SERVICES_H
#define PUBLIC SERVICES_H

#include "CitySubject.h"
#include "PublicServiceState.h"

#include <iostream>

class Public_Services : public CitySubject {
	private:
		PublicServiceState* InfraStructureCondition;
	public:
		void DelegateFunds();
		void setPublicServiceState(PublicServiceState* newState);

};

#endif
