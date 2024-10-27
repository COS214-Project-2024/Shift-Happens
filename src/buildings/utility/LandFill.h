#ifndef LANDFILL_H
#define LANDFILL_H

#include "UtilityBuilding.h"

class LandFill : public UtilityBuilding
{

public:
	int wasteRemovalRate;

	int getWasteRemovalRate();

	void setWasteRemovalRate(int wasteRemovalRate);
};

#endif
