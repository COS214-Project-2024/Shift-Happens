#ifndef UTILITYBUILDING_H
#define UTILITYBUILDING_H

#include "../Building.h"
class UtilityBuilding : public Building {

	public:
		int runningCostPerHour;

		int getRunningCostPerHour();

		void setRunningCostPerHour(int runningCostPerHour);
};


#endif
