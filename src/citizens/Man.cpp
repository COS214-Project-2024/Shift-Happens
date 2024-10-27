#include "Man.h"

void Man::setType(std::string type) {
	this->Type = type;
}

void Man::setGender(std::string gender) {
	this->Gender = gender;
}

void Man::setStatus(bool status){
	this->setEmployment(status);
}

void Man::setEmployment(bool status) {
	this->Employment = status;
}

std::string Man::getGender(){
	return Gender;
}

bool Man::getStatus(){
	return Employment;
}

std::string Man::getType(){
	return Type;
}

void Man::setEmployment(bool status) {
	this->Employment = status;
}
