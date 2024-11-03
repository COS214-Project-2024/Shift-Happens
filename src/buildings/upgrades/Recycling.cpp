#include "Recycling.h"

Recycling::Recycling(shared_ptr<Building> building) : Upgrade(building) {
    type = "Recycling";
}

int Recycling::getWasteProduced() {
    return 0; // Set waste produced to 0
}

void Recycling::print() {
    //prints the building's attributes with the 0 waste produced and upgrade type
    cout << "Building Attributes:" << endl;
    cout << "Width: " << building->getWidth() << ", Length: " << building->getLength() << endl;
    cout << "Position: (" << building->getXPos() << ", " << building->getYPos() << ")" << endl;
    cout << "Type: " << building->getType() << ", Variant: " << building->getVariant() << endl;
    cout << "Upgrade Type: " << type << endl;
    cout << "Construction Price: " << building->getConstructionPrice() << endl;
    cout << "Waste Produced: " << 0 << ", Sewage Produced: " << building->getSewageProduced() << endl;
    cout << "Electricity Demand: " << building->getElectricityDemand() << ", Water Demand: " << building->getWaterDemand() << endl;
}

// New functions
double Recycling::getAverageSatisfactionScore() {
    return building->getAverageSatisfactionScore();
}

int Recycling::getTotalWaterSupply() {
    return building->getTotalWaterSupply();
}

int Recycling::getTotalWaterUsage() {
    return building->getTotalWaterUsage();
}

int Recycling::getTotalElectricitySupply() {
    return building->getTotalElectricitySupply();
}

int Recycling::getTotalElectricityDemand() {
    return building->getTotalElectricityDemand();
}

int Recycling::getTotalSewageCapacity() {
    return building->getTotalSewageCapacity();
}

int Recycling::getTotalWasteCapacity() {
    return building->getTotalWasteCapacity();
}

int Recycling::getTotalWasteProduction() {
    return getWasteProduced();
}

int Recycling::getTotalSewageProduction() {
    return building->getTotalSewageProduction();
}

int Recycling::getTotalNumberOfJobs() {
    return building->getTotalNumberOfJobs();
}