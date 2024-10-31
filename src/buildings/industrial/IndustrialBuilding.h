#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H
#include "../Building.h"
#include <vector>
#include <iostream>

class IndustrialBuilding : public Building {

private:
    int numberOfEmployees;
    int satisfactionScore;

public:
    IndustrialBuilding(int id, int numberOfEmployees, std::string variant, int satisfactionScore, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);

    int getNumberOfEmployees();
    void setNumberOfEmployees(int numberOfEmployees);

    int getSatisfactionScore();
    void setSatisfactionScore(int satisfactionScore);

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