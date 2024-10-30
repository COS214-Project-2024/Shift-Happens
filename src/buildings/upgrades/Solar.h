#ifndef SOLAR_H
#define SOLAR_H

#include "../Upgrade.h"


class Solar : public Upgrade {
public:
    Solar(shared_ptr<Building> building);
    int getElectricityDemand() override;
    virtual void print();
};

#endif