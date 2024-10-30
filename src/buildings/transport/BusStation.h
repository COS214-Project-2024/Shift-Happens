#ifndef BUSSTATION_H
#define BUSSTATION_H

#include "TransportBuilding.h"

class BusStation : public TransportBuilding
{
public:
    BusStation(int id);
    ~BusStation();
    void print();
};

#endif // BUSSTATION_H