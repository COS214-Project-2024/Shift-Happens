#include "Park.h"

Park::Park(int id)
    : LandMark(id, "Park", 100, 20, 20, 20, 20, 50)
{
}

Park::~Park()
{
}

void Park::print(){
    cout << "Park Attributes:" << endl;
    cout << "Width: " << getWidth() << endl;
    cout << "Length: " << getLength() << endl;
    cout << "X Position: " << getXPos() << endl;
    cout << "Y Position: " << getYPos() << endl;
    cout << "Construction Price: " << getConstructionPrice() << endl;
    cout << "Waste Produced: " << getWasteProduced() << endl;
    cout << "Sewage Produced: " << getSewageProduced() << endl;
    cout << "Electricity Demand: " << getElectricityDemand() << endl;
    cout << "Water Demand: " << getWaterDemand() << endl;
    LandMark::print(); // Call to LandMark's print function
}

// New functions
double Park::getAverageSatisfactionScore() {
    return LandMark::getAverageSatisfactionScore();
}

int Park::getTotalWaterSupply() {
    return LandMark::getTotalWaterSupply();
}

int Park::getTotalWaterUsage() {
    return LandMark::getTotalWaterUsage();
}

int Park::getTotalElectricitySupply() {
    return LandMark::getTotalElectricitySupply();
}

int Park::getTotalElectricityDemand() {
    return LandMark::getTotalElectricityDemand();
}

int Park::getTotalSewageCapacity() {
    return LandMark::getTotalSewageCapacity();
}

int Park::getTotalWasteCapacity() {
    return LandMark::getTotalWasteCapacity();
}

int Park::getTotalWasteProduction() {
    return LandMark::getTotalWasteProduction();
}

int Park::getTotalSewageProduction() {
    return LandMark::getTotalSewageProduction();
}

int Park::getTotalNumberOfJobs() {
    return LandMark::getTotalNumberOfJobs();
}