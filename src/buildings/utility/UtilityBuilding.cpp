#include "UtilityBuilding.h"

int Building_State::UtilityBuilding::getRunningCostPerHour() {
	return this->runningCostPerHour;
}

void Building_State::UtilityBuilding::setRunningCostPerHour(int runningCostPerHour) {
	this->runningCostPerHour = runningCostPerHour;
}
