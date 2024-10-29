#include "Manufacturer.h"
#include <iostream>

// Manufacturer::Manufacturer(int id)
// : IndustrialBuilding(id, 100, "Manufacturer", 25, 250, 0, 0, 100, 100)
// {
//     this->productsPerHour = 100;
//     this->partsUsedPerProduct = 3;
//     this->profitPerProduct = 5;
// }
Manufacturer::Manufacturer(int id)
    : IndustrialBuilding(id, 100, "Manufacturer", 25, 250, 0, 0, 100, 100, statistics), satisfactionScore(25), numberOfEmployees(100), productsPerHour(100), partsUsedPerProduct(3), profitPerProduct(5) {}


Manufacturer::~Manufacturer()
{
}

void Manufacturer::print() const {
    cout << "Manufacturer Attributes:" << endl;
    cout << "Products per Hour: " << productsPerHour << endl;
    cout << "Parts Used per Product: " << partsUsedPerProduct << endl;
    cout << "Profit per Product: " << profitPerProduct << endl;
    IndustrialBuilding::print(); // Call to IndustrialBuilding's print function
}