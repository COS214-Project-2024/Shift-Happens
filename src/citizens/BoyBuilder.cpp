#include "BoyBuilder.h"

#include <iostream>

void BoyBuilder::addGender() {
	Boy->setGender("Male");
}

void BoyBuilder::addType() {
	Boy->setType("Boy");
}

void BoyBuilder::addStatus() {
	std::string answer ;
	std::cout << "Is the boy in school? (Yes/No)" << std::endl;
	std::cin >> answer;
	if(answer == "Yes" || answer == "yes"){
		Boy->setSchool(true);
	} else if(answer == "No" || answer == "no"){
		Boy->setSchool(false);
	} else {
		bool done = false;
		while (done != true)
		{
			std::cout << "Input did not match the expected Yes or No input. Try again." << std::endl;
			std::cout << "Is the boy in school? (Yes/No)" << std::endl;
			std::cin >> answer;
			if(answer == "Yes" || answer == "yes"){
				Boy->setSchool(true);
				done = true;
			} else if(answer == "No" || answer == "no"){
				Boy->setSchool(false);
				done = false;
			}
		}
		
	}
}

Citizen* BoyBuilder::getCitizen() {
	return Boy;
}
