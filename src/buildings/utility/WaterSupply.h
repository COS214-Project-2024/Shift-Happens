#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "UtilityBuilding.h"

class WaterSupply : public UtilityBuilding {
private:
    int waterSupply;

public:
    WaterSupply(int id);
    double getWaterSupply();
    void setWaterSupply(int waterSupply);
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