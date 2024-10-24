#include "WaterSupply.h"

int Building_State::WaterSupply::getWaterSupply() {
	return this->waterSupply;
}

void Building_State::WaterSupply::setWaterSupply(int waterSupply) {
	this->waterSupply = waterSupply;
}
