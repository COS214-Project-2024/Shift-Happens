#include "WomanBuilder.h"
#include <iostream>

void WomanBuilder::addGender() {
	Woman->setGender("Female");
}

void WomanBuilder::addType() {
	Woman->setType("Woman");
}

void WomanBuilder::addStatus() {
	std::string answer ;
	std::cout << "Is the Woman employed? (Yes/No)" << std::endl;
	std::cin >> answer;
	if(answer == "Yes" || answer == "yes"){
		Woman->setEmployment(true);
	} else if(answer == "No" || answer == "no"){
		Woman->setEmployment(false);
	} else {
		bool done = false;
		while (done != true)
		{
			std::cout << "Input did not match the expected Yes or No input. Try again." << std::endl;
			std::cout << "Is the Woman employed? (Yes/No)" << std::endl;
			std::cin >> answer;
			if(answer == "Yes" || answer == "yes"){
				Woman->setEmployment(true);
				done = true;
			} else if(answer == "No" || answer == "no"){
				Woman->setEmployment(false);
				done = false;
			}
		}
		
	}
}

shared_ptr<Citizen> WomanBuilder::getCitizen() {
	return Woman;
}
