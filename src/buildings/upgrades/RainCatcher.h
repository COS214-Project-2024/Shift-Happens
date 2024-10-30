#ifndef RAINCATCHER_H
#define RAINCATCHER_H

#include "../Upgrade.h"

class RainCatcher : public Upgrade {
public:
    RainCatcher(shared_ptr<Building> building);
    int getWaterDemand() override;
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