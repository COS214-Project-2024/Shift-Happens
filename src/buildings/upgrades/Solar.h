#ifndef SOLAR_H
#define SOLAR_H
#include "Upgrade.h"
	class Solar : public Upgrade {


	public:
		virtual int getWasteProduced() = 0;

		virtual void setWasteProduced(int wasteProduced) = 0;

		virtual int getSewageProduced() = 0;

		virtual void setSewageProduced(int sewageProduced) = 0;

		virtual int getElectricityDemand() = 0;

		virtual void setElectricityDemand(int electricityDemand) = 0;

		virtual int getWaterDemand() = 0;

		virtual void setWaterDemand(int waterDemand) = 0;
	};

#endif
