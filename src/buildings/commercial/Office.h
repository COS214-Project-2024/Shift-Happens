#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuilding.h"

class Office : public CommercialBuilding
{
private:
	/* data */
public:
	Office(int id, string name, int incomePerHour, string variant, int satisfactionScore, int numberOfEmployees, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);
	~Office();
};



#endif
