#include "Infrastructure.h"

Infrastructure::Infrastructure(string variant, int id) 
: MapComponent(id)
{
    this->variant = variant;
    this->type = "Infrastructure";
    this->width = 1;
    this->length = 1;
    this->yPos = -1;
    this->xPos = -1;
}

int Infrastructure::getWidth() {
    return this->width;
}

void Infrastructure::setWidth(int width) {
    this->width = width;
}

int Infrastructure::getLength() {
    return this->length;
}

void Infrastructure::setLength(int length) {
    this->length = length;
}

int Infrastructure::getYPos() {
    return this->yPos;
}

void Infrastructure::setYPos(int yPos) {
    this->yPos = yPos;
}

int Infrastructure::getXPos() {
    return this->xPos;
}

void Infrastructure::setXPos(int xPos) {
    this->xPos = xPos;
}

int Infrastructure::getConstructionCost() {
    return this->constructionCost;
}

void Infrastructure::setConstructionCost(int constructionCost) {
    this->constructionCost = constructionCost;
}

void Infrastructure::render() {
    throw "Infrastructure::render() not yet implemented";
}

bool Infrastructure::add(MapComponent *component) {
    throw "Infrastructure::add() not yet implemented";
}

bool Infrastructure::remove(MapComponent *component) {
    throw "Infrastructure::remove() not yet implemented";
}

void Infrastructure::getComponent(int id) {
    throw "Infrastructure::getComponent() not yet implemented";
}

Infrastructure::~Infrastructure() {
}

void Infrastructure::print() {
    //prints all the attributes
    cout << "Infrastructure Attributes:" << endl;
    cout << "Variant: " << variant << endl;
    cout << "Type: " << type << endl;
    cout << "Width: " << width << endl;
    cout << "Length: " << length << endl;
    cout << "Y Position: " << yPos << endl;
    cout << "X Position: " << xPos << endl;
    cout << "Construction Cost: " << constructionCost << endl;
}

// New functions
double Infrastructure::getAverageSatisfactionScore() {
    return 0; // Infrastructure does not have a satisfaction score
}

int Infrastructure::getTotalWaterSupply() {
    return 0; // Infrastructure does not supply water
}

int Infrastructure::getTotalWaterUsage() {
    return 0; // Infrastructure does not use water
}

int Infrastructure::getTotalElectricitySupply() {
    return 0; // Infrastructure does not supply electricity
}

int Infrastructure::getTotalElectricityDemand() {
    return 0; // Infrastructure does not demand electricity
}

int Infrastructure::getTotalSewageCapacity() {
    return 0; // Infrastructure does not have sewage capacity
}

int Infrastructure::getTotalWasteCapacity() {
    return 0; // Infrastructure does not have waste capacity
}

int Infrastructure::getTotalWasteProduction() {
    return 0; // Infrastructure does not produce waste
}

int Infrastructure::getTotalSewageProduction() {
    return 0; // Infrastructure does not produce sewage
}

int Infrastructure::getTotalNumberOfJobs() {
    return 0; // Infrastructure does not provide jobs
}

