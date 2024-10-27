#include "ResidentialBuilding.h"

int ResidentialBuilding::getCapacity() {
	return this->capacity;
}

void ResidentialBuilding::setCapacity(int capacity) {
	this->capacity = capacity;
}

int ResidentialBuilding::getSatisfactionScore() {
	return this->satisfactionScore;
}

void ResidentialBuilding::setSatisfactionScore(int satisfactionScore) {
	this->satisfactionScore = satisfactionScore;
}

int ResidentialBuilding::getIncomePerHour() {
	return this->incomePerHour;
}

void ResidentialBuilding::setIncomePerHour(int incomePerHour) {
	this->incomePerHour = incomePerHour;
}
