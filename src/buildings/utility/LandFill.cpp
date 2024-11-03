#include "LandFill.h"
#include <iostream>

LandFill::LandFill(int id)
    : UtilityBuilding(id, "Landfill", 500, 0, 10, 10, 10), wasteRemovalRate(500) {}

int LandFill::getWasteRemovalRate() {
    return this->wasteRemovalRate;
}

void LandFill::setWasteRemovalRate(int wasteRemovalRate) {
    this->wasteRemovalRate = wasteRemovalRate;
}

void LandFill::print() {
    std::cout << "LandFill Attributes:" << std::endl;
    std::cout << "Waste Removal Rate: " << wasteRemovalRate << std::endl;
    UtilityBuilding::print(); // Call to UtilityBuilding's print function
}

// New functions
double LandFill::getAverageSatisfactionScore() {
    return 0; // LandFill does not have a satisfaction score
}

int LandFill::getTotalWaterSupply() {
    return 0; // LandFill does not supply water
}

int LandFill::getTotalWaterUsage() {
    return getWaterDemand();
}

int LandFill::getTotalElectricitySupply() {
    return 0; // LandFill does not supply electricity
}

int LandFill::getTotalElectricityDemand() {
    return getElectricityDemand();
}

int LandFill::getTotalSewageCapacity() {
    return 0; // LandFill does not have sewage capacity
}

int LandFill::getTotalWasteCapacity() {
    return getWasteRemovalRate();
}

int LandFill::getTotalWasteProduction() {
    return getWasteProduced();
}

int LandFill::getTotalSewageProduction() {
    return getSewageProduced();
}

int LandFill::getTotalNumberOfJobs() {
    return 0; // LandFill does not provide jobs
}