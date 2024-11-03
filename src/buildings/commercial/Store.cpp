#include "Store.h"

Store::Store(int id)
: CommercialBuilding(id, 50, "Store", 50, 25, 125, 10, 10, 10, 10) {}

Store::~Store() {}

void Store::print() {
    cout << "Store Attributes:" << endl;
    CommercialBuilding::print(); // Call to CommercialBuilding's print function
}

// New functions
double Store::getAverageSatisfactionScore() {
    return CommercialBuilding::getAverageSatisfactionScore();
}

int Store::getTotalWaterSupply() {
    return CommercialBuilding::getTotalWaterSupply();
}

int Store::getTotalWaterUsage() {
    return CommercialBuilding::getTotalWaterUsage();
}

int Store::getTotalElectricitySupply() {
    return CommercialBuilding::getTotalElectricitySupply();
}

int Store::getTotalElectricityDemand() {
    return CommercialBuilding::getTotalElectricityDemand();
}

int Store::getTotalSewageCapacity() {
    return CommercialBuilding::getTotalSewageCapacity();
}

int Store::getTotalWasteCapacity() {
    return CommercialBuilding::getTotalWasteCapacity();
}

int Store::getTotalWasteProduction() {
    return CommercialBuilding::getTotalWasteProduction();
}

int Store::getTotalSewageProduction() {
    return CommercialBuilding::getTotalSewageProduction();
}

int Store::getTotalNumberOfJobs() {
    return CommercialBuilding::getTotalNumberOfJobs();
}