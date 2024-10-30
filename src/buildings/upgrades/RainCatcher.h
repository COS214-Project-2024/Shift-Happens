#ifndef RAINCATCHER_H
#define RAINCATCHER_H

#include "Upgrade.h"

class RainCatcher : public Upgrade {
public:
    RainCatcher(Building* building);
    int getWaterDemand() override;
};

#endif