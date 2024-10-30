#include "BusStation.h"

BusStation::BusStation(int id) : TransportBuilding(id, 200, "BusStation", 1000, 50000, 50, 50, 100, 100)
{
}

BusStation::~BusStation()
{
}

void BusStation::print()
{
    std::cout << "Bus Station Attributes:" << std::endl;
    TransportBuilding::print();
}

// New functions
double BusStation::getAverageSatisfactionScore() {
    return TransportBuilding::getAverageSatisfactionScore();
}

int BusStation::getTotalWaterSupply() {
    return TransportBuilding::getTotalWaterSupply();
}

int BusStation::getTotalWaterUsage() {
    return TransportBuilding::getTotalWaterUsage();
}

int BusStation::getTotalElectricitySupply() {
    return TransportBuilding::getTotalElectricitySupply();
}

int BusStation::getTotalElectricityDemand() {
    return TransportBuilding::getTotalElectricityDemand();
}

int BusStation::getTotalSewageCapacity() {
    return TransportBuilding::getTotalSewageCapacity();
}

int BusStation::getTotalWasteCapacity() {
    return TransportBuilding::getTotalWasteCapacity();
}

int BusStation::getTotalWasteProduction() {
    return TransportBuilding::getTotalWasteProduction();
}

int BusStation::getTotalSewageProduction() {
    return TransportBuilding::getTotalSewageProduction();
}

int BusStation::getTotalNumberOfJobs() {
    return TransportBuilding::getTotalNumberOfJobs();
}