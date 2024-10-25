#include "Girl.h"

#include <iostream>

void Building_State::Girl::setType(std::string type) {
	this->Type = type;
}

void Building_State::Girl::setGender(std::string gender) {
	this->Gender = gender;
}

void Building_State::Girl::setSchool(bool status) {
	this->School = status;
}
