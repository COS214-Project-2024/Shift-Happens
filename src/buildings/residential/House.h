#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"
#include <iostream>

class House : public ResidentialBuilding {
private:
    int satisfactionScore;
    int capacity;
    int incomePerHour;

public:
    House(int id);
    ~House();

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