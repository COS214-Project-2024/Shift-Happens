#include "LandMark.h"

LandMark::LandMark(int id, string variant, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand, int satisfactionScore)
: Building(id, 1, 1, -1, -1, variant, "LandMark", constructionPrice, wasteProduced, sewageProduced, electricityDemand, waterDemand)
{
    this->variant = variant;
    this->satisfactionScore = satisfactionScore;
}

int LandMark::getSatisfactionScore() {
    return this->satisfactionScore;
}

void LandMark::setSatisfactionScore(int satisfactionScore) {
    this->satisfactionScore = satisfactionScore;
}

void LandMark::render() {
    throw "LandMark::render() not yet implemented";
}




LandMark::~LandMark() {
}

void LandMark::print() {
    std::cout << "LandMark" << std::endl;
    std::cout << "ID: " << this->getId() << std::endl;
    std::cout << "Variant: " << this->variant << std::endl;
    std::cout << "Construction Price: " << this->getConstructionPrice() << std::endl;
    std::cout << "Waste Produced: " << this->getWasteProduced() << std::endl;
    std::cout << "Sewage Produced: " << this->getSewageProduced() << std::endl;
    std::cout << "Electricity Demand: " << this->getElectricityDemand() << std::endl;
    std::cout << "Water Demand: " << this->getWaterDemand() << std::endl;
    std::cout << "Satisfaction Score: " << this->satisfactionScore << std::endl;
}

// New functions
double LandMark::getAverageSatisfactionScore() {
    return static_cast<double>(satisfactionScore);
}

int LandMark::getTotalWaterSupply() {
    return 0; // LandMark buildings do not supply water
}

int LandMark::getTotalWaterUsage() {
    return getWaterDemand();
}

int LandMark::getTotalElectricitySupply() {
    return 0; // LandMark buildings do not supply electricity
}

int LandMark::getTotalElectricityDemand() {
    return getElectricityDemand();
}

int LandMark::getTotalSewageCapacity() {
    return 0; // LandMark buildings do not have sewage capacity
}

int LandMark::getTotalWasteCapacity() {
    return 0; // LandMark buildings do not have waste capacity
}

int LandMark::getTotalWasteProduction() {
    return getWasteProduced();
}

int LandMark::getTotalSewageProduction() {
    return getSewageProduced();
}

int LandMark::getTotalNumberOfJobs() {
    return 0; // LandMark buildings do not provide jobs
}