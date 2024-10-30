#ifndef BUSSTATION_H
#define BUSSTATION_H

#include "TransportBuilding.h"

class BusStation : public TransportBuilding
{
public:
    BusStation(int id);
    ~BusStation();
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

#endif // BUSSTATION_H