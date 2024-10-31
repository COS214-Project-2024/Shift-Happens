#ifndef SOLAR_H
#define SOLAR_H

#include "../Upgrade.h"

class Solar : public Upgrade {
public:
    Solar(shared_ptr<Building> building);
    int getElectricityDemand() override;
    virtual void print() override;

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

#endif