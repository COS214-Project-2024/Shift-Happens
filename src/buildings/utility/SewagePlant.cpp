#include "SewagePlant.h"

int Building_State::SewagePlant::getSewageRemovalRate() {
	return this->sewageRemovalRate;
}

void Building_State::SewagePlant::setSewageRemovalRate(int sewageRemovalRate) {
	this->sewageRemovalRate = sewageRemovalRate;
}
