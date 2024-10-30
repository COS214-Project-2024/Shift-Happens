#ifndef GARDEN_H
#define GARDEN_H

#include "Upgrade.h"

class Garden : public Upgrade {
public:
    Garden(Building* building);
    int getSewageProduced() override;
};

#endif