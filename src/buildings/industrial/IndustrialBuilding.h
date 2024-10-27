#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include "../Building.h"

class IndustrialBuilding : public Building
{

private:
	int numberOfEmployees;
	int satisfactionScore;

public:

	IndustrialBuilding(int id, int numberOfEmployees,string variant, int satisfactionScore, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);
	
	int getNumberOfEmployees();

	void setNumberOfEmployees(int numberOfEmployees);

	int getSatisfactionScore();

	void setSatisfactionScore(int satisfactionScore);
};

#endif
