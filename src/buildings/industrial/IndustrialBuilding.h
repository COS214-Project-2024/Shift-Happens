#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H
#include "Building.h"
#include "Materials.h"
#include <vector>

using namespace std;
	class IndustrialBuilding : Building {

	private:
		int numberOfEmployees;
		int satisfactionScore;
		vector<Materials*> availableMaterials; //THIS WOULD STORE THE materials in the warehouse that were produced by the factory

public:

	IndustrialBuilding(int id, int numberOfEmployees,string variant, int satisfactionScore, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);
	
	int getNumberOfEmployees();

	void setNumberOfEmployees(int numberOfEmployees);

	int getSatisfactionScore();

	void setSatisfactionScore(int satisfactionScore);
};

#endif
