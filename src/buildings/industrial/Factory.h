#ifndef FACTORY_H
#define FACTORY_H
#include "IndustrialBuilding.h"

class Factory : public IndustrialBuilding {
private:
    int satisfactionScore;
    int numberOfEmployees;
    int partProductionPerHour;
    int productionCostPerHour;

public:
    Factory(int id);
    ~Factory();
    virtual void print();

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