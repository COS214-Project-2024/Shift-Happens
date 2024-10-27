#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "UtilityBuilding.h"

class WaterSupply : public UtilityBuilding
{

public:
	int waterSupply;

	int getWaterSupply();

	void setWaterSupply(int waterSupply);
};

#endif
