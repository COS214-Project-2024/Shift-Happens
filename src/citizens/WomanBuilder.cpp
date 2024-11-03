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
	std::cout << "Is the Woman employed? (Yes/No)" << std::endl;
	std::cin >> answer;
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
