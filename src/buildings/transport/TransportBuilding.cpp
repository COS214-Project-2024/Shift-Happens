#include "TransportBuilding.h"

TransportBuilding::TransportBuilding(int id, int capacity, std::string variant, int maintenanceCost, int constructionCost, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand)
    : Building(id, 1, 1, -1, -1, variant, "Transport", constructionCost, wasteProduced, sewageProduced, electricityDemand, waterDemand)
{
    this->capacity = capacity;
    this->maintenanceCost = maintenanceCost;
    this->constructionCost = constructionCost;
}

int TransportBuilding::getCapacity() const {
    return this->capacity;
}

void TransportBuilding::setCapacity(int capacity) {
    this->capacity = capacity;
}

int TransportBuilding::getMaintenanceCost() const {
    return this->maintenanceCost;
}

void TransportBuilding::setMaintenanceCost(int maintenanceCost) {
    this->maintenanceCost = maintenanceCost;
}

int TransportBuilding::getConstructionCost() const {
    return this->constructionCost;
}

void TransportBuilding::setConstructionCost(int constructionCost) {
    this->constructionCost = constructionCost;
}

TransportBuilding::~TransportBuilding() {
}

void TransportBuilding::print(){
    std::cout << "Transport Building" << std::endl;
    std::cout << "ID: " << this->getId() << std::endl;
    std::cout << "Capacity: " << this->capacity << std::endl;
    std::cout << "Maintenance Cost: " << this->maintenanceCost << std::endl;
    std::cout << "Construction Cost: " << this->constructionCost << std::endl;
    std::cout << "Waste Produced: " << this->getWasteProduced() << std::endl;
    std::cout << "Sewage Produced: " << this->getSewageProduced() << std::endl;
    std::cout << "Electricity Demand: " << this->getElectricityDemand() << std::endl;
    std::cout << "Water Demand: " << this->getWaterDemand() << std::endl;
}