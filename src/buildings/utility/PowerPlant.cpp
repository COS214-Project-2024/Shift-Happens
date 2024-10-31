#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant(int id)
    : UtilityBuilding(id, "PowerPlant", 500, 10, 10, 0, 10), electricityProduction(500) {}

double PowerPlant::getElectricityProduction() {
    return electricityProduction;
}

void PowerPlant::setElectricityProduction(int electricityProduction) {
    this->electricityProduction = electricityProduction;
}

void PowerPlant::print() {
    cout << "PowerPlant Attributes:" << endl;
    cout << "Electricity Production: " << electricityProduction << endl;
    UtilityBuilding::print(); // Call to UtilityBuilding's print function
}

// New functions
double PowerPlant::getAverageSatisfactionScore() {
    return 0; // PowerPlant does not have a satisfaction score
}

int PowerPlant::getTotalWaterSupply() {
    return 0; // PowerPlant does not supply water
}

int PowerPlant::getTotalWaterUsage() {
    return getWaterDemand();
}

int PowerPlant::getTotalElectricitySupply() {
    return getElectricityProduction();
}

int PowerPlant::getTotalElectricityDemand() {
    return getElectricityDemand();
}

int PowerPlant::getTotalSewageCapacity() {
    return 0; // PowerPlant does not have sewage capacity
}

int PowerPlant::getTotalWasteCapacity() {
    return 0; // PowerPlant does not have waste capacity
}

int PowerPlant::getTotalWasteProduction() {
    return getWasteProduced();
}

int PowerPlant::getTotalSewageProduction() {
    return getSewageProduced();
}

int PowerPlant::getTotalNumberOfJobs() {
    return 0; // PowerPlant does not provide jobs
}