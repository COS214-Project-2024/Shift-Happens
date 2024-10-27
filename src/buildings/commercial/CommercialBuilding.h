#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "../Building.h"
class CommercialBuilding : public Building {

	private:
		int incomePerHour;
		int satisfactionScore;
		int numberOfEmployees;

	public:
		
		CommercialBuilding(int id, string name, int incomePerHour,string variant, int satisfactionScore, int numberOfEmployees, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);
		
		int getIncomePerHour();

		void setIncomePerHour(int incomePerHour);

		int getSatisfactionScore();

		void setSatisfactionScore(int satisfactionScore);

		void getNumberOfEmployees();

		void setNumberOfEmployees(int numberOfEmployees);
	};


#endif
