#ifndef STATISTICS_H
#define STATISTICS_H
#include <iostream>
#include <vector>
#include <string>
#include "map/Map.h"

class Statistics
{
private:
	Map &map;
	int money;
	int income;
	int population;
	int maxPopulation;
	int employment;
	int satisfaction;
	int waterSupply;
	int powerSupply;
	int sewageCapacity;
	int wasteCapacity;

	int waterConsumption;
	int powerConsumption;
	int sewageProduction;
	int wasteProduction;



public:
	Statistics();

	void updateStats();

	//getters
	int getMoney();
	int getIncome();
	int getPopulation();
	int getMaxPopulation();
	int getEmployment();
	int getSatisfaction();
	int getWaterSupply();
	int getPowerSupply();
	int getSewageCapacity();
	int getWasteCapacity();
	int getWaterConsumption();
	int getPowerConsumption();
	int getSewageProduction();
	int getWasteProduction();

	//setters
	void setMoney(int m);
	void setIncome(int i);
	void setPopulation(int p);
	void setMaxPopulation(int mp);
	void setEmployment(int e);
	void setSatisfaction(int s);
	void setWaterSupply(int ws);
	void setPowerSupply(int ps);
	void setSewageCapacity(int sc);
	void setWasteCapacity(int wc);
	void setWaterConsumption(int wc);
	void setPowerConsumption(int pc);
	void setSewageProduction(int sp);
	void setWasteProduction(int wp);

	void increaseBusinessTax();
	void decreaseBusinessTax();
	void increasePersonalTax();
	void decreasePersonalTax();
	void collectBusinessTax();
	void collectPersonalTax();
	


};

#endif

// add a statistics pointer in every building and citizen object