#ifndef LANDFILL_H
#define LANDFILL_H

#include "UtilityBuilding.h"

class LandFill : public UtilityBuilding {
private:
    int wasteRemovalRate;

public:
    LandFill(int id);
    int getWasteRemovalRate();
    void setWasteRemovalRate(int wasteRemovalRate);
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