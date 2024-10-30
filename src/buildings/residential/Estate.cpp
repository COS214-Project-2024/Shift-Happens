#include "Estate.h"

Estate::Estate(int id)
    : ResidentialBuilding(id, 80, "Estate", 75, 160, 800, 40, 40, 40, 40), satisfactionScore(75), capacity(80), incomePerHour(160) {}

Estate::~Estate() {
}

void Estate::print() {
    std::cout << "Estate Attributes:" << std::endl;
    std::cout << "Satisfaction Score: " << satisfactionScore << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Income per Hour: " << incomePerHour << std::endl;
    ResidentialBuilding::print(); 
}

// New functions
double Estate::getAverageSatisfactionScore() {
    return ResidentialBuilding::getAverageSatisfactionScore();
}

int Estate::getTotalWaterSupply() {
    return ResidentialBuilding::getTotalWaterSupply();
}

int Estate::getTotalWaterUsage() {
    return ResidentialBuilding::getTotalWaterUsage();
}

int Estate::getTotalElectricitySupply() {
    return ResidentialBuilding::getTotalElectricitySupply();
}

int Estate::getTotalElectricityDemand() {
    return ResidentialBuilding::getTotalElectricityDemand();
}

int Estate::getTotalSewageCapacity() {
    return ResidentialBuilding::getTotalSewageCapacity();
}

int Estate::getTotalWasteCapacity() {
    return ResidentialBuilding::getTotalWasteCapacity();
}

int Estate::getTotalWasteProduction() {
    return ResidentialBuilding::getTotalWasteProduction();
}

int Estate::getTotalSewageProduction() {
    return ResidentialBuilding::getTotalSewageProduction();
}

int Estate::getTotalNumberOfJobs() {
    return ResidentialBuilding::getTotalNumberOfJobs();
}