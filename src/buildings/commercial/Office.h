#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuilding.h"

class Office : public CommercialBuilding {
public:
    Office(int id);
    ~Office();

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
