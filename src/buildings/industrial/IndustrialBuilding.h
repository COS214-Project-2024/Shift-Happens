#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include "../Building.h"

class IndustrialBuilding : public Building
{

private:
	int numberOfEmployees;
	int satisfactionScore;

public:
	int getNumberOfEmployees();

	void setNumberOfEmployees(int numberOfEmployees);

	int getSatisfactionScore();

	void setSatisfactionScore(int satisfactionScore);
};

#endif
