#ifndef CULTURALCENTER_H
#define CULTURALCENTER_H

#include "LandMark.h"
class CulturalCenter : public LandMark
{
public:
    CulturalCenter(int id);
    ~CulturalCenter();
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

#endif