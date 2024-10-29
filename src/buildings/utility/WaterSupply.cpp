#include "WaterSupply.h"
#include <iostream>

WaterSupply::WaterSupply(int id)
    : UtilityBuilding(id, "WaterSupply", 500, 10, 10, 10, 0, statistics), waterSupply(500) {}

double WaterSupply::getWaterSupply() {
    return waterSupply;
}

void WaterSupply::setWaterSupply(int waterSupply) {
    this->waterSupply = waterSupply;
}

void WaterSupply::print() const {
    std::cout << "WaterSupply Attributes:" << std::endl;
    std::cout << "Water Supply: " << waterSupply << std::endl;
    UtilityBuilding::print(); // UtilityBuilding's print function
}
