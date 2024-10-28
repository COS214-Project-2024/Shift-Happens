#ifndef SEWAGEPLANT_H
#define SEWAGEPLANT_H

#include "UtilityBuilding.h"

class SewagePlant : public UtilityBuilding{

private:
	int sewageRemovalRate;
public:
	SewagePlant(int id);
	int getSewageRemovalRate();
	void setSewageRemovalRate(int sewageRemovalRate);
	virtual void print() const override;
};

#endif
