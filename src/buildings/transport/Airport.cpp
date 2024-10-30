#include "Airport.h"

Airport::Airport(int id) : TransportBuilding(id, 1000, "Airport", 5000, 1000000, 100, 100, 500, 500)
{
}

Airport::~Airport()
{
}

void Airport::print()
{
    std::cout << "Airport Attributes:" << std::endl;
    TransportBuilding::print();
}

// New functions
double Airport::getAverageSatisfactionScore() {
    return TransportBuilding::getAverageSatisfactionScore();
}

int Airport::getTotalWaterSupply() {
    return TransportBuilding::getTotalWaterSupply();
}

int Airport::getTotalWaterUsage() {
    return TransportBuilding::getTotalWaterUsage();
}

int Airport::getTotalElectricitySupply() {
    return TransportBuilding::getTotalElectricitySupply();
}

int Airport::getTotalElectricityDemand() {
    return TransportBuilding::getTotalElectricityDemand();
}

int Airport::getTotalSewageCapacity() {
    return TransportBuilding::getTotalSewageCapacity();
}

int Airport::getTotalWasteCapacity() {
    return TransportBuilding::getTotalWasteCapacity();
}

int Airport::getTotalWasteProduction() {
    return TransportBuilding::getTotalWasteProduction();
}

int Airport::getTotalSewageProduction() {
    return TransportBuilding::getTotalSewageProduction();
}

int Airport::getTotalNumberOfJobs() {
    return TransportBuilding::getTotalNumberOfJobs();
}