#ifndef SEWAGEPLANT_H
#define SEWAGEPLANT_H

#include "UtilityBuilding.h"

class SewagePlant : public UtilityBuilding
{

public:
	int sewageRemovalRate;

	int getSewageRemovalRate();

	void setSewageRemovalRate(int sewageRemovalRate);
};

#endif
