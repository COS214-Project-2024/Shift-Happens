#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "TransportBuilding.h"

class TrainStation : public TransportBuilding
{
public:
    TrainStation(int id);
    ~TrainStation();
};

#endif // TRAINSTATION_H