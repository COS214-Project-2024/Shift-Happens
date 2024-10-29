#include "TownHouse.h"

TownHouse::TownHouse(int id)
    : ResidentialBuilding(id, 20, "TownHouse", 75, 40, 200, 10, 10, 10, 10, statistics), satisfactionScore(75), capacity(20), incomePerHour(40) {}

TownHouse::~TownHouse()
{
}

void TownHouse::print() const {
    std::cout << "TownHouse Attributes:" << std::endl;
    std::cout << "Satisfaction Score: " << satisfactionScore << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Income per Hour: " << incomePerHour << std::endl;
    ResidentialBuilding::print(); 
}
