#ifndef GARDEN_H
#define GARDEN_H

#include "../Upgrade.h"

class Garden : public Upgrade {
public:
    Garden(shared_ptr<Building> building);
    int getSewageProduced() override;
    virtual void print();
};

#endif