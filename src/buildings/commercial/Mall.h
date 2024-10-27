#ifndef MALL_H
#define MALL_H

#include "CommercialBuilding.h"

class Mall : public CommercialBuilding
{

private:
public:
	Mall(int id, string name, int incomePerHour, string variant, int satisfactionScore, int numberOfEmployees, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);
	~Mall();
};

#endif
