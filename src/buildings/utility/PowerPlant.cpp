#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant(int id)
    : UtilityBuilding(id, "PowerPlant", 500, 10, 10, 0, 10), electricityProduction(500) {}

double PowerPlant::getElectricityProduction() {

    return electricityProduction;
}

void PowerPlant::setElectricityProduction(int electricityProduction) {
	this->electricityProduction = electricityProduction;
}

//print function
void PowerPlant::print() {
    cout << "PowerPlant Attributes:" << endl;
    cout << "Electricity Production: " << electricityProduction << endl;
    UtilityBuilding::print(); //UB print function called here
}