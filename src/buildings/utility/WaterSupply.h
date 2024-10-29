#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "UtilityBuilding.h"

class WaterSupply : public UtilityBuilding{
private:
	int waterSupply;
public:	
	WaterSupply(int id);
	double getWaterSupply();
	void setWaterSupply(int waterSupply);
	virtual void print();
};

#endif
