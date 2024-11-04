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
		boy->setSchool(true);
	} else if(answer == "No" || answer == "no"){
		boy->setSchool(false);
	} else {
		bool done = false;
		while (done != true)
		{
			std::cout << "Input did not match the expected Yes or No input. Try again." << std::endl;
			std::cout << "Is the boy in school? (Yes/No)" << std::endl;
			std::cin >> answer;
			if(answer == "Yes" || answer == "yes"){
				boy->setSchool(true);
				done = true;
			} else if(answer == "No" || answer == "no"){
				boy->setSchool(false);
				done = false;
			}
		}
		
	}
}

std::shared_ptr<Citizen> BoyBuilder::getCitizen() {
	return this->boy;
}
