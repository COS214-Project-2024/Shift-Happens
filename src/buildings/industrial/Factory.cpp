#include "Factory.h"
#include <iostream>

// Factory::Factory(int id)
// : IndustrialBuilding(id, 100, "Factory", 25, 250, 50, 50, 50, 50)
// {
//     this->partProductionPerHour = 300;
//     this->productionCostPerHour = 100;
// }
Factory::Factory(int id)
    : IndustrialBuilding(id, 100, "Factory", 25, 250, 50, 50, 50, 50), satisfactionScore(25), numberOfEmployees(100), partProductionPerHour(300), productionCostPerHour(100) {}


Factory::~Factory()
{
}

void Factory::print() const {
    cout << "Factory Attributes:" << endl;
    cout << "Part Production per Hour: " << partProductionPerHour << endl;
    cout << "Production Cost per Hour: " << productionCostPerHour << endl;
    IndustrialBuilding::print(); // Call to IndustrialBuilding's print function
}