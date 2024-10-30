#include "Airport.h"

Airport::Airport(int id) : TransportBuilding(id, 1000, "Airport", 5000, 1000000, 100, 100, 500, 500)
{
}

Airport::~Airport()
{
}

void Airport::print()
{
    std::cout << "Airport Attributes:" << std::endl;
    TransportBuilding::print();
}
