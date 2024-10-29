#include "LandFill.h"
#include <iostream>

LandFill::LandFill(int id)
    : UtilityBuilding(id, "Landfill", 500, 0, 10, 10, 10, statistics), wasteRemovalRate(500) {}

int LandFill::getWasteRemovalRate() {
	return this->wasteRemovalRate;
}

void LandFill::setWasteRemovalRate(int wasteRemovalRate) {
	this->wasteRemovalRate = wasteRemovalRate;
}

void LandFill::print() const {
    std::cout << "LandFill Attributes:" << std::endl;
    std::cout << "Waste Removal Rate: " << wasteRemovalRate << std::endl;
    UtilityBuilding::print(); 
}