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
		int getIncomePerHour();

		void setIncomePerHour(int incomePerHour);

		int getSatisfactionScore();

		void setSatisfactionScore(int satisfactionScore);

		void getNumberOfEmployees();

		void setNumberOfEmployees(int numberOfEmployees);
	};


#endif
