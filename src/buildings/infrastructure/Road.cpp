#include "Road.h"
#include <iostream>

Road::Road(int id)
: Infrastructure("Road", id)
{
}

Road::~Road()
{
}

void Road::print()
{
    cout << "Road" << endl;
    Infrastructure::print(); // Call to Infrastructure's print function
}

// New functions
double Road::getAverageSatisfactionScore() {
    return 75;
}

int Road::getTotalWaterSupply() {
    return 0;
}

int Road::getTotalWaterUsage() {
    return 0;
}

int Road::getTotalElectricitySupply() {
    return 0;
}

int Road::getTotalElectricityDemand() {
    return 0;
}

int Road::getTotalSewageCapacity() {
    return 0;
}

int Road::getTotalWasteCapacity() {
    return 0;
}

int Road::getTotalWasteProduction() {
    return 0;
}

int Road::getTotalSewageProduction() {
    return 0;
}

int Road::getTotalNumberOfJobs() {
    return 0;
}

string Road::getType() {
    return "Infrastructure";
}

string Road::getVariant() {
    return "Road";
}