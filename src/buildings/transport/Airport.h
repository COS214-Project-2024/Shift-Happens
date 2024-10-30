#ifndef AIRPORT_H
#define AIRPORT_H

#include "TransportBuilding.h"

class Airport : public TransportBuilding
{
public:
    Airport(int id);
    ~Airport();

    void print();
};

#endif // AIRPORT_H