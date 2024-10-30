#include "BusStation.h"

BusStation::BusStation(int id) : TransportBuilding(id, 200, "BusStation", 1000, 50000, 50, 50, 100, 100)
{
}

BusStation::~BusStation()
{
}

void BusStation::print()
{
    cout << "Bus Station Attributes:" << endl;
    TransportBuilding::print();
}