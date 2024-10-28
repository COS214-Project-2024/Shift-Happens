#include "SewagePlant.h"
#include <iostream>

SewagePlant::SewagePlant(int id)
    : UtilityBuilding(id, "SewagePlant", 500, 0, 10, 10, 10), sewageRemovalRate(500) {}

int SewagePlant::getSewageRemovalRate() {
	return this->sewageRemovalRate;
}

void SewagePlant::setSewageRemovalRate(int sewageRemovalRate) {
	this->sewageRemovalRate = sewageRemovalRate;
}

void SewagePlant::print() const {
    std::cout << "SewagePlant Attributes:" << std::endl;
    std::cout << "Sewage Removal Rate: " << sewageRemovalRate << std::endl;
    UtilityBuilding::print(); // Call to UtilityBuilding's print function
}
