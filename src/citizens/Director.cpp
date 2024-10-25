#include "Director.h"

#include "ManBuilder.h"
#include "WomanBuilder.h"
#include "BoyBuilder.h"
#include "GirlBuilder.h"

#include <iostream>
void Director::construct() {
	std::string answer;
	std::cout << "Would you like to create a Man,Woman,Boy or Girl. Enter you choice below: " << std::endl;
	std::cin >> answer;

	if(answer == "Man" || answer == "man"){
		Builder = new ManBuilder;
		Builder->addGender();
		Builder->addStatus();
		Builder->addType();	
	} else if(answer == "Woman" || answer == "woman"){
		Builder = new WomanBuilder;
		Builder->addGender();
		Builder->addStatus();
		Builder->addType();	
	} else if(answer == "Boy" || answer == "Boy"){
		Builder = new BoyBuilder;
		Builder->addGender();
		Builder->addStatus();
		Builder->addType();
	} else if(answer == "Girl" || answer == "girl"){
		Builder = new GirlBuilder;
		Builder->addGender();
		Builder->addStatus();
		Builder->addType();
	} else {
		bool done = false;
		while (done != true)
		{
			std::cout << "Input did not match the expected Man,Woman,Boy or Girl input. Try again." << std::endl;
			std::cout << "Would you like to create a Man,Woman,Boy or Girl. Enter you choice below: " << std::endl;
			std::cin >> answer;

			if(answer == "Man" || answer == "man"){
				Builder = new ManBuilder;
				Builder->addGender();
				Builder->addStatus();
				Builder->addType();	
				done = true;
			} else if(answer == "Woman" || answer == "woman"){
				Builder = new WomanBuilder;
				Builder->addGender();
				Builder->addStatus();
				Builder->addType();	
				done = true;
			} else if(answer == "Boy" || answer == "Boy"){
				Builder = new BoyBuilder;
				Builder->addGender();
				Builder->addStatus();
				Builder->addType();
				done = true;
			} else if(answer == "Girl" || answer == "girl"){
				Builder = new GirlBuilder;
				Builder->addGender();
				Builder->addStatus();
				Builder->addType();
				done = true;
			}	
		}
	}
}

