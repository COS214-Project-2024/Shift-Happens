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

	ResidentialBuilding(int id, int capacity, string variant, int satisfactionScore, int incomePerHour, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand, Statistics* statistics);

	int getCapacity();

	void setCapacity(int capacity);

	int getSatisfactionScore();

	void setSatisfactionScore(int satisfactionScore);

	int getIncomePerHour();

	void setIncomePerHour(int incomePerHour);

	~ResidentialBuilding();

	//print function
	virtual void print() const override;
};

#endif
