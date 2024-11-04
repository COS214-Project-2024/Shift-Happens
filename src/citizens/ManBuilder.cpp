#include "ManBuilder.h"

ManBuilder::ManBuilder(){
	this->man = make_shared<Man>();
}

void ManBuilder::addGender() {
	man->setGender("Male");
}

void ManBuilder::addType() {
	man->setType("Man");
}

void ManBuilder::addStatus(std::string answer) {

	if(answer == "Yes" || answer == "yes"){
		man->setEmployment(true);
	} else if(answer == "No" || answer == "no"){
		man->setEmployment(false);
	} else {
		bool done = false;
		while (done != true)
		{
			std::cout << "Input did not match the expected Yes or No input. Try again." << std::endl;
			std::cout << "Is the Man employed? (Yes/No)" << std::endl;
			std::cin >> answer;
			if(answer == "Yes" || answer == "yes"){
				man->setEmployment(true);
				done = true;
			} else if(answer == "No" || answer == "no"){
				man->setEmployment(false);
				done = false;
			}
		}
		
	}	
}

shared_ptr<Citizen> ManBuilder::getCitizen() {
	return this->man;
}
