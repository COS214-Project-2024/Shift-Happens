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

void SewagePlant::print() {
    std::cout << "SewagePlant Attributes:" << std::endl;
    std::cout << "Sewage Removal Rate: " << sewageRemovalRate << std::endl;
    UtilityBuilding::print(); // Call to UtilityBuilding's print function
}

// New functions
double SewagePlant::getAverageSatisfactionScore() {
    return 0; // SewagePlant does not have a satisfaction score
}

int SewagePlant::getTotalWaterSupply() {
    return 0; // SewagePlant does not supply water
}

int SewagePlant::getTotalWaterUsage() {
    return getWaterDemand();
}

int SewagePlant::getTotalElectricitySupply() {
    return 0; // SewagePlant does not supply electricity
}

int SewagePlant::getTotalElectricityDemand() {
    return getElectricityDemand();
}

int SewagePlant::getTotalSewageCapacity() {
    return getSewageRemovalRate();
}

int SewagePlant::getTotalWasteCapacity() {
    return 0; // SewagePlant does not have waste capacity
}

int SewagePlant::getTotalWasteProduction() {
    return getWasteProduced();
}

int SewagePlant::getTotalSewageProduction() {
    return getSewageProduced();
}

int SewagePlant::getTotalNumberOfJobs() {
    return 0; // SewagePlant does not provide jobs
}