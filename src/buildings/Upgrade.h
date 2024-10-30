#ifndef UPGRADE_H
#define UPGRADE_H

#include "Building.h"

class Upgrade : public Building {
protected:
    Building* building;
public:
    Upgrade(Building* building);
    virtual ~Upgrade();

    virtual int getWasteProduced() ;
    virtual void setWasteProduced(int wasteProduced) ;

    virtual int getSewageProduced() ;
    virtual void setSewageProduced(int sewageProduced) ;

    virtual int getElectricityDemand() ;
    virtual void setElectricityDemand(int electricityDemand) ;

    virtual int getWaterDemand() ;
    virtual void setWaterDemand(int waterDemand) ;
};

#endif