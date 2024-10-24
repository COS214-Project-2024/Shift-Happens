#include "LandMark.h"

int Building_State::LandMark::getSatisfactionScore() {
	return this->satisfactionScore;
}

void Building_State::LandMark::setSatisfactionScore(int satisfactionScore) {
	this->satisfactionScore = satisfactionScore;
}
