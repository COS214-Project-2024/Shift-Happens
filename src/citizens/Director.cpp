#include "Director.h"

#include "ManBuilder.h"
#include "WomanBuilder.h"
#include "BoyBuilder.h"
#include "GirlBuilder.h"

#include <iostream>
#include <cstdlib>

Director::Director(std::shared_ptr<CitizenBuilder> Builder){
	this->Builder = Builder;
}

void Director::construct() {
	// std::string answer ;
	
	// if(CreatorCounter == 0){
	// 	answer = "Yes";
	// 	CreatorCounter++;
	// } else if(CreatorCounter == 1){
	// 	answer = "No";
	// 	CreatorCounter++;
	// } else if(CreatorCounter == 2){
	// 	answer = "Yes";
	// 	CreatorCounter++;
	// } else if(CreatorCounter == 3){
	// 	answer = "Yes";
	// 	CreatorCounter++;
	// } else if(CreatorCounter == 4){
	// 	answer = "No";
	// 	CreatorCounter = 0;
	// }

	std::string answer;

  int randomValue = rand() % 21; 
	//cout << "Random" << randomValue << endl;

	if(randomValue <= 13){
		answer = "Yes";
	} else {
		answer = "No";
	}
	Builder->addGender();
	Builder->addStatus(answer);
	Builder->addType();	
	// std::string answer;
	// std::cout << "Would you like to create a Man,Woman,Boy or Girl. Enter you choice below: " << std::endl;
	// std::cin >> answer;

	// if(answer == "Man" || answer == "man"){
	// 	Builder = std::make_shared<ManBuilder>();
	// 	Builder->addGender();
	// 	Builder->addStatus();
	// 	Builder->addType();	
	// } else if(answer == "Woman" || answer == "woman"){
	// 	Builder = std::make_shared<WomanBuilder>() ;
	// 	Builder->addGender();
	// 	Builder->addStatus();
	// 	Builder->addType();	
	// } else if(answer == "Boy" || answer == "Boy"){
	// 	Builder = std::make_shared<BoyBuilder>();
	// 	Builder->addGender();
	// 	Builder->addStatus();
	// 	Builder->addType();
	// } else if(answer == "Girl" || answer == "girl"){
	// 	Builder = std::make_shared<GirlBuilder>();
	// 	Builder->addGender();
	// 	Builder->addStatus();
	// 	Builder->addType();
	// } else {
	// 	bool done = false;
	// 	while (done != true)
	// 	{
	// 		std::cout << "Input did not match the expected Man,Woman,Boy or Girl input. Try again." << std::endl;
	// 		std::cout << "Would you like to create a Man,Woman,Boy or Girl. Enter you choice below: " << std::endl;
	// 		std::cin >> answer;

	// 		if(answer == "Man" || answer == "man"){
	// 			Builder = std::make_shared<ManBuilder>();
	// 			Builder->addGender();
	// 			Builder->addStatus();
	// 			Builder->addType();	
	// 			done = true;
	// 		} else if(answer == "Woman" || answer == "woman"){
	// 			Builder = std::make_shared<WomanBuilder>();
	// 			Builder->addGender();
	// 			Builder->addStatus();
	// 			Builder->addType();	
	// 			done = true;
	// 		} else if(answer == "Boy" || answer == "Boy"){
	// 			Builder = std::make_shared<BoyBuilder>();
	// 			Builder->addGender();
	// 			Builder->addStatus();
	// 			Builder->addType();
	// 			done = true;
	// 		} else if(answer == "Girl" || answer == "girl"){
	// 			Builder = std::make_shared<GirlBuilder>();
	// 			Builder->addGender();
	// 			Builder->addStatus();
	// 			Builder->addType();
	// 			done = true;
	// 		}	
	// 	}
	// }
}

std::shared_ptr<CitizenBuilder> Director::getBuilder() const {
	return Builder;
}

