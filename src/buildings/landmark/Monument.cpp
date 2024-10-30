#include "Monument.h"

Monument::Monument(int id)
    : LandMark(id, "Monument", 500, 20, 20, 20, 20, 50)
{
}

Monument::~Monument()
{
}

void Monument::print(){
    cout << "Monument Attributes:" << endl;
    cout << "Construction Price: " << getConstructionPrice() << endl;
    cout << "Waste Produced: " << getWasteProduced() << endl;
    cout << "Sewage Produced: " << getSewageProduced() << endl;
    cout << "Electricity Demand: " << getElectricityDemand() << endl;
    cout << "Water Demand: " << getWaterDemand() << endl;
    LandMark::print(); // Call to LandMark's print function
}

// New functions
double Monument::getAverageSatisfactionScore() {
    return LandMark::getAverageSatisfactionScore();
}

int Monument::getTotalWaterSupply() {
    return LandMark::getTotalWaterSupply();
}

int Monument::getTotalWaterUsage() {
    return LandMark::getTotalWaterUsage();
}

int Monument::getTotalElectricitySupply() {
    return LandMark::getTotalElectricitySupply();
}

int Monument::getTotalElectricityDemand() {
    return LandMark::getTotalElectricityDemand();
}

int Monument::getTotalSewageCapacity() {
    return LandMark::getTotalSewageCapacity();
}

int Monument::getTotalWasteCapacity() {
    return LandMark::getTotalWasteCapacity();
}

int Monument::getTotalWasteProduction() {
    return LandMark::getTotalWasteProduction();
}

int Monument::getTotalSewageProduction() {
    return LandMark::getTotalSewageProduction();
}

int Monument::getTotalNumberOfJobs() {
    return LandMark::getTotalNumberOfJobs();
}