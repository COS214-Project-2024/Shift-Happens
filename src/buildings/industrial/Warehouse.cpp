#include "Warehouse.h"
#include <iostream>

// Warehouse::Warehouse(int id)
// : IndustrialBuilding(id, 50, "Warehouse", 25, 250, 10, 10, 10, 10)
// {
//     this->storageCapacity = 600;
//     this->storageUsed = 0;
// }
Warehouse::Warehouse(int id)
    : IndustrialBuilding(id, 50, "Warehouse", 25, 250, 10, 10, 10, 10, statistics), satisfactionScore(25), numberOfEmployees(50), storageCapacity(600), storageUsed(0) {}

Warehouse::~Warehouse()
{
}

void Warehouse::print() const {
    cout << "Warehouse Attributes:" << endl;
    cout << "Storage Capacity: " << storageCapacity << endl;
    cout << "Storage Used: " << storageUsed << endl;
    IndustrialBuilding::print(); // Call to IndustrialBuilding's print function
}




