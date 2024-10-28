#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H
#include "Building.h"
#include "Materials.h"
#include <vector>

using namespace std;
	class CommercialBuilding : public Building {

	private:
		int incomePerHour;
		int satisfactionScore;
		int numberOfEmployees;
		vector<Materials*> soldMaterials; //this is how the shop keeps track of the materials it has sold
	public:
		
		CommercialBuilding(int id, int incomePerHour,string variant, int satisfactionScore, int numberOfEmployees, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);
		
		int getIncomePerHour();

		void setIncomePerHour(int incomePerHour);

		int getSatisfactionScore();

		void setSatisfactionScore(int satisfactionScore);

		int getNumberOfEmployees();

		void setNumberOfEmployees(int numberOfEmployees);
	};


#endif
