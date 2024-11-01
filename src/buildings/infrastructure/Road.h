#ifndef ROAD_H
#define ROAD_H
#include "Infrastructure.h"

class Road : public Infrastructure
{
public:
    Road(int id);
    ~Road();

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

    string getType() override;
    string getVariant() override;
};

#endif