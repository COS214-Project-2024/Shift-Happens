#ifndef UTILITYBUILDING_H
#define UTILITYBUILDING_H

#include "../Building.h"

class UtilityBuilding : public Building {

	private:

		int runningCostPerHour;

	public:

		UtilityBuilding(int id,string variant, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);

		int getRunningCostPerHour();

		void setRunningCostPerHour(int runningCostPerHour);
};


#endif
