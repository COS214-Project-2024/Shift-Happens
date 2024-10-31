#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "UtilityBuilding.h"

class PowerPlant : public UtilityBuilding
{
private:
    int electricityProduction;

public:
    PowerPlant(int id);
    double getElectricityProduction();
    void setElectricityProduction(int electricityProduction);
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