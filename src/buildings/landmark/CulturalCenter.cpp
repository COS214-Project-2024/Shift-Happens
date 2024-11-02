#include "CulturalCenter.h"

CulturalCenter::CulturalCenter(int id)
    : LandMark(id, "CulturalCenter", 400, 20, 20, 20, 20, 50)
{
}

CulturalCenter::~CulturalCenter()
{
}

void CulturalCenter::print(){
    cout << "Cultural Center Attributes:" << endl;
    cout << "Construction Price: " << getConstructionPrice() << endl;
    cout << "Waste Produced: " << getWasteProduced() << endl;
    cout << "Sewage Produced: " << getSewageProduced() << endl;
    cout << "Electricity Demand: " << getElectricityDemand() << endl;
    cout << "Water Demand: " << getWaterDemand() << endl;
    LandMark::print(); // Call to LandMark's print function
}

// New functions
double CulturalCenter::getAverageSatisfactionScore() {
    return LandMark::getAverageSatisfactionScore();
}

int CulturalCenter::getTotalWaterSupply() {
    return LandMark::getTotalWaterSupply();
}

int CulturalCenter::getTotalWaterUsage() {
    return LandMark::getTotalWaterUsage();
}

int CulturalCenter::getTotalElectricitySupply() {
    return LandMark::getTotalElectricitySupply();
}

int CulturalCenter::getTotalElectricityDemand() {
    return LandMark::getTotalElectricityDemand();
}

int CulturalCenter::getTotalSewageCapacity() {
    return LandMark::getTotalSewageCapacity();
}

int CulturalCenter::getTotalWasteCapacity() {
    return LandMark::getTotalWasteCapacity();
}

int CulturalCenter::getTotalWasteProduction() {
    return LandMark::getTotalWasteProduction();
}

int CulturalCenter::getTotalSewageProduction() {
    return LandMark::getTotalSewageProduction();
}

int CulturalCenter::getTotalNumberOfJobs() {
    return LandMark::getTotalNumberOfJobs();
}