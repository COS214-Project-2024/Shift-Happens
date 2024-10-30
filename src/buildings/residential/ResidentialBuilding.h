#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "../Building.h"

class ResidentialBuilding : public Building
{
private:
    int capacity;
    int satisfactionScore;
    int incomePerHour;

public:
    ResidentialBuilding(int id, int capacity, std::string variant, int satisfactionScore, int incomePerHour, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);

    int getCapacity();
    void setCapacity(int capacity);

    int getSatisfactionScore();
    void setSatisfactionScore(int satisfactionScore);

    int getIncomePerHour();
    void setIncomePerHour(int incomePerHour);

    ~ResidentialBuilding();

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