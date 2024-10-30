#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "TransportBuilding.h"

class TrainStation : public TransportBuilding
{
public:
    TrainStation(int id);
    ~TrainStation();
    void print() override;

    // New functions
    double getAverageSatisfactionScore() override;
    int getTotalWaterSupply() override;
    int getTotalWaterUsage() override;
    int getTotalElectricitySupply() override;
    int getTotalElectricityDemand() override;
    int getTotalSewageCapacity() override;
    int getTotalWasteCapacity() override;
    int getTotalWasteProduction() override;
    int getTotalSewageProduction() override;
    int getTotalNumberOfJobs() override;
};

#endif // TRAINSTATION_H