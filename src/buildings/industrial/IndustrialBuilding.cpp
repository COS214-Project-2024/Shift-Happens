#include "IndustrialBuilding.h"

IndustrialBuilding::IndustrialBuilding(int id, int numberOfEmployees, std::string variant, int satisfactionScore, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand)
: Building(id, 1, 1, -1, -1, variant, "Industrial", constructionPrice, wasteProduced, sewageProduced, electricityDemand, waterDemand) {
    this->numberOfEmployees = numberOfEmployees;
    this->satisfactionScore = satisfactionScore;
}

int IndustrialBuilding::getNumberOfEmployees() {
    return this->numberOfEmployees;
}

void IndustrialBuilding::setNumberOfEmployees(int numberOfEmployees) {
    this->numberOfEmployees = numberOfEmployees;
}

int IndustrialBuilding::getSatisfactionScore() {
    return this->satisfactionScore;
}

void IndustrialBuilding::setSatisfactionScore(int satisfactionScore) {
    this->satisfactionScore = satisfactionScore;
}

void IndustrialBuilding::print() {
    std::cout << "Industrial Building Attributes:" << std::endl;
    std::cout << "Number of Employees: " << numberOfEmployees << std::endl;
    std::cout << "Satisfaction Score: " << satisfactionScore << std::endl;
    Building::print(); // Call to Building's print function
}

// New functions
double IndustrialBuilding::getAverageSatisfactionScore() {
    return static_cast<double>(satisfactionScore);
}

int IndustrialBuilding::getTotalWaterSupply() {
    return 0; // Industrial buildings do not supply water
}

int IndustrialBuilding::getTotalWaterUsage() {
    return getWaterDemand();
}

int IndustrialBuilding::getTotalElectricitySupply() {
    return 0; // Industrial buildings do not supply electricity
}

int IndustrialBuilding::getTotalElectricityDemand() {
    return getElectricityDemand();
}

int IndustrialBuilding::getTotalSewageCapacity() {
    return 0; // Industrial buildings do not have sewage capacity
}

int IndustrialBuilding::getTotalWasteCapacity() {
    return 0; // Industrial buildings do not have waste capacity
}

int IndustrialBuilding::getTotalWasteProduction() {
    return getWasteProduced();
}

int IndustrialBuilding::getTotalSewageProduction() {
    return getSewageProduced();
}

int IndustrialBuilding::getTotalNumberOfJobs() {
    return getNumberOfEmployees();
}