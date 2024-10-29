#include "LandMark.h"

LandMark::LandMark(int id,string variant, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand, int satisfactionScore)
:Building(id,1,1,-1,-1,variant,"LandMark",constructionPrice,wasteProduced,sewageProduced,electricityDemand,waterDemand)
{
	this->variant = variant;
	this->satisfactionScore = satisfactionScore;
}

int LandMark::getSatisfactionScore() {
	return this->satisfactionScore;
}

void LandMark::setSatisfactionScore(int satisfactionScore) {
	this->satisfactionScore = satisfactionScore;
}

void LandMark::render() {
	throw "LandMark::render() not yet implemented";
}

bool LandMark::add(MapComponent *component) {
	throw "LandMark::add() not yet implemented";
}

bool LandMark::remove(MapComponent *component) {
	throw "LandMark::remove() not yet implemented";
}

void LandMark::getComponent(int id) {
	throw "LandMark::getComponent() not yet implemented";
}

LandMark::~LandMark() {
	
}