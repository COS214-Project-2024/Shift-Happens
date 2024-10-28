#include "IndustrialBuilding.h"

IndustrialBuilding::IndustrialBuilding(int id, int numberOfEmployees,string variant, int satisfactionScore, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand)
: Building(id,1, 1, -1, -1, variant, "Industrial",constructionPrice,wasteProduced,sewageProduced,electricityDemand,waterDemand)
{
	this->numberOfEmployees = numberOfEmployees;
	this->satisfactionScore = satisfactionScore;
}

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
