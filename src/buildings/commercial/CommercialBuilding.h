#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "../Building.h"
class CommercialBuilding : public Building {

	private:
		int incomePerHour;
		int satisfactionScore;
		int numberOfEmployees;

	public:
		int getIncomePerHour();

		void setIncomePerHour(int incomePerHour);

		int getSatisfactionScore();

		void setSatisfactionScore(int satisfactionScore);

		void getNumberOfEmployees();

		void setNumberOfEmployees(int numberOfEmployees);
	};


#endif
