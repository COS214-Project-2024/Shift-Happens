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
	std::string answer ;
	
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
		bool done = false;
		while (done != true)
		{
			std::cout << "Input did not match the expected Yes or No input. Try again." << std::endl;
			std::cout << "Is the Woman employed? (Yes/No)" << std::endl;
			std::cin >> answer;
			if(answer == "Yes" || answer == "yes"){
				woman->setEmployment(true);
				done = true;
			} else if(answer == "No" || answer == "no"){
				woman->setEmployment(false);
				done = false;
			}
		}
		
	}
}

shared_ptr<Citizen> WomanBuilder::getCitizen() {
	return this->woman;
}
