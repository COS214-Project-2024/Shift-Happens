#include "CommercialBuilding.h"

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
