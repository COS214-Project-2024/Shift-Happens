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
    TransportBuilding(int id, int capacity, std::string variant, int maintenanceCost, int constructionCost, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);

    int getCapacity() const;
    void setCapacity(int capacity);

    int getMaintenanceCost() const;
    void setMaintenanceCost(int maintenanceCost);

    int getConstructionCost() const;
    void setConstructionCost(int constructionCost);

    virtual void print();

    ~TransportBuilding();

    // New functions
    double getAverageSatisfactionScore() override;
    int getTotalWaterSupply() override;
    int getTotalWaterUsage() override;
    int getTotalElectricitySupply() override;
    int getTotalElectricityDemand() override;
    int getTotalSewageCapacity() override;
    int getTotalWasteCapacity() override;
    int getTotalWasteProduction() override;
    int getTotalSewageProduction() override;
    int getTotalNumberOfJobs() override;
};

#endif // TRANSPORTBUILDING_H