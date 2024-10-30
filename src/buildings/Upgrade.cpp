#include "Upgrade.h"

Upgrade::Upgrade(shared_ptr<Building> building)
: Building(building)
{
    this->building = building;
}



Upgrade::~Upgrade() {}

int Upgrade::getWasteProduced() {
    return building->getWasteProduced();
}

void Upgrade::setWasteProduced(int wasteProduced) {
    building->setWasteProduced(wasteProduced);
}

int Upgrade::getSewageProduced() {
    return building->getSewageProduced();
}

void Upgrade::setSewageProduced(int sewageProduced) {
    building->setSewageProduced(sewageProduced);
}

int Upgrade::getElectricityDemand() {
    return building->getElectricityDemand();
}

void Upgrade::setElectricityDemand(int electricityDemand) {
    building->setElectricityDemand(electricityDemand);
}

int Upgrade::getWaterDemand() {
    return building->getWaterDemand();
}

void Upgrade::setWaterDemand(int waterDemand) {
    building->setWaterDemand(waterDemand);
}

string Upgrade::getUpgradeType() {
    return type;
} 