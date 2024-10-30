#include "Factory.h"
#include <iostream>

Factory::Factory(int id)
    : IndustrialBuilding(id, 100, "Factory", 25, 250, 50, 50, 50, 50), satisfactionScore(25), numberOfEmployees(100), partProductionPerHour(300), productionCostPerHour(100) {}

Factory::~Factory() {}

void Factory::print() {
    std::cout << "Factory Attributes:" << std::endl;
    std::cout << "Part Production per Hour: " << partProductionPerHour << std::endl;
    std::cout << "Production Cost per Hour: " << productionCostPerHour << std::endl;
    IndustrialBuilding::print(); // Call to IndustrialBuilding's print function
}

// New functions
double Factory::getAverageSatisfactionScore() {
    return IndustrialBuilding::getAverageSatisfactionScore();
}

int Factory::getTotalWaterSupply() {
    return IndustrialBuilding::getTotalWaterSupply();
}

int Factory::getTotalWaterUsage() {
    return IndustrialBuilding::getTotalWaterUsage();
}

int Factory::getTotalElectricitySupply() {
    return IndustrialBuilding::getTotalElectricitySupply();
}

int Factory::getTotalElectricityDemand() {
    return IndustrialBuilding::getTotalElectricityDemand();
}

int Factory::getTotalSewageCapacity() {
    return IndustrialBuilding::getTotalSewageCapacity();
}

int Factory::getTotalWasteCapacity() {
    return IndustrialBuilding::getTotalWasteCapacity();
}

int Factory::getTotalWasteProduction() {
    return IndustrialBuilding::getTotalWasteProduction();
}

int Factory::getTotalSewageProduction() {
    return IndustrialBuilding::getTotalSewageProduction();
}

int Factory::getTotalNumberOfJobs() {
    return IndustrialBuilding::getTotalNumberOfJobs();
}