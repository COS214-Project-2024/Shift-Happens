#include "Man.h"

void Building_State::Man::setType(std::string type) {
	this->Type = type;
}

void Building_State::Man::setGender(std::string gender) {
	this->Gender = gender;
}

void Building_State::Man::setEmployment(bool status) {
	this->Employment = status;
}
