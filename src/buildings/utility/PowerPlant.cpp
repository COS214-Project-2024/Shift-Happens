#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant(int id)
    : UtilityBuilding(id, "PowerPlant", 500, 10, 10, 0, 10, statistics), electricityProduction(500) {}

void PowerPlant::getElectricityProduction() {
	// TODO - implement PowerPlant::getElectricityProduction
	throw "Not yet implemented";
}

void PowerPlant::setElectricityProduction(int electricityProduction) {
	this->electricityProduction = electricityProduction;
}

//print function
void PowerPlant::print() const {
    cout << "PowerPlant Attributes:" << endl;
    cout << "Electricity Production: " << electricityProduction << endl;
    UtilityBuilding::print(); //UB print function called here
}