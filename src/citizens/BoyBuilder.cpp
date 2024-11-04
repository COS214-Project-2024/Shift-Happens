#include "BoyBuilder.h"

#include <iostream>

BoyBuilder::BoyBuilder(){
	this->boy = make_shared<Boy>();
}

void BoyBuilder::addGender() {
	boy->setGender("Male");
}

void BoyBuilder::addType() {
	boy->setType("Boy");
}

void BoyBuilder::addStatus(std::string answer) {

	if(answer == "Yes" || answer == "yes"){
		boy->setSchool(true);
	} else if(answer == "No" || answer == "no"){
		boy->setSchool(false);
	} else {
		throw "BoyBuilder::addStatus() invalid input";
	}
}

std::shared_ptr<Citizen> BoyBuilder::getCitizen() {
	return this->boy;
}
