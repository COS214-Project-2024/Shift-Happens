#include "Railway.h"
#include <iostream>

Railway::Railway(int id)
: Infrastructure("Railway", id)
{
}

Railway::~Railway()
{
}

void Railway::print()
{
    cout << "Railway" << endl;
    Infrastructure::print(); // Call to Infrastructure's print function
}

// New functions
double Railway::getAverageSatisfactionScore() {
    return Infrastructure::getAverageSatisfactionScore();
}

int Railway::getTotalWaterSupply() {
    return Infrastructure::getTotalWaterSupply();
}

int Railway::getTotalWaterUsage() {
    return Infrastructure::getTotalWaterUsage();
}

int Railway::getTotalElectricitySupply() {
    return Infrastructure::getTotalElectricitySupply();
}

int Railway::getTotalElectricityDemand() {
    return Infrastructure::getTotalElectricityDemand();
}

int Railway::getTotalSewageCapacity() {
    return Infrastructure::getTotalSewageCapacity();
}

int Railway::getTotalWasteCapacity() {
    return Infrastructure::getTotalWasteCapacity();
}

int Railway::getTotalWasteProduction() {
    return Infrastructure::getTotalWasteProduction();
}

int Railway::getTotalSewageProduction() {
    return Infrastructure::getTotalSewageProduction();
}

int Railway::getTotalNumberOfJobs() {
    return Infrastructure::getTotalNumberOfJobs();
}