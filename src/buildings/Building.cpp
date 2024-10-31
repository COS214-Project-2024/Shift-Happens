#include "Building.h"
#include <string>
#include <iostream>

using namespace std;

Building::Building(int id, int width, int length, int xPos, int yPos, string variant, string type, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand)
: MapComponent(id) {
    this->width = width;
    this->length = length;
    this->xPos = xPos;
    this->yPos = yPos;
    this->variant = variant;
    this->type = type;
    this->constructionPrice = constructionPrice;
    this->wasteProduced = wasteProduced;
    this->sewageProduced = sewageProduced;
    this->electricityDemand = electricityDemand;
    this->waterDemand = waterDemand;
}

int Building::getWidth() {
    return this->width;
}

void Building::setWidth(int width) {
    this->width = width;
}

int Building::getLength() {
    return this->length;
}

void Building::setLength(int length) {
    this->length = length;
}

int Building::getXPos() {
    return this->xPos;
}

void Building::setXPos(int xPos) {
    this->xPos = xPos;
}

int Building::getYPos() {
    return this->yPos;
}

void Building::setYPos(int yPos) {
    this->yPos = yPos;
}

string Building::getVariant() {
    return this->variant;
}

void Building::setVariant(string variant) {
    this->variant = variant;
}

string Building::getType() {
    return this->type;
}

void Building::setType(string type) {
    this->type = type;
}

int Building::getConstructionPrice() {
    return this->constructionPrice;
}

void Building::setConstructionPrice(int constructionPrice) {
    this->constructionPrice = constructionPrice;
}

int Building::getWasteProduced() {
    return this->wasteProduced;
}

void Building::setWasteProduced(int wasteProduced) {
    this->wasteProduced = wasteProduced;
}

int Building::getSewageProduced() {
    return this->sewageProduced;
}

void Building::setSewageProduced(int sewageProduced) {
    this->sewageProduced = sewageProduced;
}

int Building::getElectricityDemand() {
    return this->electricityDemand;
}

void Building::setElectricityDemand(int electricityDemand) {
    this->electricityDemand = electricityDemand;
}

int Building::getWaterDemand() {
    return this->waterDemand;
}

void Building::setWaterDemand(int waterDemand) {
    this->waterDemand = waterDemand;
}

void Building::render() {
    throw "Building::render() not implemented";
}

void Building::print() const {
    cout << "Building Attributes:" << endl;
    cout << "Width: " << width << ", Length: " << length << endl;
    cout << "Position: (" << xPos << ", " << yPos << ")" << endl;
    cout << "Type: " << type << ", Variant: " << variant << endl;
    cout << "Construction Price: " << constructionPrice << endl;
    cout << "Waste Produced: " << wasteProduced << ", Sewage Produced: " << sewageProduced << endl;
    cout << "Electricity Demand: " << electricityDemand << ", Water Demand: " << waterDemand << endl;
}

Building::Building(shared_ptr<Building> building) 
: MapComponent(building->getId()) {
    this->width = building->getWidth();
    this->length = building->getLength();
    this->xPos = building->getXPos();
    this->yPos = building->getYPos();
    this->variant = building->getVariant();
    this->type = building->getType();
    this->constructionPrice = building->getConstructionPrice();
    this->wasteProduced = building->getWasteProduced();
    this->sewageProduced = building->getSewageProduced();
    this->electricityDemand = building->getElectricityDemand();
    this->waterDemand = building->getWaterDemand();
}
