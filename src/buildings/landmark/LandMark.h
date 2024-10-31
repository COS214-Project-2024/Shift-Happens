#ifndef LANDMARK_H
#define LANDMARK_H

#include "../Building.h"
class LandMark : public Building
{

protected:
    string variant;
    int satisfactionScore;

public:
    LandMark(int id, string variant, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand, int satisfactionScore);

    int getSatisfactionScore();

    void setSatisfactionScore(int satisfactionScore);

    void render();

    void print();

    ~LandMark();

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
