#ifndef RECYCLING_H
#define RECYCLING_H

#include "Upgrade.h"

class Recycling : public Upgrade {
public:
    Recycling(Building* building);
    int getWasteProduced() override;
};

#endif