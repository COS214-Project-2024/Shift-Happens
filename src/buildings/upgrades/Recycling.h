#ifndef RECYCLING_H
#define RECYCLING_H

#include "../Upgrade.h"

class Recycling : public Upgrade {
public:
    Recycling(shared_ptr<Building> building);
    int getWasteProduced() override;
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