#ifndef MODERN_H
#define MODERN_H

#include "PublicServiceState.h"
#include "Standard.h"

class Modern : public PublicServiceState {
	private:
		double ModernLowerCap = 1000;
	public:
		void increaseBudget(double increase);
		void descreaseBudget(double decrease);
};


#endif
