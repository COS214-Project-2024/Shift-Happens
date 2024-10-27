#include "UtilityBuilding.h"

UtilityBuilding::UtilityBuilding(int id,string variant, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand)
: Building(id,1, 1, -1, -1, variant, "Utility",constructionPrice,wasteProduced,sewageProduced,electricityDemand,waterDemand)
{
	this->runningCostPerHour = 0;
}

int UtilityBuilding::getRunningCostPerHour() {
	return this->runningCostPerHour;
}

void UtilityBuilding::setRunningCostPerHour(int runningCostPerHour) {
	this->runningCostPerHour = runningCostPerHour;
}
