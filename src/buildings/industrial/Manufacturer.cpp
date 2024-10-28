#include "Manufacturer.h"

Manufacturer::Manufacturer(int id)
: IndustrialBuilding(id, 100, "Manufacturer", 25, 250, 0, 0, 100, 100)
{
    this->productsPerHour = 100;
    this->partsUsedPerProduct = 3;
    this->profitPerProduct = 5;
}

Manufacturer::~Manufacturer()
{
}