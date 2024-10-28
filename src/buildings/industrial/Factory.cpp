#include "Factory.h"

Factory::Factory(int id)
: IndustrialBuilding(id, 100, "Factory", 25, 250, 50, 50, 50, 50)
{
    this->partProductionPerHour = 300;
    this->productionCostPerHour = 100;
}

Factory::~Factory()
{
}