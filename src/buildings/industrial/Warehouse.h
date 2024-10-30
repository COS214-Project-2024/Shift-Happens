#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "IndustrialBuilding.h"
class Warehouse : public IndustrialBuilding{

private:
	int satisfactionScore;
    int numberOfEmployees;
	int storageCapacity;
	int storageUsed;

public:
	Warehouse(int id);
	~Warehouse();
	virtual void print();
};

#endif
