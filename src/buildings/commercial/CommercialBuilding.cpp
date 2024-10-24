#include "CommercialBuilding.h"

int Building_State::CommercialBuilding::getIncomePerHour() {
	return this->incomePerHour;
}

void Building_State::CommercialBuilding::setIncomePerHour(int incomePerHour) {
	this->incomePerHour = incomePerHour;
}

int Building_State::CommercialBuilding::getSatisfactionScore() {
	return this->satisfactionScore;
}

void Building_State::CommercialBuilding::setSatisfactionScore(int satisfactionScore) {
	this->satisfactionScore = satisfactionScore;
}

void Building_State::CommercialBuilding::getNumberOfEmployees() {
	// TODO - implement CommercialBuilding::getNumberOfEmployees
	throw "Not yet implemented";
}

void Building_State::CommercialBuilding::setNumberOfEmployees(int numberOfEmployees) {
	this->numberOfEmployees = numberOfEmployees;
}
