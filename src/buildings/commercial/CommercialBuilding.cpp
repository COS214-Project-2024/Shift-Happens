#include "CommercialBuilding.h"

CommercialBuilding::CommercialBuilding(int id, int incomePerHour,string variant, int satisfactionScore, int numberOfEmployees, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand, Statistics* statistics) 
: 	Building(id,1, 1, -1, -1, variant, "Commercial",constructionPrice,wasteProduced,sewageProduced,electricityDemand,waterDemand, statistics)
{
	this->incomePerHour = incomePerHour;
	this->satisfactionScore = satisfactionScore;
	this->numberOfEmployees = numberOfEmployees;
}
int CommercialBuilding::getIncomePerHour() {
	return this->incomePerHour;
}

void CommercialBuilding::setIncomePerHour(int incomePerHour) {
	this->incomePerHour = incomePerHour;
}

int CommercialBuilding::getSatisfactionScore() {
	return this->satisfactionScore;
}

void CommercialBuilding::setSatisfactionScore(int satisfactionScore) {
	this->satisfactionScore = satisfactionScore;
}

int CommercialBuilding::getNumberOfEmployees() {
	return this->numberOfEmployees;
}

void CommercialBuilding::setNumberOfEmployees(int numberOfEmployees) {
	this->numberOfEmployees = numberOfEmployees;
}
