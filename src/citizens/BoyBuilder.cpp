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

void BoyBuilder::addStatus() {
	std::string answer  = "";

	if(CreatorCounter == 0){
		answer = "Yes";
		CreatorCounter++;
	} else if(CreatorCounter == 1){
		answer = "No";
		CreatorCounter++;
	} else if(CreatorCounter == 2){
		answer == "Yes";
		CreatorCounter++;
	} else if(CreatorCounter == 3){
		answer = "Yes";
		CreatorCounter++;
	} else if(CreatorCounter == 4){
		answer = "No";
		CreatorCounter = 0;
	}

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
