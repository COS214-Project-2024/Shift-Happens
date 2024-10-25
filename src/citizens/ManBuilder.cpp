#include "ManBuilder.h"

void Building_State::ManBuilder::addGender() {
	Man->setGender("Male");
}

void Building_State::ManBuilder::addType() {
	Man->setType("Man");
}

void Building_State::ManBuilder::addStatus() {
	std::string answer ;
	std::cout << "Is the Man employed? (Yes/No)" << std::endl;
	std::cin >> answer;
	if(answer == "Yes" || answer == "yes"){
		Man->setEmployment(true);
	} else if(answer == "No" || answer == "no"){
		Man->setEmployment(false);
	} else {
		bool done = false;
		while (done != true)
		{
			std::cout << "Input did not match the expected Yes or No input. Try again." << std::endl;
			std::cout << "Is the Man employed? (Yes/No)" << std::endl;
			std::cin >> answer;
			if(answer == "Yes" || answer == "yes"){
				Man->setEmployment(true);
				done = true;
			} else if(answer == "No" || answer == "no"){
				Man->setEmployment(false);
				done = false;
			}
		}
		
	}	
}

Building_State::Citizen* Building_State::ManBuilder::getCitizen() {
	return Man;
}
