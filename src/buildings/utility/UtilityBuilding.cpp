#include "UtilityBuilding.h"
#include <iostream>

UtilityBuilding::UtilityBuilding(int id,string variant, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand)
    : Building(id, 1, 1, -1, -1, variant, "Utility", constructionPrice, wasteProduced, sewageProduced, electricityDemand, waterDemand), runningCostPerHour(100) {}
// {
// 	this->runningCostPerHour = 0;
// }

int UtilityBuilding::getRunningCostPerHour() {
	return this->runningCostPerHour;
}

void UtilityBuilding::setRunningCostPerHour(int runningCostPerHour) {
	this->runningCostPerHour = runningCostPerHour;
}

void UtilityBuilding::print() {
    cout << "UtilityBuilding Attributes:" << endl;
    cout << "Running Cost per Hour: " << runningCostPerHour << endl;
    Building::print(); // Building print called
} 