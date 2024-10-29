#include "TrainStation.h"

TrainStation::TrainStation(int id) :
    TransportBuilding(id, 500, "TrainStation", 2000, 200000, 75, 75, 200, 200, statistics)
{
}

TrainStation::~TrainStation()
{
}