#include "ResidentialBuilding.h"
#include <iostream>

using namespace std;

ResidentialBuilding::ResidentialBuilding(int id, int capacity, string variant, int satisfactionScore, int incomePerHour, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand, Statistics* statistics)
	: Building(id, 1, 1, -1, -1, variant, "Residential", constructionPrice, wasteProduced, sewageProduced, electricityDemand, waterDemand, statistics)
{
	this->capacity = capacity;
	this->satisfactionScore = satisfactionScore;
	this->incomePerHour = incomePerHour;
}

// ResidentialBuilding::ResidentialBuilding(int id, int capacity, std::string variant, int satisfactionScore, int incomePerHour, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand)
//     : Building(id, 1, 1, -1, -1, variant, "Residential", constructionPrice, wasteProduced, sewageProduced, electricityDemand, waterDemand), capacity(capacity), satisfactionScore(satisfactionScore), incomePerHour(incomePerHour) {}

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

ResidentialBuilding::~ResidentialBuilding() {
}

void ResidentialBuilding::print() const {
    cout << "ResidentialBuilding Attributes:" << endl;
    cout << "Capacity: " << capacity << ", Satisfaction Score: " << satisfactionScore << endl;
    cout << "Income per Hour: " << incomePerHour << endl;
    Building::print(); 
}