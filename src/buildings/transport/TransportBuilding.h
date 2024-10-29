#ifndef TRANSPORTBUILDING_H
#define TRANSPORTBUILDING_H

#include "../Building.h"
#include <string>

class TransportBuilding : public Building
{
private:
    int capacity;
    int maintenanceCost;
    int constructionCost;

public:
    TransportBuilding(int id, int capacity, std::string variant, int maintenanceCost, int constructionCost, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand, Statistics* statistics);

    int getCapacity() const;
    void setCapacity(int capacity);

    int getMaintenanceCost() const;
    void setMaintenanceCost(int maintenanceCost);

    int getConstructionCost() const;
    void setConstructionCost(int constructionCost);

    ~TransportBuilding();
};

#endif // TRANSPORTBUILDING_H

