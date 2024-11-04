#include "WomanBuilder.h"
#include <iostream>

WomanBuilder::WomanBuilder(){
	this->woman = make_shared<Woman>();
}

void WomanBuilder::addGender() {
	woman->setGender("Female");
}

void WomanBuilder::addType() {
	woman->setType("Woman");
}

void WomanBuilder::addStatus(std::string answer) {
	
	if(answer == "Yes" || answer == "yes"){
		woman->setEmployment(true);
	} else if(answer == "No" || answer == "no"){
		woman->setEmployment(false);
	} else {
		throw "womanBuilder::addStatus() invalid input";
		
	}
}

shared_ptr<Citizen> WomanBuilder::getCitizen() {
	return this->woman;
}
