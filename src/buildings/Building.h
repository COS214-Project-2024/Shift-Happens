#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
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
    int getWidth();

    bool add(MapComponent *component);
    bool remove(MapComponent *component);
    void getComponent(int id);
    void render();

    void setWidth(int width);

    int getLength();
    void setLength(int length);

    int getXPos();
    void setXPos(int xPos);

    int getYPos();
    void setYPos(int yPos);

    std::string getVariant();
    void setVariant(std::string variant);

    std::string getType();
    void setType(std::string type);

    int getConstructionPrice();
    void setConstructionPrice(int constructionPrice);

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
