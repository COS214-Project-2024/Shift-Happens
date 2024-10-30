#include "Mall.h"

Mall::Mall(int id)
: CommercialBuilding(id, 200, "Mall", 50, 100, 500, 40, 40, 40, 40) {}

Mall::~Mall() {}

void Mall::print() {
    cout << "Mall Attributes:" << endl;
    CommercialBuilding::print(); // Call to CommercialBuilding's print function
}

// New functions
double Mall::getAverageSatisfactionScore() {
    return CommercialBuilding::getAverageSatisfactionScore();
}

int Mall::getTotalWaterSupply() {
    return CommercialBuilding::getTotalWaterSupply();
}

int Mall::getTotalWaterUsage() {
    return CommercialBuilding::getTotalWaterUsage();
}

int Mall::getTotalElectricitySupply() {
    return CommercialBuilding::getTotalElectricitySupply();
}

int Mall::getTotalElectricityDemand() {
    return CommercialBuilding::getTotalElectricityDemand();
}

int Mall::getTotalSewageCapacity() {
    return CommercialBuilding::getTotalSewageCapacity();
}

int Mall::getTotalWasteCapacity() {
    return CommercialBuilding::getTotalWasteCapacity();
}

int Mall::getTotalWasteProduction() {
    return CommercialBuilding::getTotalWasteProduction();
}

int Mall::getTotalSewageProduction() {
    return CommercialBuilding::getTotalSewageProduction();
}

int Mall::getTotalNumberOfJobs() {
    return CommercialBuilding::getTotalNumberOfJobs();
}