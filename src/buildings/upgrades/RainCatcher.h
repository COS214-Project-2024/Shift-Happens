#ifndef RAINCATCHER_H
#define RAINCATCHER_H

#include "../Upgrade.h"

class RainCatcher : public Upgrade {
public:
    RainCatcher(shared_ptr<Building> building);
    int getWaterDemand() override;
    virtual void print();
};

#endif