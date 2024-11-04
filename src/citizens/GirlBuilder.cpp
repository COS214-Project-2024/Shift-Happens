#include "GirlBuilder.h"

#include <iostream>

GirlBuilder::GirlBuilder(){
	this->girl = make_shared<Girl>();
}

void GirlBuilder::addGender() {
	girl->setGender("Female");
}

void GirlBuilder::addType() {
	girl->setType("Girl");
}

void GirlBuilder::addStatus(std::string answer) {
	if(answer == "Yes" || answer == "yes"){
		girl->setSchool(true);
	} else if(answer == "No" || answer == "no"){
		girl->setSchool(false);
	} else {
		bool done = false;
		while (done != true)
		{
			std::cout << "Input did not match the expected Yes or No input. Try again." << std::endl;
			std::cout << "Is the girl in school? (Yes/No)" << std::endl;
			std::cin >> answer;
			if(answer == "Yes" || answer == "yes"){
				girl->setSchool(true);
				done = true;
			} else if(answer == "No" || answer == "no"){
				girl->setSchool(false);
				done = false;
			}
		}
		
	}
}

shared_ptr<Citizen> GirlBuilder::getCitizen() {
	return this->girl;
}
