#ifndef RECYCLING_H
#define RECYCLING_H

#include "../Upgrade.h"

class Recycling : public Upgrade {
public:
    Recycling(shared_ptr<Building> building);
    int getWasteProduced() override;
    virtual void print();
};

#endif