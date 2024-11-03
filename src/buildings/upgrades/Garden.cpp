#include "Garden.h"

Garden::Garden(shared_ptr<Building> building) : Upgrade(building) {
    type = "Garden";
}

int Garden::getSewageProduced() {
    return 0; // Set sewage produced to 0
}

void Garden::print() {
    //prints the building's attributes with the 0 sewage produced and upgrade type
    cout << "Building Attributes:" << endl;
    cout << "Width: " << building->getWidth() << ", Length: " << building->getLength() << endl;
    cout << "Position: (" << building->getXPos() << ", " << building->getYPos() << ")" << endl;
    cout << "Type: " << building->getType() << ", Variant: " << building->getVariant() << endl;
    cout << "Upgrade Type: " << type << endl;
    cout << "Construction Price: " << building->getConstructionPrice() << endl;
    cout << "Waste Produced: " << building->getWasteProduced() << ", Sewage Produced: " << 0 << endl;
    cout << "Electricity Demand: " << building->getElectricityDemand() << ", Water Demand: " << building->getWaterDemand() << endl;
}

// New functions
double Garden::getAverageSatisfactionScore() {
    return building->getAverageSatisfactionScore();
}

int Garden::getTotalWaterSupply() {
    return building->getTotalWaterSupply();
}

int Garden::getTotalWaterUsage() {
    return building->getTotalWaterUsage();
}

int Garden::getTotalElectricitySupply() {
    return building->getTotalElectricitySupply();
}

int Garden::getTotalElectricityDemand() {
    return building->getTotalElectricityDemand();
}

int Garden::getTotalSewageCapacity() {
    return building->getTotalSewageCapacity();
}

int Garden::getTotalWasteCapacity() {
    return building->getTotalWasteCapacity();
}

int Garden::getTotalWasteProduction() {
    return building->getTotalWasteProduction();
}

int Garden::getTotalSewageProduction() {
    return getSewageProduced();
}

int Garden::getTotalNumberOfJobs() {
    return building->getTotalNumberOfJobs();
}