#include "TownHouse.h"

TownHouse::TownHouse(int id)
    : ResidentialBuilding(id, 20, "TownHouse", 75, 40, 200, 10, 10, 10, 10), satisfactionScore(75), capacity(20), incomePerHour(40) {}

TownHouse::~TownHouse() {
}

void TownHouse::print() {
    std::cout << "TownHouse Attributes:" << std::endl;
    std::cout << "Satisfaction Score: " << satisfactionScore << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Income per Hour: " << incomePerHour << std::endl;
    ResidentialBuilding::print(); 
}

// New functions
double TownHouse::getAverageSatisfactionScore() {
    return ResidentialBuilding::getAverageSatisfactionScore();
}

int TownHouse::getTotalWaterSupply() {
    return ResidentialBuilding::getTotalWaterSupply();
}

int TownHouse::getTotalWaterUsage() {
    return ResidentialBuilding::getTotalWaterUsage();
}

int TownHouse::getTotalElectricitySupply() {
    return ResidentialBuilding::getTotalElectricitySupply();
}

int TownHouse::getTotalElectricityDemand() {
    return ResidentialBuilding::getTotalElectricityDemand();
}

int TownHouse::getTotalSewageCapacity() {
    return ResidentialBuilding::getTotalSewageCapacity();
}

int TownHouse::getTotalWasteCapacity() {
    return ResidentialBuilding::getTotalWasteCapacity();
}

int TownHouse::getTotalWasteProduction() {
    return ResidentialBuilding::getTotalWasteProduction();
}

int TownHouse::getTotalSewageProduction() {
    return ResidentialBuilding::getTotalSewageProduction();
}

int TownHouse::getTotalNumberOfJobs() {
    return ResidentialBuilding::getTotalNumberOfJobs();
}