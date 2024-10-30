#ifndef SOLAR_H
#define SOLAR_H

#include "Upgrade.h"

class Solar : public Upgrade {
public:
    Solar(Building* building);
    int getElectricityDemand() override;
};

#endif