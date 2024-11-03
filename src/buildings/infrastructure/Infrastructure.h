#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include "../../map/MapComponent.h"
#include <string>

using namespace std;

class Infrastructure : public MapComponent
{
protected:
    string variant;
    string type;
    int width;
    int length;
    int yPos;
    int xPos;
    int constructionCost;

public:
    Infrastructure(string variant, int id);
    virtual ~Infrastructure();

    int getWidth();
    void setWidth(int width);

    int getLength();
    void setLength(int length);

    int getYPos();
    void setYPos(int yPos);

    int getXPos();
    void setXPos(int xPos);

    int getConstructionCost();
    void setConstructionCost(int constructionCost);

    void render();

    
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
