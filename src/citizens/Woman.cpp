#include "Woman.h"

void Woman::setType(std::string type) {
	this->Type = type;
}

void Woman::setGender(std::string gender) {
	this->Gender = gender;
}

void Woman::setStatus(bool status){
	this->setEmployment(status);
}

void Woman::setEmployment(bool status) {
	this->Employment = status;
}

std::string Woman::getGender(){
	return Gender;
}

bool Woman::getStatus(){
	return Employment;
}

std::string Woman::getType(){
	return Type;
}

std::string Woman::getDescription() const {
    return "Woman Citizen";
}
