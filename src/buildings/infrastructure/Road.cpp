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
    return Infrastructure::getAverageSatisfactionScore();
}

int Road::getTotalWaterSupply() {
    return Infrastructure::getTotalWaterSupply();
}

int Road::getTotalWaterUsage() {
    return Infrastructure::getTotalWaterUsage();
}

int Road::getTotalElectricitySupply() {
    return Infrastructure::getTotalElectricitySupply();
}

int Road::getTotalElectricityDemand() {
    return Infrastructure::getTotalElectricityDemand();
}

int Road::getTotalSewageCapacity() {
    return Infrastructure::getTotalSewageCapacity();
}

int Road::getTotalWasteCapacity() {
    return Infrastructure::getTotalWasteCapacity();
}

int Road::getTotalWasteProduction() {
    return Infrastructure::getTotalWasteProduction();
}

int Road::getTotalSewageProduction() {
    return Infrastructure::getTotalSewageProduction();
}

int Road::getTotalNumberOfJobs() {
    return Infrastructure::getTotalNumberOfJobs();
}