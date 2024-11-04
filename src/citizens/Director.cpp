#include "Director.h"

#include "ManBuilder.h"
#include "WomanBuilder.h"
#include "BoyBuilder.h"
#include "GirlBuilder.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

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
	srand(static_cast<unsigned int>(time(0)));

  // Generate a random value between 1 and 5
  int randomValue = rand() % 5 + 1; 
  if (randomValue <= 3) { 
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

