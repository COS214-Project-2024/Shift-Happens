#include "Building.h"

int Building_State::Building::getWidth() {
	return this->width;
}

void Building_State::Building::setWidth(int width) {
	this->width = width;
}

int Building_State::Building::getLength() {
	return this->length;
}

void Building_State::Building::setLength(int length) {
	this->length = length;
}

int Building_State::Building::getXPos() {
	return this->xPos;
}

void Building_State::Building::setXPos(int xPos) {
	this->xPos = xPos;
}

int Building_State::Building::getYPos() {
	return this->yPos;
}

void Building_State::Building::setYPos(int yPos) {
	this->yPos = yPos;
}

string Building_State::Building::getVariant() {
	return this->variant;
}

void Building_State::Building::setVariant(string variant) {
	this->variant = variant;
}

string Building_State::Building::getType() {
	return this->type;
}

void Building_State::Building::setType(string type) {
	this->type = type;
}

int Building_State::Building::getConstructionPrice() {
	return this->constructionPrice;
}

void Building_State::Building::setConstructionPrice(int constructionPrice) {
	this->constructionPrice = constructionPrice;
}

int Building_State::Building::getWasteProduced() {
	return this->wasteProduced;
}

void Building_State::Building::setWasteProduced(int wasteProduced) {
	this->wasteProduced = wasteProduced;
}

int Building_State::Building::getSewageProduced() {
	return this->sewageProduced;
}

void Building_State::Building::setSewageProduced(int sewageProduced) {
	this->sewageProduced = sewageProduced;
}

int Building_State::Building::getElectricityDemand() {
	return this->electricityDemand;
}

void Building_State::Building::setElectricityDemand(int electricityDemand) {
	this->electricityDemand = electricityDemand;
}

int Building_State::Building::getWaterDemand() {
	return this->waterDemand;
}

void Building_State::Building::setWaterDemand(int waterDemand) {
	this->waterDemand = waterDemand;
}
