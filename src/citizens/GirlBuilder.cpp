#include "GirlBuilder.h"

#include <iostream>

void Building_State::GirlBuilder::addGender() {
	Girl->setGender("Female");
}

void Building_State::GirlBuilder::addType() {
	Girl->setType("Girl");
}

void Building_State::GirlBuilder::addStatus() {
	std::string answer ;
	std::cout << "Is the girl in school? (Yes/No)" << std::endl;
	std::cin >> answer;
	if(answer == "Yes" || answer == "yes"){
		Girl->setSchool(true);
	} else if(answer == "No" || answer == "no"){
		Girl->setSchool(false);
	} else {
		bool done = false;
		while (done != true)
		{
			std::cout << "Input did not match the expected Yes or No input. Try again." << std::endl;
			std::cout << "Is the girl in school? (Yes/No)" << std::endl;
			std::cin >> answer;
			if(answer == "Yes" || answer == "yes"){
				Girl->setSchool(true);
				done = true;
			} else if(answer == "No" || answer == "no"){
				Girl->setSchool(false);
				done = false;
			}
		}
		
	}
}

Building_State::Citizen* Building_State::GirlBuilder::getCitizen() {
	return Girl;
}
