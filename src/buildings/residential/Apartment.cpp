#include "Apartment.h"
#include <iostream>

using namespace std;

Apartment::Apartment(int id)
    : ResidentialBuilding(id, 10, "Apartment", 75, 20, 100, 5, 5, 5, 5), satisfactionScore(75), capacity(10), incomePerHour(20) {}

Apartment::~Apartment() {
}

void Apartment::print() {
    cout << "Apartment Attributes:" << endl;
    cout << "Satisfaction Score: " << satisfactionScore << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Income per Hour: " << incomePerHour << endl;
    ResidentialBuilding::print(); 
}

// New functions
double Apartment::getAverageSatisfactionScore() {
    return ResidentialBuilding::getAverageSatisfactionScore();
}

int Apartment::getTotalWaterSupply() {
    return ResidentialBuilding::getTotalWaterSupply();
}

int Apartment::getTotalWaterUsage() {
    return ResidentialBuilding::getTotalWaterUsage();
}

int Apartment::getTotalElectricitySupply() {
    return ResidentialBuilding::getTotalElectricitySupply();
}

int Apartment::getTotalElectricityDemand() {
    return ResidentialBuilding::getTotalElectricityDemand();
}

int Apartment::getTotalSewageCapacity() {
    return ResidentialBuilding::getTotalSewageCapacity();
}

int Apartment::getTotalWasteCapacity() {
    return ResidentialBuilding::getTotalWasteCapacity();
}

int Apartment::getTotalWasteProduction() {
    return ResidentialBuilding::getTotalWasteProduction();
}

int Apartment::getTotalSewageProduction() {
    return ResidentialBuilding::getTotalSewageProduction();
}

int Apartment::getTotalNumberOfJobs() {
    return ResidentialBuilding::getTotalNumberOfJobs();
}
