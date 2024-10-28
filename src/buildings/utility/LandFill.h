#ifndef LANDFILL_H
#define LANDFILL_H

#include "UtilityBuilding.h"

class LandFill : public UtilityBuilding{

private:
	int wasteRemovalRate;
public:
	LandFill(int id);
	int getWasteRemovalRate();
	void setWasteRemovalRate(int wasteRemovalRate);
	virtual void print() const override; 
};

#endif
