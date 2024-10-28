#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "UtilityBuilding.h"

class WaterSupply : public UtilityBuilding{
private:
	int waterSupply;
public:	
	WaterSupply(int id);
	int getWaterSupply();
	void setWaterSupply(int waterSupply);
	virtual void print() const override;
};

#endif
