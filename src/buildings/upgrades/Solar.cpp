#include "Solar.h"

Solar::Solar(shared_ptr<Building> building) : Upgrade(building) {
    type = "Solar";
}

int Solar::getElectricityDemand() {
    return 0; // Set electricity demand to 0
}

void Solar::print() {
    //prints the building's attributes with the 0 electricity demand and upgrade type
    cout << "Building Attributes:" << endl;
    cout << "Width: " << building->getWidth() << ", Length: " << building->getLength() << endl;
    cout << "Position: (" << building->getXPos() << ", " << building->getYPos() << ")" << endl;
    cout << "Type: " << building->getType() << ", Variant: " << building->getVariant() << endl;
    cout << "Upgrade Type: " << type << endl;
    cout << "Construction Price: " << building->getConstructionPrice() << endl;
    cout << "Waste Produced: " << building->getWasteProduced() << ", Sewage Produced: " << building->getSewageProduced() << endl;
    cout << "Electricity Demand: " << 0 << ", Water Demand: " << building->getWaterDemand() << endl;
}

// New functions
double Solar::getAverageSatisfactionScore() {
    return building->getAverageSatisfactionScore();
}

int Solar::getTotalWaterSupply() {
    return building->getTotalWaterSupply();
}

int Solar::getTotalWaterUsage() {
    return building->getTotalWaterUsage();
}

int Solar::getTotalElectricitySupply() {
    return building->getTotalElectricitySupply();
}

int Solar::getTotalElectricityDemand() {
    return getElectricityDemand();
}

int Solar::getTotalSewageCapacity() {
    return building->getTotalSewageCapacity();
}

int Solar::getTotalWasteCapacity() {
    return building->getTotalWasteCapacity();
}

int Solar::getTotalWasteProduction() {
    return building->getTotalWasteProduction();
}

int Solar::getTotalSewageProduction() {
    return building->getTotalSewageProduction();
}

int Solar::getTotalNumberOfJobs() {
    return building->getTotalNumberOfJobs();
}