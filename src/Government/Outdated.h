#ifndef OUTDATED_H
#define OUTDATED_H

#include "PublicServiceState.h"
#include "Standard.h"

class Outdated : public PublicServiceState {
	private:
		double OutdatedHighCap = 100;
	public:
		void increaseBudget(double increase);
		void descreaseBudget(double decrease);
};


#endif
