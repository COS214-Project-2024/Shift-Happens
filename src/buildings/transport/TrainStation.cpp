#include "TrainStation.h"

TrainStation::TrainStation(int id) :
    TransportBuilding(id, 500, "TrainStation", 2000, 200000, 75, 75, 200, 200)
{
}

TrainStation::~TrainStation()
{
}

void TrainStation::print()
{
    std::cout << "Train Station Attributes:" << std::endl;
    TransportBuilding::print();
}

// New functions
double TrainStation::getAverageSatisfactionScore() {
    return TransportBuilding::getAverageSatisfactionScore();
}

int TrainStation::getTotalWaterSupply() {
    return TransportBuilding::getTotalWaterSupply();
}

int TrainStation::getTotalWaterUsage() {
    return TransportBuilding::getTotalWaterUsage();
}

int TrainStation::getTotalElectricitySupply() {
    return TransportBuilding::getTotalElectricitySupply();
}

int TrainStation::getTotalElectricityDemand() {
    return TransportBuilding::getTotalElectricityDemand();
}

int TrainStation::getTotalSewageCapacity() {
    return TransportBuilding::getTotalSewageCapacity();
}

int TrainStation::getTotalWasteCapacity() {
    return TransportBuilding::getTotalWasteCapacity();
}

int TrainStation::getTotalWasteProduction() {
    return TransportBuilding::getTotalWasteProduction();
}

int TrainStation::getTotalSewageProduction() {
    return TransportBuilding::getTotalSewageProduction();
}

int TrainStation::getTotalNumberOfJobs() {
    return TransportBuilding::getTotalNumberOfJobs();
}