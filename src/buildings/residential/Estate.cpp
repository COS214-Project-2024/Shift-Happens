#include "Estate.h"

Estate::Estate(int id)
    : ResidentialBuilding(id, 80, "Estate", 75, 160, 800, 40, 40, 40, 40), satisfactionScore(75), capacity(80), incomePerHour(160) {}

Estate::~Estate()
{
}

void Estate::print() const {
    std::cout << "Estate Attributes:" << std::endl;
    std::cout << "Satisfaction Score: " << satisfactionScore << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Income per Hour: " << incomePerHour << std::endl;
    ResidentialBuilding::print(); 
}