#include "Boy.h"

#include <iostream>

void Boy::setType(std::string type) {
	this->Type = type;
}

void Boy::setGender(std::string gender) {
	this->Gender = gender;
}

void Boy::setStatus(bool status){
	this->setSchool(status);
}

void Boy::setSchool(bool status) {
	this->School = status;
}

std::string Boy::getGender(){
	return Gender;
}

bool Boy::getStatus(){
	return School;
}

std::string Boy::getType(){
	return Type;
}

std::string Boy::getDescription() const {
    return "Boy Citizen";
}


void Boy::setIncomeRate(double income){

}

double Boy::getIncome(){
	return 0;
}