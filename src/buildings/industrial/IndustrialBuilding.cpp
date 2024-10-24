#include "IndustrialBuilding.h"

int Building_State::IndustrialBuilding::getNumberOfEmployees() {
	return this->numberOfEmployees;
}

void Building_State::IndustrialBuilding::setNumberOfEmployees(int numberOfEmployees) {
	this->numberOfEmployees = numberOfEmployees;
}

int Building_State::IndustrialBuilding::getSatisfactionScore() {
	return this->satisfactionScore;
}

void Building_State::IndustrialBuilding::setSatisfactionScore(int satisfactionScore) {
	this->satisfactionScore = satisfactionScore;
}
