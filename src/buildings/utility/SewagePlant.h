#ifndef SEWAGEPLANT_H
#define SEWAGEPLANT_H

#include "UtilityBuilding.h"

class SewagePlant : public UtilityBuilding {
private:
    int sewageRemovalRate;

public:
    SewagePlant(int id);
    int getSewageRemovalRate();
    void setSewageRemovalRate(int sewageRemovalRate);
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