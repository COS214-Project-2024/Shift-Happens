#ifndef STANDARD_H
#define STANDARD_H

#include "PublicServiceState.h"
#include "Modern.h"
#include "Outdated.h"

class Standard : public PublicServiceState {
	private:
		double StandardHighCap = 1000;
		double StandardLowerCap = 100;
	public:
		void increaseBudget(double increase);
		void descreaseBudget(double decrease);
};


#endif
