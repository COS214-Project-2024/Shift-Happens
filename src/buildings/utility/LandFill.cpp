#include "LandFill.h"

int Building_State::LandFill::getWasteRemovalRate() {
	return this->wasteRemovalRate;
}

void Building_State::LandFill::setWasteRemovalRate(int wasteRemovalRate) {
	this->wasteRemovalRate = wasteRemovalRate;
}
