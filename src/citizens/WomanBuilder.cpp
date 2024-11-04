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

void WomanBuilder::addStatus() {
	std::string answer = "" ;
	
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
