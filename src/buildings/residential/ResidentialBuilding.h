#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "../Building.h"
class ResidentialBuilding : public Building
{

private:
	int capacity;
	int satisfactionScore;
	int incomePerHour;

public:
	int getCapacity();

	void setCapacity(int capacity);

	int getSatisfactionScore();

	void setSatisfactionScore(int satisfactionScore);

	int getIncomePerHour();

	void setIncomePerHour(int incomePerHour);
};

#endif
