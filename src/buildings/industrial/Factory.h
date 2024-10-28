#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuilding.h"
class Factory : public IndustrialBuilding{

private:
	int satisfactionScore;
    int numberOfEmployees;
	int partProductionPerHour;
	int productionCostPerHour;
public:
	Factory(int id);
	~Factory();
	virtual void print() const override;
};

#endif
