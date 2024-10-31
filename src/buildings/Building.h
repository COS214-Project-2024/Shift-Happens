#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include <memory>
#include <string>
#include "../map/MapComponent.h"

class Building : public MapComponent {
private:
    int width;
    int xPos;
    int yPos;
    int constructionPrice;
    int length;
    std::string variant;
    std::string type;
    int wasteProduced;
    int sewageProduced;
    int electricityDemand;
    int waterDemand;

protected:

public:
    Building(int id, int width, int length, int xPos, int yPos, std::string variant, std::string type, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);
    Building(shared_ptr<Building> building);
    
    int getWidth();

    virtual void render();

    virtual void setWidth(int width);

    virtual int getLength();
    virtual void setLength(int length);

    virtual int getXPos();
    virtual void setXPos(int xPos);

    virtual int getYPos();
    virtual void setYPos(int yPos);

    virtual std::string getVariant();
    virtual void setVariant(std::string variant);

    virtual std::string getType();
    virtual void setType(std::string type);

    virtual int getConstructionPrice();
    virtual void setConstructionPrice(int constructionPrice);

    virtual int getWasteProduced();
    virtual void setWasteProduced(int wasteProduced);

    virtual int getSewageProduced();
    virtual void setSewageProduced(int sewageProduced);

    virtual int getElectricityDemand();
    virtual void setElectricityDemand(int electricityDemand);

    virtual int getWaterDemand();
    virtual void setWaterDemand(int waterDemand);

    virtual void print() const;
};

#endif
