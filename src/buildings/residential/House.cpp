#include "House.h"

House::House(int id)
    : ResidentialBuilding(id, 40, "House", 75, 80, 400, 20, 20, 20, 20), satisfactionScore(75), capacity(40), incomePerHour(80) {}

House::~House()
{
}

void House::print() const {
    std::cout << "House Attributes:" << std::endl;
    std::cout << "Satisfaction Score: " << satisfactionScore << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Income per Hour: " << incomePerHour << std::endl;
    ResidentialBuilding::print(); 
}
