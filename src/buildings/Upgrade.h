#ifndef UPGRADE_H
#define UPGRADE_H

#include "Building.h"
#include <string>
#include <memory>

class Upgrade : public Building {
protected:
    shared_ptr<Building> building;
    string type;
public:
    Upgrade(shared_ptr<Building> building);
    virtual ~Upgrade();

    virtual int getWasteProduced() ;
    virtual void setWasteProduced(int wasteProduced) ;

    virtual int getSewageProduced() ;
    virtual void setSewageProduced(int sewageProduced) ;

    virtual int getElectricityDemand() ;
    virtual void setElectricityDemand(int electricityDemand) ;

    virtual int getWaterDemand() ;
    virtual void setWaterDemand(int waterDemand) ;

    string getUpgradeType();
};

#endif