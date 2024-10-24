#include "ResidentialBuilding.h"

int Building_State::ResidentialBuilding::getCapacity() {
	return this->capacity;
}

void Building_State::ResidentialBuilding::setCapacity(int capacity) {
	this->capacity = capacity;
}

int Building_State::ResidentialBuilding::getSatisfactionScore() {
	return this->satisfactionScore;
}

void Building_State::ResidentialBuilding::setSatisfactionScore(int satisfactionScore) {
	this->satisfactionScore = satisfactionScore;
}

int Building_State::ResidentialBuilding::getIncomePerHour() {
	return this->incomePerHour;
}

void Building_State::ResidentialBuilding::setIncomePerHour(int incomePerHour) {
	this->incomePerHour = incomePerHour;
}
