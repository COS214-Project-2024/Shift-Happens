#include "Office.h"

Office::Office(int id)
: CommercialBuilding(id, 100, "Office", 50, 50, 250, 40, 40, 40, 40) {}

Office::~Office() {}

void Office::print() {
    cout << "Office Attributes:" << endl;
    CommercialBuilding::print(); // Call to CommercialBuilding's print function
}

// New functions
double Office::getAverageSatisfactionScore() {
    return CommercialBuilding::getAverageSatisfactionScore();
}

int Office::getTotalWaterSupply() {
    return CommercialBuilding::getTotalWaterSupply();
}

int Office::getTotalWaterUsage() {
    return CommercialBuilding::getTotalWaterUsage();
}

int Office::getTotalElectricitySupply() {
    return CommercialBuilding::getTotalElectricitySupply();
}

int Office::getTotalElectricityDemand() {
    return CommercialBuilding::getTotalElectricityDemand();
}

int Office::getTotalSewageCapacity() {
    return CommercialBuilding::getTotalSewageCapacity();
}

int Office::getTotalWasteCapacity() {
    return CommercialBuilding::getTotalWasteCapacity();
}

int Office::getTotalWasteProduction() {
    return CommercialBuilding::getTotalWasteProduction();
}

int Office::getTotalSewageProduction() {
    return CommercialBuilding::getTotalSewageProduction();
}

int Office::getTotalNumberOfJobs() {
    return CommercialBuilding::getTotalNumberOfJobs();
}