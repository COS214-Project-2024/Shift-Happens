#ifndef STATISTICS_H
#define STATISTICS_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "map/Map.h"
#include "map/Transportation/TransportationStrategy.h"
#include "Government/Government.h"
#include "Government/StandardTax.h"
#include "Government/LowTax.h"
#include "Government/HighTax.h"

using namespace std;
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

	int uncollectedBusinessTax;
	int uncollectedPersonalTax;

	std::shared_ptr<Government> government;

	shared_ptr<TransportationStrategy> strategy;	//for transportation

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


	//Government
	void changeBusinessTax(double rate, string type);
	void changePersonalTax(double rate, string type);
	void collectBusinessTax();
	void collectPersonalTax();
	shared_ptr<Government> getGovernment();

	string implementPolicy(string policy);
	vector<string> getCurrentPolicies();
	void changeBudget(string type, string change);

	int getUncollectedTax(string type);

	vector<vector<string>> getImplementedPolicies();
	vector<string> getAvailablePolicies();

	//transportation functions
	void setStrategy(shared_ptr<TransportationStrategy> strat);
	double getCost(int distance);
    double getDuration(int distance);
    void displayOption(int distance);


};

#endif

// add a statistics pointer in every building and citizen object