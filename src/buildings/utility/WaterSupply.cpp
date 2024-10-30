#include "WaterSupply.h"
#include <iostream>

WaterSupply::WaterSupply(int id)
    : UtilityBuilding(id, "WaterSupply", 500, 10, 10, 10, 0), waterSupply(500) {}

double WaterSupply::getWaterSupply() {
    return waterSupply;
}

void WaterSupply::setWaterSupply(int waterSupply) {
    this->waterSupply = waterSupply;
}

void WaterSupply::print() {
    std::cout << "WaterSupply Attributes:" << std::endl;
    std::cout << "Water Supply: " << waterSupply << std::endl;
    UtilityBuilding::print(); // Call to UtilityBuilding's print function
}

// New functions
double WaterSupply::getAverageSatisfactionScore() {
    return 0; // WaterSupply does not have a satisfaction score
}

int WaterSupply::getTotalWaterSupply() {
    return getWaterSupply();
}

int WaterSupply::getTotalWaterUsage() {
    return getWaterDemand();
}

int WaterSupply::getTotalElectricitySupply() {
    return 0; // WaterSupply does not supply electricity
}

int WaterSupply::getTotalElectricityDemand() {
    return getElectricityDemand();
}

int WaterSupply::getTotalSewageCapacity() {
    return 0; // WaterSupply does not have sewage capacity
}

int WaterSupply::getTotalWasteCapacity() {
    return 0; // WaterSupply does not have waste capacity
}

int WaterSupply::getTotalWasteProduction() {
    return getWasteProduced();
}

int WaterSupply::getTotalSewageProduction() {
    return getSewageProduced();
}

int WaterSupply::getTotalNumberOfJobs() {
    return 0; // WaterSupply does not provide jobs
}