#include "IndustrialBuilding.h"

int IndustrialBuilding::getNumberOfEmployees() {
	return this->numberOfEmployees;
}

void IndustrialBuilding::setNumberOfEmployees(int numberOfEmployees) {
	this->numberOfEmployees = numberOfEmployees;
}

int IndustrialBuilding::getSatisfactionScore() {
	return this->satisfactionScore;
}

void IndustrialBuilding::setSatisfactionScore(int satisfactionScore) {
	this->satisfactionScore = satisfactionScore;
}
