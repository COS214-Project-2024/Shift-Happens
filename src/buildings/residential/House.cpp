#include "House.h"

House::House(int id)
    : ResidentialBuilding(id, 40, "House", 75, 80, 400, 20, 20, 20, 20), satisfactionScore(75), capacity(40), incomePerHour(80) {}

House::~House() {
}

void House::print() {
    std::cout << "House Attributes:" << std::endl;
    std::cout << "Satisfaction Score: " << satisfactionScore << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Income per Hour: " << incomePerHour << std::endl;
    ResidentialBuilding::print(); 
}

// New functions
double House::getAverageSatisfactionScore() {
    return ResidentialBuilding::getAverageSatisfactionScore();
}

int House::getTotalWaterSupply() {
    return ResidentialBuilding::getTotalWaterSupply();
}

int House::getTotalWaterUsage() {
    return ResidentialBuilding::getTotalWaterUsage();
}

int House::getTotalElectricitySupply() {
    return ResidentialBuilding::getTotalElectricitySupply();
}

int House::getTotalElectricityDemand() {
    return ResidentialBuilding::getTotalElectricityDemand();
}

int House::getTotalSewageCapacity() {
    return ResidentialBuilding::getTotalSewageCapacity();
}

int House::getTotalWasteCapacity() {
    return ResidentialBuilding::getTotalWasteCapacity();
}

int House::getTotalWasteProduction() {
    return ResidentialBuilding::getTotalWasteProduction();
}

int House::getTotalSewageProduction() {
    return ResidentialBuilding::getTotalSewageProduction();
}

int House::getTotalNumberOfJobs() {
    return ResidentialBuilding::getTotalNumberOfJobs();
}