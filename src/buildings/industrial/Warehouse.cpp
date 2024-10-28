#include "Warehouse.h"

Warehouse::Warehouse(int id)
: IndustrialBuilding(id, 50, "Warehouse", 25, 250, 10, 10, 10, 10)
{
    this->storageCapacity = 600;
    this->storageUsed = 0;
}

Warehouse::~Warehouse()
{
}





