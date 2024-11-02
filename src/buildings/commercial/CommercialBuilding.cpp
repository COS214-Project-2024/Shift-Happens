#include "CommercialBuilding.h"

CommercialBuilding::CommercialBuilding(int id, int incomePerHour, string variant, int satisfactionScore, int numberOfEmployees, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand) 
: Building(id, 1, 1, -1, -1, variant, "Commercial", constructionPrice, wasteProduced, sewageProduced, electricityDemand, waterDemand) {
    this->incomePerHour = incomePerHour;
    this->satisfactionScore = satisfactionScore;
    this->numberOfEmployees = numberOfEmployees;
}

int CommercialBuilding::getIncomePerHour() {
    return this->incomePerHour;
}

void CommercialBuilding::setIncomePerHour(int incomePerHour) {
    this->incomePerHour = incomePerHour;
}

int CommercialBuilding::getSatisfactionScore() {
    return this->satisfactionScore;
}

void CommercialBuilding::setSatisfactionScore(int satisfactionScore) {
    this->satisfactionScore = satisfactionScore;
}

int CommercialBuilding::getNumberOfEmployees() {
    return this->numberOfEmployees;
}

void CommercialBuilding::setNumberOfEmployees(int numberOfEmployees) {
    this->numberOfEmployees = numberOfEmployees;
}

void CommercialBuilding::print() {
    cout << "Commercial Building Attributes:" << endl;
    cout << "Income per Hour: " << incomePerHour << endl;
    cout << "Satisfaction Score: " << satisfactionScore << endl;
    cout << "Number of Employees: " << numberOfEmployees << endl;
    Building::print();
}

// New functions
double CommercialBuilding::getAverageSatisfactionScore() {
    return static_cast<double>(satisfactionScore);
}

int CommercialBuilding::getTotalWaterSupply() {
    return 0; // Commercial buildings do not supply water
}

int CommercialBuilding::getTotalWaterUsage() {
    return getWaterDemand();
}

int CommercialBuilding::getTotalElectricitySupply() {
    return 0; // Commercial buildings do not supply electricity
}

int CommercialBuilding::getTotalElectricityDemand() {
    return getElectricityDemand();
}

int CommercialBuilding::getTotalSewageCapacity() {
    return 0; // Commercial buildings do not have sewage capacity
}

int CommercialBuilding::getTotalWasteCapacity() {
    return 0; // Commercial buildings do not have waste capacity
}

int CommercialBuilding::getTotalWasteProduction() {
    return getWasteProduced();
}

int CommercialBuilding::getTotalSewageProduction() {
    return getSewageProduced();
}

int CommercialBuilding::getTotalNumberOfJobs() {
    return getNumberOfEmployees();
}