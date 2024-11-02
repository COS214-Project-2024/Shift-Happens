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

std::string Man::getDescription() const {
    return "Man Citizen";
}


double Man::getIncome(){
	return this->Income;
}

void Man::setIncomeRate(double income){
	this->Income = income;
}

double Man::getIncome(){
	return this->Income;
}