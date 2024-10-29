#include "Building.h"
#include <string> 
#include <iostream> 

using namespace std;

Building::Building(int id,int width, int length, int xPos, int yPos, string variant, string type, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand, Statistics* statistics) 
: MapComponent(id)
{
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
	this->statistics = statistics;
	statistics->addBuilding(this); //add recently created building to the statistics object vector which tracks all buildings
}


int Building::getWidth() {
	return this->width;
}

void Building::Building::setWidth(int width) {
	this->width = width;
}

int Building::Building::getLength() {
	return this->length;
}

void Building::Building::setLength(int length) {
	this->length = length;
}

int Building::Building::getXPos() {
	return this->xPos;
}

void Building::Building::setXPos(int xPos) {
	this->xPos = xPos;
}

int Building::Building::getYPos() {
	return this->yPos;
}

void Building::Building::setYPos(int yPos) {
	this->yPos = yPos;
}

string Building::Building::getVariant() {
	return this->variant;
}

void Building::Building::setVariant(string variant) {
	this->variant = variant;
}

string Building::Building::getType() {
	return this->type;
}

void Building::Building::setType(string type) {
	this->type = type;
}

int Building::Building::getConstructionPrice() {
	return this->constructionPrice;
}

void Building::Building::setConstructionPrice(int constructionPrice) {
	this->constructionPrice = constructionPrice;
}

int Building::Building::getWasteProduced() {
	return this->wasteProduced;
}

void Building::Building::setWasteProduced(int wasteProduced) {
	this->wasteProduced = wasteProduced;
}

int Building::Building::getSewageProduced() {
	return this->sewageProduced;
}

void Building::Building::setSewageProduced(int sewageProduced) {
	this->sewageProduced = sewageProduced;
}

int Building::Building::getElectricityDemand() {
	return this->electricityDemand;
}

void Building::Building::setElectricityDemand(int electricityDemand) {
	this->electricityDemand = electricityDemand;
}

int Building::Building::getWaterDemand() {
	return this->waterDemand;
}

void Building::Building::setWaterDemand(int waterDemand) {
	this->waterDemand = waterDemand;
}

bool Building::add(MapComponent *component) {
	throw "Building::add(MapComponent *component) not implemented";
}

bool Building::remove(MapComponent *component) {
	throw "Building::remove(MapComponent *component) not implemented";
}

void Building::getComponent(int id) {
	throw "Building::getComponent(int id) not implemented";
}

void Building::render() {
	throw "Building::render() not implemented";
}

//print function
void Building::print() const {
    cout << "Building Attributes:" << endl;
    cout << "Width: " << width << ", Length: " << length << endl;
    cout << "Position: (" << xPos << ", " << yPos << ")" << endl;
    cout << "Type: " << type << ", Variant: " << variant << endl;
    cout << "Construction Price: " << constructionPrice << endl;
    cout << "Waste Produced: " << wasteProduced << ", Sewage Produced: " << sewageProduced << endl;
    cout << "Electricity Demand: " << electricityDemand << ", Water Demand: " << waterDemand << endl;
}

