#include "Warehouse.h"
#include <iostream>

Warehouse::Warehouse(int id)
    : IndustrialBuilding(id, 50, "Warehouse", 25, 250, 10, 10, 10, 10), satisfactionScore(25), numberOfEmployees(50), storageCapacity(600), storageUsed(0) {}

Warehouse::~Warehouse() {}

void Warehouse::print() {
    std::cout << "Warehouse Attributes:" << std::endl;
    std::cout << "Storage Capacity: " << storageCapacity << std::endl;
    std::cout << "Storage Used: " << storageUsed << std::endl;
    IndustrialBuilding::print(); // Call to IndustrialBuilding's print function
}

// New functions
double Warehouse::getAverageSatisfactionScore() {
    return IndustrialBuilding::getAverageSatisfactionScore();
}

int Warehouse::getTotalWaterSupply() {
    return IndustrialBuilding::getTotalWaterSupply();
}

int Warehouse::getTotalWaterUsage() {
    return IndustrialBuilding::getTotalWaterUsage();
}

int Warehouse::getTotalElectricitySupply() {
    return IndustrialBuilding::getTotalElectricitySupply();
}

int Warehouse::getTotalElectricityDemand() {
    return IndustrialBuilding::getTotalElectricityDemand();
}

int Warehouse::getTotalSewageCapacity() {
    return IndustrialBuilding::getTotalSewageCapacity();
}

int Warehouse::getTotalWasteCapacity() {
    return IndustrialBuilding::getTotalWasteCapacity();
}

int Warehouse::getTotalWasteProduction() {
    return IndustrialBuilding::getTotalWasteProduction();
}

int Warehouse::getTotalSewageProduction() {
    return IndustrialBuilding::getTotalSewageProduction();
}

int Warehouse::getTotalNumberOfJobs() {
    return IndustrialBuilding::getTotalNumberOfJobs();
}



