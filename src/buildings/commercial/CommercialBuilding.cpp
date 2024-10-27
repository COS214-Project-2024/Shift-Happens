#include "CommercialBuilding.h"

CommercialBuilding::CommercialBuilding(int id, string name, int incomePerHour,string variant, int satisfactionScore, int numberOfEmployees, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand) 
: 	Building(id,1, 1, -1, -1, variant, "Commercial",constructionPrice,wasteProduced,sewageProduced,electricityDemand,waterDemand)
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

void CommercialBuilding::getNumberOfEmployees() {
	// TODO - implement CommercialBuilding::getNumberOfEmployees
	throw "Not yet implemented";
}

void CommercialBuilding::setNumberOfEmployees(int numberOfEmployees) {
	this->numberOfEmployees = numberOfEmployees;
}
