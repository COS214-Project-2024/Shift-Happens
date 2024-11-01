#include "Girl.h"

#include <iostream>

void Girl::setType(std::string type) {
	this->Type = type;
}

void Girl::setGender(std::string gender) {
	this->Gender = gender;
}

void Girl::setStatus(bool status){
	this->setSchool(status);
}

void Girl::setSchool(bool status) {
	this->School = status;
}

std::string Girl::getGender(){
	return Gender;
}

bool Girl::getStatus(){
	return School;
}

std::string Girl::getType(){
	return Type;
}
