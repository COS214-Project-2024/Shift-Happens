#include "Manufacturer.h"
#include <iostream>

Manufacturer::Manufacturer(int id)
    : IndustrialBuilding(id, 100, "Manufacturer", 25, 250, 0, 0, 100, 100), satisfactionScore(25), numberOfEmployees(100), productsPerHour(100), partsUsedPerProduct(3), profitPerProduct(5) {}

Manufacturer::~Manufacturer() {}

void Manufacturer::print() {
    std::cout << "Manufacturer Attributes:" << std::endl;
    std::cout << "Products per Hour: " << productsPerHour << std::endl;
    std::cout << "Parts Used per Product: " << partsUsedPerProduct << std::endl;
    std::cout << "Profit per Product: " << profitPerProduct << std::endl;
    IndustrialBuilding::print(); // Call to IndustrialBuilding's print function
}

// New functions
double Manufacturer::getAverageSatisfactionScore() {
    return IndustrialBuilding::getAverageSatisfactionScore();
}

int Manufacturer::getTotalWaterSupply() {
    return IndustrialBuilding::getTotalWaterSupply();
}

int Manufacturer::getTotalWaterUsage() {
    return IndustrialBuilding::getTotalWaterUsage();
}

int Manufacturer::getTotalElectricitySupply() {
    return IndustrialBuilding::getTotalElectricitySupply();
}

int Manufacturer::getTotalElectricityDemand() {
    return IndustrialBuilding::getTotalElectricityDemand();
}

int Manufacturer::getTotalSewageCapacity() {
    return IndustrialBuilding::getTotalSewageCapacity();
}

int Manufacturer::getTotalWasteCapacity() {
    return IndustrialBuilding::getTotalWasteCapacity();
}

int Manufacturer::getTotalWasteProduction() {
    return IndustrialBuilding::getTotalWasteProduction();
}

int Manufacturer::getTotalSewageProduction() {
    return IndustrialBuilding::getTotalSewageProduction();
}

int Manufacturer::getTotalNumberOfJobs() {
    return IndustrialBuilding::getTotalNumberOfJobs();
}