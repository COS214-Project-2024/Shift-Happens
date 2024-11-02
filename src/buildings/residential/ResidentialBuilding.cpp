#include "ResidentialBuilding.h"
#include <iostream>

using namespace std;

ResidentialBuilding::ResidentialBuilding(int id, int capacity, string variant, int satisfactionScore, int incomePerHour, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand)
    : Building(id, 1, 1, -1, -1, variant, "Residential", constructionPrice, wasteProduced, sewageProduced, electricityDemand, waterDemand)
{
    this->capacity = capacity;
    this->satisfactionScore = satisfactionScore;
    this->incomePerHour = incomePerHour;
}

int ResidentialBuilding::getCapacity() {
    return this->capacity;
}

void ResidentialBuilding::setCapacity(int capacity) {
    this->capacity = capacity;
}

int ResidentialBuilding::getSatisfactionScore() {
    return this->satisfactionScore;
}

void ResidentialBuilding::setSatisfactionScore(int satisfactionScore) {
    this->satisfactionScore = satisfactionScore;
}

int ResidentialBuilding::getIncomePerHour() {
    return this->incomePerHour;
}

void ResidentialBuilding::setIncomePerHour(int incomePerHour) {
    this->incomePerHour = incomePerHour;
}

ResidentialBuilding::~ResidentialBuilding() {
}

void ResidentialBuilding::print() {
    cout << "ResidentialBuilding Attributes:" << endl;
    cout << "Capacity: " << capacity << ", Satisfaction Score: " << satisfactionScore << endl;
    cout << "Income per Hour: " << incomePerHour << endl;
    Building::print(); 
}

// New functions
double ResidentialBuilding::getAverageSatisfactionScore() {
    return static_cast<double>(satisfactionScore);
}

int ResidentialBuilding::getTotalWaterSupply() {
    return 0; // Residential buildings do not supply water
}

int ResidentialBuilding::getTotalWaterUsage() {
    return getWaterDemand();
}

int ResidentialBuilding::getTotalElectricitySupply() {
    return 0; // Residential buildings do not supply electricity
}

int ResidentialBuilding::getTotalElectricityDemand() {
    return getElectricityDemand();
}

int ResidentialBuilding::getTotalSewageCapacity() {
    return 0; // Residential buildings do not have sewage capacity
}

int ResidentialBuilding::getTotalWasteCapacity() {
    return 0; // Residential buildings do not have waste capacity
}

int ResidentialBuilding::getTotalWasteProduction() {
    return getWasteProduced();
}

int ResidentialBuilding::getTotalSewageProduction() {
    return getSewageProduced();
}

int ResidentialBuilding::getTotalNumberOfJobs() {
    return 0; // Residential buildings do not provide jobs
}

