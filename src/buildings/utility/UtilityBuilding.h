#ifndef UTILITYBUILDING_H
#define UTILITYBUILDING_H

#include "../Building.h"

class UtilityBuilding : public Building {

	public:

		UtilityBuilding(int id,string variant, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);

		int runningCostPerHour;

		int getRunningCostPerHour();

		void setRunningCostPerHour(int runningCostPerHour);
};


#endif
