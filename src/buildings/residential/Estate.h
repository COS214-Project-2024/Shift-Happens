#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"
#include <iostream>

class Estate : public ResidentialBuilding {
private:
    int satisfactionScore;
    int capacity;
    int incomePerHour;

public:
    Estate(int id);
    ~Estate();

    // Print function
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